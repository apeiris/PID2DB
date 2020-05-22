#include <Arduino.h>
#include <Print.h>
#include <Thing.h>
#include <WebThingAdapter.h>
#include <WiFi.h>

const char *ssid = "Peiris_Wifi";
const char *wifiPassword = "22051954";

IPAddress sqlIP(192, 168, 0, 12);

int loginCounter = 0;
WebThingAdapter *adapter;
String mac = WiFi.macAddress();

void setup()
{
  WiFi.mode(WIFI_STA);
  Serial.print("Connecting :\n ");
  WiFi.begin(ssid, wifiPassword);
  mac.replace(":", "");
  printf("Connected... mac=%s\n", mac.c_str());
}

void loop()
{
  // put your main code here, to run repeatedly:
}