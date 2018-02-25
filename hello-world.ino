#include <ESP8266HTTPUpdateServer.h>
#include <ESP8266WebServer.h>
#include <DNSServer.h>
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266mDNS.h>
#include "WiFiManager.h"
#include <Adafruit_NeoPixel.h>
#include "html.h"

#define LED_DATA 13

//The pin for our "program" button, which does double duty as a simple method of user input.
#define BUTTON 0

//This is the format for the badge's hostname.  Change this if you want to make it easier to identify.
//The %06x part will be filled in with the ESP8266's unique ID.
const char* _host = "esp8266-%06x";


//The longest string size we can use for the hostname.
#define MAX_HOST_NAME_LEN 26

//Create the web server, port 80
ESP8266WebServer _server(80);
void on_homepage();

void setup() 
{
    Serial.begin(115200);
    Serial.println("setup()");
    String ap_name = get_ap_name();
    Serial.printf("WiFi SSID: %s", ap_name.c_str());

    WiFi.persistent(false);
    WiFi.softAP(ap_name.c_str());
    WiFi.mode(WIFI_AP);
  
    // Set server callback functions
    _server.on("/", on_homepage);    
    _server.begin();

    //Allows us to use the "program" (top) button in our program.
    pinMode(BUTTON, INPUT_PULLUP);
}

void loop()
{
    //NOTE: Here's where the code for the main program should start. 
    Serial.println("Main program loop begins...");
    
    _server.handleClient();
    
    Serial.println("Main program loop ends...");
}


void on_homepage() 
{
    String html = FPSTR(index_html);
    _server.send(200, "text/html", html);
}


char dec2hex(byte dec) 
{
    //Serial.println("dec2hex()");
    if(dec<10) return '0'+dec;
    else return 'A'+(dec-10);
}

// AP name is ESP_ following by 
// the last 6 bytes of MAC address
String get_ap_name() 
{
     Serial.println("get_ap_name()");
    static String ap_name = "";
    if(!ap_name.length()) 
    {
        byte mac[6];
        WiFi.macAddress(mac);
        ap_name = "ESP_";
        for(byte i=3;i<6;i++) 
        {
            ap_name += dec2hex((mac[i]>>4)&0x0F);
            ap_name += dec2hex(mac[i]&0x0F);
        }
    }
    return ap_name;
}