#!/bin/bash
apt update
apt install software-properties-common -y
add-apt-repository ppa:ubuntu-toolchain-r/test -y
apt update
DEBIAN_FRONTEND=noninteractive apt upgrade --allow-downgrades -y


apt-get install gcc-7 g++-7 git unzip mosquitto mosquitto-clients libmosquitto-dev libc6-dev libssl-dev libc-ares-dev nano -y


sudo update-alternatives \
 --install /usr/bin/gcc gcc /usr/bin/gcc-7 60 \
 --slave /usr/bin/gcc-ar gcc-ar /usr/bin/gcc-ar-7 \
 --slave /usr/bin/gcc-nm gcc-nm /usr/bin/gcc-nm-7 \
 --slave /usr/bin/gcc-ranlib gcc-ranlib /usr/bin/gcc-ranlib-7
 
update-alternatives --config gcc


systemctl enable mosquitto
systemctl start mosquitto


git clone https://github.com/unwireddevices/lora-mqtt.git
cd lora-mqtt
CC=gcc make
cp bin/mqtt /usr/local/bin/
chmod 755 /usr/local/bin/mqtt
mkdir /etc/lora-mqtt
cp dist/openwrt/files/mqtt.conf /etc/lora-mqtt/
sed -i s/ttyATH0/ttySAC1/ /etc/lora-mqtt/mqtt.conf
cp dist/init.d/mqtt.init /etc/init.d/mqtt
chmod 755 /etc/init.d/mqtt
cd ..


systemctl enable mqtt
systemctl start mqtt


