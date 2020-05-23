#include <Arduino.h>
#include <Print.h>
#include <Thing.h>
#include <WebThingAdapter.h>
#include <WiFi.h>
#include <MySQL_Connection.h>
#include <MySQL_Cursor.h>

const char *ssid = "Peiris_Wifi";
const char *wifiPassword = "22051954";

IPAddress sqlIP(192, 168, 0, 12);
int loginCounter = 0;
WebThingAdapter *adapter;
String mac = WiFi.macAddress();
char sqlUser[] = "TONY";
char sqlPassword[] = "2205";
char insert_device[] = "INSERT INTO iot.devices(UUID,LABEL) VALUES('%s','%s');";

WiFiClient wClient;

MySQL_Connection sqlConn((Client *)&wClient);
void setup()
{
  WiFi.mode(WIFI_STA);
  Serial.print("Connecting :\n ");
  WiFi.begin(ssid, wifiPassword);
  mac.replace(":", "");
  printf("Connected... mac=%s\n", mac.c_str());
  if (WiFi.isConnected())
  {
    printf("Wifi connected \n");
    printf("dns........%s\n", WiFi.dnsIP(0).toString().c_str());
  }
  if (sqlConn.connect(sqlIP, 3306, sqlUser, sqlPassword))
  {
    delay(10);
    printf("Connected to Sql\n");
  }
  else
  {
    printf("Connection to db failed..\n");
  }

  MySQL_Cursor *cur = new MySQL_Cursor(&sqlConn);
  char q[256];
  printf("Exec ->%s\n", insert_device);
  sprintf(q, insert_device, mac.c_str(), "ESP32-1");
  unsigned long st = millis();

  printf("Exec ->%s\n", q);
  cur->execute(q);
  unsigned long ct = millis();
  unsigned long tt = ct - st;
  char stt[6];
  itoa(tt, stt, 10);
  printf("Done in %s milli seconds...!\n", stt);
  printf("done./n\n");
  memset(q, 0, sizeof q); // we have no use anymore
  delete cur;
}

void loop()
{
  // put your main code here, to run repeatedly:
}