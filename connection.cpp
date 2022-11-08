#include "connection.h"

Connection::Connection(){}

bool Connection::createconnect()
{
 db = QSqlDatabase::addDatabase("QODBC");
 bool test=false;
db.setDatabaseName("Test");
db.setUserName("farouk");
db.setPassword("farouk");
if (db.open()) test=true;

    return  test;
}
void Connection::closeconnect(){db.close();}
