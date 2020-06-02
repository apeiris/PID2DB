#include <Arduino.h>
#include <Print.h>
#include <Thing.h>

#define DEBUG
#undef DEBUG
#include <WebThingAdapter.h>
#include <WiFi.h>

#define DEBUGmSql
#include "mySql.h"

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

MySQL_Connection sconn((Client *)&wClient);
//----------------------------------------------------------

void ExecSQL(MySQL_Connection *conn)
{

  MySQL_Cursor *cur = new MySQL_Cursor(conn);
  char q[256];
  sprintf(q, "CALL iot.insertEvent('%s','%s',%.2lf,'%s',@outx);", mac.c_str(), "TH1", 101.21,mac.c_str());
  unsigned long st = millis();
  printf("%s\n", q);
  cur->execute(q);

  unsigned long tt = millis() - st; // blah .. should not do arithmatic on time !
  char stt[6];
  itoa(tt, stt, 10);
  printf("Done in %s milli seconds...!\n", stt);
  memset(q, 0, sizeof q); // we have no use anymore
  delete cur;
};
/*
static void ExecSQL(MySQL_Connection *conn, char *stmt)
{
  MySQL_Cursor *cur = new MySQL_Cursor(conn);
  unsigned long st = millis();
  printf("%s\n", stmt);
  cur->execute(stmt);

  unsigned long tt = millis() - st; // blah .. should not do arithmatic on time !
  char stt[6];
  itoa(tt, stt, 10);
  printf("Done in %s milli seconds...!\n", stt);
  // memset(q, 0, sizeof q); // we have no use anymore
  delete cur;
};
*/

//----------------------------------------------------------
//mSql sql(wClient);
//----------------------------------------------------------
void setup()
{

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, wifiPassword);
  delay(500);
  mac.replace(":", "");
  printf("Wifi Connected... mac=%s\n", mac.c_str());

  //------------------------------------------------------
  char q[256];
  //sprintf(q, "CALL iot.insertEvent('%s','%s',%.2lf,@outx);", mac.c_str(), "TH3", 101.21);
    sprintf(q, "CALL iot.insertEvent('%s','%s',%.2lf,'%s',@outx);", mac.c_str(), "TH1", 101.21,mac.c_str());
  for (int i = 1; i <= 100; i++)
    //sql::ExecSQL((char*)q);

    memset(q, 0, sizeof q); // we have no use anymore
  printf("Completed...\n");

  String u = sqlUser;

  printf("Sql u=%s ,char[] sqlUser=%s\n\n", u.c_str(), sqlUser);
  //----On to mSql Class ---------------------------------

  mySql sql(wClient, sqlIP, 3306, sqlUser, sqlPassword, "IOT");

  //sprintf(q, "CALL iot.insertEvent('%s','%s',%.2lf,@outx);", mac.c_str(), "TH1", 101.21);
    sprintf(q, "CALL iot.insertEvent('%s','%s',%.2lf,'%s',@outx);", mac.c_str(), "TH1", 101.21,mac.c_str());
  for (int i = 1; i < 100; i++)
    sql.ExecSql(q);

}
void loop()
{
  // put your main code here, to run repeatedly:
}