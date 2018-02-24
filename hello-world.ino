#include <ESP8266HTTPUpdateServer.h>
#include <ESP8266WebServer.h>
#include <DNSServer.h>
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>
#include <ESP8266HTTPUpdateServer.h>
#include "WiFiManager.h"
#include <Adafruit_NeoPixel.h>

#define LED_DATA 13

//The pin for our "program" button, which does double duty as a simple method of user input.
#define BUTTON 0

//This is the format for the badge's hostname.  Change this if you want to make it easier to identify.
//The %06x part will be filled in with the ESP8266's unique ID.
const char* _host = "esp8266-%06x";

//Keep track of the initial bootup period. 
bool _bootup = true;

//The longest string size we can use for the hostname.
#define MAX_HOST_NAME_LEN 26

ESP8266WebServer _httpServer(80);
ESP8266HTTPUpdateServer _httpUpdater;

void setup() 
{
    Serial.begin(115200);
    Serial.println("setup()");

    //Allows us to use the "program" (top) button in our program.
    pinMode(BUTTON, INPUT_PULLUP);
}

void loop()
{
    //When the program first starts up, we must check if the user wishes to enter OTA upload mode.
    if(_bootup == true) 
    {
        if(digitalRead(BUTTON) == LOW) 
        {
            Serial.println("Reset access point settings!");
            WiFi.disconnect();
        }
    }
    //If we fall through to here, the program button isn't being held down at any point, and we will just run the normal code.
    //Never return to this code again, until the user resets the device.
    Serial.println("Skip access point reset...");
    _bootup = false;


    //NOTE: Here's where the code for the main program should start. 
    Serial.println("Main program loop begins...");
    
    Serial.println("Hello World!");
    
    Serial.println("Main program loop ends...");
    
}
