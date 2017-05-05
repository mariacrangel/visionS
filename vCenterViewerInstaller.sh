#!/bin/bash

sudo cp -R vCenterViewer /opt/
sudo chmod -R 777 /opt/vCenterViewer
sudo cp vcenter.desktop /usr/share/applications/

cd vCenterViewer
mongorestore

if [ -d ~/Desktop ]; then
	cd ~/Desktop
else
	cd ~/Escritorio
fi
	
sudo ln -s /opt/vCenterViewer/ ./vCenterViewer
