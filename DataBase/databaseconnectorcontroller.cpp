#include "DataBase/databaseconnectorcontroller.h"
#include "mainwindow.h"

DataBaseConnectorController::DataBaseConnectorController(MainWindow *wnd)
    : window(wnd)
{
    dbConnector = new DataBaseConnector;

    connect(dbConnector, &DataBaseConnector::unblur, this, &DataBaseConnectorController::unblurMainWindow);
}

DataBaseConnectorController::~DataBaseConnectorController()
{

}

void DataBaseConnectorController::showDataBaseConnectionWindow()
{
    dbConnector->show();
}

void DataBaseConnectorController::unblurMainWindow()
{
    window->blur(false);
}
