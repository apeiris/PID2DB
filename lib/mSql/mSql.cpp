#include "mSql.h"
#include <errno.h>

mSql::mSql(Client &client, String hostIP, int hostPort, String user, String password) : _client(client), _hostIP(hostIP), _hostPort(hostPort), _user(user), _password(password)
{
#ifdef DEBUGmSql
    printf("connecting to IP=%s \n", hostIP.c_str());
    log_e("errorno = %s\n", strerror(errno));
#endif
}