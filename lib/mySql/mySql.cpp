#include "mySql.h"
#include <errno.h>
#define DEBUGmySql

mySql::mySql(Client &client, IPAddress hostIP, int hostPort, String user, String password, String db)
    : _client(client), _hostIP(hostIP), _hostPort(hostPort), _user(user), _password(password), _db(db)
{
#ifdef DEBUGmySql
    printf("*** constructor called <== \nconnecting to IP=%s \n", hostIP.toString().c_str());
    log_e("errorno = %s\n", strerror(errno));
#endif
    MySQL_Connection _conn(&_client);
    _conn.connect(_hostIP, _hostPort, (char *)_user.c_str(), (char *)_password.c_str(), (char *)_db.c_str());
    delay(400);
    if (_conn.connected() == 1)
    {
        printf("Server version=%s \n", (char *)_conn.server_version);
        printf("Connected.. current State:%s \n", strerror(errno));
    }
    else
    {
        printf("Can not cnnect !.\n");
    }
}

int mySql::ExecSql(String sqlToExec)
{
#ifdef DEBUGmySql
    log_e("arg[1]-> %s \n", sqlToExec.c_str());

#endif
    MySQL_Connection _conn((Client *)&_client);
    MySQL_Cursor *cur = new MySQL_Cursor(&_conn);
    cur->execute(sqlToExec.c_str());

    delete cur;
    // _conn.close();
    return -1;
}
mySql::~mySql()
{
    _client.stop();
    
    //delete &_client;
    printf("**** destructor has been called <==== \n\n");
}