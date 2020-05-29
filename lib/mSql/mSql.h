#ifndef __mSql_H__
#define __mSql_H__
#include <MySQL_Connection.h>
#include <MySQL_Cursor.h>
#include <WiFiClient.h>

class mSql
{
public:
    mSql(Client& client,String hostIP,int hostPort
        ,String user,String password
    );
   

   

private:
    Client& _client;
    String _hostIP;
    int _hostPort;
    String _user,_password;
};
#endif // __mSql_H__