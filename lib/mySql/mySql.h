#ifndef __mySql_H__
#define __mySql_H__
#include <MySQL_Connection.h>
#include <MySQL_Cursor.h>
#include <MySQL_Packet.h>
#include <WiFiClient.h>

class mySql
{
public:
    mySql(Client &client, IPAddress hostIP, int hostPort, String user, String password, String db);
    int ExecSql(String sqlToExec);

private:
    Client& _client;
    IPAddress _hostIP;
    int _hostPort;
    String _user, _password;
    String _db;
    //MySQL_Connection _conn;
};
#endif // __mSql_H__