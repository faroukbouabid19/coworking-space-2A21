#include "connection.h"

Connection::Connection(){}

bool Connection::createconnect()
{
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
bool test=false;

db.setDatabaseName("test");
db.setUserName("farouk");//inserer nom de l'utilisateur
db.setPassword("farouk");//inserer mot de passe de cet utilisateur

if (db.open())
test=true;


return  test;
}

void Connection::closeConnection(){db.close();}
