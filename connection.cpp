#include "connection.h"

Connection::Connection(){}

bool Connection::createconnect()
{
 db = QSqlDatabase::addDatabase("QODBC");
 bool test=false;
db.setDatabaseName("Test");
db.setUserName("Khalil");
db.setPassword("esprit22");
if (db.open()) test=true;

    return  test;
}
void Connection::closeconnect(){db.close();}
