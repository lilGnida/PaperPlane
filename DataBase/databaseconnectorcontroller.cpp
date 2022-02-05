#include "DataBase/databaseconnectorcontroller.h"

DataBaseConnectorController::DataBaseConnectorController(QObject *parent) : QObject(parent)
{
    dbConnector = new DataBaseConnector;

    //    connect(dbConnector, &DataBaseConnector::)
}

void DataBaseConnectorController::showDataBaseConnectionWindow()
{
    dbConnector->show();
}
