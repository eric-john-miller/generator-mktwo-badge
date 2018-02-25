# mktwo-hello-world
A simple mktwo-badge hello world app.

The mktwo-badge is something I picked up at Penguicon 2017. It is a ESP8266/WS2812 wifi-enabled badge with Arduino-compatible pin-outs.  
You can find out more about All Hands Active and the mktwo-badge [here](https://github.com/allhandsactive/mktwo-badge).  

This program is a very stripped down "Hello World" web page hosted on the badge. The ESP8266 web server has a default IP address of 192.168.4.1. The SSID is set to "ESP_" following by the last 6 bytes of MAC address.

You can use the Arduino IDE. It's not the most user friendly environment, but it's the least painful to setup. I use [Visual Studio Code](https://code.visualstudio.com/) with the [Arduino Extension](https://marketplace.visualstudio.com/items?itemName=vsciot-vscode.vscode-arduino). This still requires the Arduino IDE, and unfortunatly, at this time, the Arduino Extension does not work fully with the portable installation of the Arduino IDE. 

![Hello World](https://raw.githubusercontent.com/eric-john-miller/mktwo-hello-world/master/IMG_8124.PNG | width=100).

