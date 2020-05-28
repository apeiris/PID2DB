#include <Arduino.h>
#include <Print.h>
#include <Thing.h>

#define DEBUG
//#undef DEBUG
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
//char insert_device[] = "INSERT INTO iot.devices(UUID,LABEL) VALUES('%s','%s');";
// char sqlInsertEvent[] = "CALL insertEvent('%s','%s',%.2lf,@outx) ";

WiFiClient wClient;
MySQL_Connection sqlConn((Client *)&wClient);

//----------------------------------------------------------
static void ExecSQL(MySQL_Connection *conn )
{
  MySQL_Cursor *cur = new MySQL_Cursor(&sqlConn);
  char q[256];
  // printf("Exec ->%s\n", sqlInsertEvent);
  //sprintf(q, sqlInsertEvent, mac.c_str(), "TH1",101.12);
  //char sql [] ="CALL insertEvent('%s','%s',%.2lf,@outx);"

  sprintf(q, "CALL iot.insertEvent('%s','%s',%.2lf,@outx);", mac.c_str(), "TH1", 101.21);
  unsigned long st = millis();
  printf("%s\n", q);
  cur->execute(q);

  unsigned long tt = millis() - st; // blah .. should not do arithmatic on time !
  char stt[6];
  itoa(tt, stt, 10);
  printf("Done in %s milli seconds...!\n", stt);
  memset(q, 0, sizeof q); // we have no use anymore
  delete cur;
}
//----------------------------------------------------------

void setup()
{

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, wifiPassword);
  delay(500);
  mac.replace(":", "");
  printf("Wifi Connected... mac=%s\n", mac.c_str());
  sqlConn.connect(sqlIP, 3306, sqlUser, sqlPassword);

  printf("**** SQl connected= %i\n", sqlConn.connected());

  if (sqlConn.connected() == 1)
  {

    printf("Connected to Sql\n");
  }
  else
  {
    printf("Connection to db failed..\n");
  }

  //------------------------------------------------------
// call the exec sql with the connector
  int n = 10; // iterate so many times
  for(int i=1; i<=n;i++)   ExecSQL(&sqlConn);
  
  //------------------------------------------------------
}

void loop()
{
  // put your main code here, to run repeatedly:
}