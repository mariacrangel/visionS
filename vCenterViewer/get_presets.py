import sys
from onvif import ONVIFCamera

ip = sys.argv[1]
port = str(sys.argv[2])
user = sys.argv[3]
password = sys.argv[4]
wsdl_dir = sys.argv[5]

def getPresets():
	#mycam = ONVIFCamera('192.168.0.139',1018,'admin','8146dpr','/home/visionstudio/Desktop/wsdl')
	
	global mycam,media,ptz,media_profile,request,ptz_configuration_options
	mycam = ONVIFCamera(ip,port,user,password,wsdl_dir)
	media = mycam.create_media_service()

	media_profile = media.GetProfiles()[0]
	ptz = mycam.create_ptz_service()

	request = ptz.create_type('GetConfigurationOptions')
	request.ConfigurationToken = media_profile.PTZConfiguration._token
	
	ptz_configuration_options = ptz.GetConfigurationOptions(request)
	request = ptz.create_type('ContinuousMove')
	request.ProfileToken = media_profile._token
	ptz.Stop({'ProfileToken': media_profile._token})

	#ver presets
	ptzPresetsList = ptz.GetPresets(request)

	print len(ptzPresetsList)

	for preset in ptzPresetsList:
		print preset._token
		if preset.Name == '':
			print '-'
		else:
			print preset.Name
			
		


if __name__ == '__main__':
    getPresets()

