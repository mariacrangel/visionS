import sys
import time
from time import sleep
from onvif import ONVIFCamera
import paho.mqtt.client as mqtt
import pprint

#
# Usage:
# python ptz_management.py <IP> <PORT> <USER> <PASSSWORD> <WSDL DIR> <IP BROKER> <TOPIC>
#

ip = sys.argv[1]
port = str(sys.argv[2])
user = sys.argv[3]
password = sys.argv[4]
wsdl_dir = sys.argv[5]
mqtt_ip = sys.argv[6]
mqtt_topic = sys.argv[7]

XMAX = 1
XMIN = -1
YMAX = 1
YMIN = -1
stop_flag = False

def set_preset(ptz,preset_name):
	requestp = ptz.create_type('SetPreset')
	requestp.ProfileToken = media_profile._token
	requestp.PresetName = preset_name
	preset = ptz.SetPreset(requestp) 

def goto_preset(ptz,preset_token):
	requestg = ptz.create_type('GotoPreset')
	requestg.ProfileToken = media_profile._token
	requestg.PresetToken = preset_token
	ptz.GotoPreset(requestg)

def perform_move(ptz, request, timeout):
    ptz.ContinuousMove(request)
    sleep(timeout)
    ptz.Stop({'ProfileToken': request.ProfileToken})

def zoom_in(ptz, request, timeout, velocity):
	print 'zoom in...'
	request.Velocity.PanTilt._x = 0
	request.Velocity.PanTilt._y = 0
	request.Velocity.Zoom._x = velocity
	perform_move(ptz, request, timeout)

def zoom_out(ptz, request, timeout, velocity):
	print 'zoom out...'
	request.Velocity.PanTilt._x = 0
	request.Velocity.PanTilt._y = 0
	request.Velocity.Zoom._x = -(velocity)
	perform_move(ptz, request, timeout)

def move_up(ptz, request, timeout, velocity):
	print 'move up...'
	request.Velocity.Zoom._x = 0
	request.Velocity.PanTilt._x = 0
	request.Velocity.PanTilt._y = velocity
	perform_move(ptz, request, timeout)

def move_down(ptz, request, timeout, velocity):
	print 'move down...'
	request.Velocity.PanTilt._x = 0
	request.Velocity.Zoom._x = 0
	request.Velocity.PanTilt._y = -(velocity)
	perform_move(ptz, request, timeout)

def move_right(ptz, request, timeout, velocity):
	print 'move right...'
	request.Velocity.PanTilt._x = velocity
	request.Velocity.Zoom._x = 0
	request.Velocity.PanTilt._y = 0
	perform_move(ptz, request, timeout)

def move_left(ptz, request, timeout, velocity):
	print 'move left...'
	request.Velocity.Zoom._x = 0
	request.Velocity.PanTilt._x = -(velocity)
	request.Velocity.PanTilt._y = 0
	perform_move(ptz, request, timeout)

# The callback for when the client receives a CONNACK response from the server.
def on_connect(client, userdata, rc):
	print("Connected with result code "+str(rc))
	# Subscribing in on_connect() means that if we lose the connection and
	# reconnect then subscriptions will be renewed.
	client.subscribe(mqtt_topic)

# The callback for when a PUBLISH message is received from the server.
def on_message(client, userdata, msg):
	
	#
	# Received Message:
	# <ip> <port> <user> <password> <action: r/l/u/d/+/-/go/set/stop> <velocity> <timeout>
	#

	tour_active = False
	smsg = str(msg.payload)
	print(msg.topic+" "+str(msg.payload))
	smsg_s = smsg.split()
	print smsg.split()[0]
	if len(smsg_s) > 6 and smsg_s[0] == ip and smsg_s[1] == port and smsg_s[2] == user and smsg_s[3] == password:
		velocity = float(smsg_s[5])
		timeout = float(smsg_s[6])
		client.publish(mqtt_topic,"Received")

		print "velocity/timeout:"
		print velocity
		print timeout
		print "perform action.."
		if smsg_s[4] == "r":
			move_right(ptz, request, timeout, velocity)
		if smsg_s[4] == "set":
			set_preset(ptz, smsg_s[7])
		if smsg_s[4] == "go":
			goto_preset(ptz, smsg_s[7])
		if smsg_s[4] == "l":
			move_left(ptz, request, timeout, velocity)
		if smsg_s[4] == "u":
			move_up(ptz, request, timeout, velocity)
		if smsg_s[4] == "d":
			move_down(ptz, request, timeout, velocity)
		if smsg_s[4] == "+":
			zoom_in(ptz, request, timeout, velocity)
		if smsg_s[4] == "-":
			zoom_out(ptz, request, timeout, velocity)
		if smsg_s[4] == "stop":
			print "Terminar"
			stop_flag = True
			sys.exit(0)

def continuous_move():
	print 0
	#mycam = ONVIFCamera('192.168.0.139',1018,'admin','8146dpr','/home/visionstudio/Desktop/wsdl')
	
	global mycam,media,ptz,media_profile,request,ptz_configuration_options,tourlist
	mycam = ONVIFCamera(ip,port,user,password,wsdl_dir)

	# Create media service object
	media = mycam.create_media_service()

	# Get target profile
	media_profile = media.GetProfiles()[0]
	# Create ptz service object
	ptz = mycam.create_ptz_service()

	# Get PTZ configuration options for getting continuous move range
	request = ptz.create_type('GetConfigurationOptions')
	
	request.ConfigurationToken = media_profile.PTZConfiguration._token
	
	ptz_configuration_options = ptz.GetConfigurationOptions(request)
	
	request = ptz.create_type('ContinuousMove')
	request.ProfileToken = media_profile._token

	ptz.Stop({'ProfileToken': media_profile._token})

	# Get range of pan and tilt
	# NOTE: X and Y are velocity vector
	global XMAX, XMIN, YMAX, YMIN

	"""
	XMAX = ptz_configuration_options.Spaces.ContinuousPanTiltVelocitySpace[0].XRange.Max
	XMIN = ptz_configuration_options.Spaces.ContinuousPanTiltVelocitySpace[0].XRange.Min
	YMAX = ptz_configuration_options.Spaces.ContinuousPanTiltVelocitySpace[0].YRange.Max
	YMIN = ptz_configuration_options.Spaces.ContinuousPanTiltVelocitySpace[0].YRange.Min
	"""

	client = mqtt.Client("", True, None, mqtt.MQTTv31)
	client.on_connect = on_connect
	client.on_message = on_message
	client.connect(mqtt_ip, 1883)

	while (stop_flag == False): 
		client.loop()

if __name__ == '__main__':
    continuous_move()








