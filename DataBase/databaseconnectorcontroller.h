#ifndef DATABASECONNECTORCONTROLLER_H
#define DATABASECONNECTORCONTROLLER_H

#include <QObject>
#include <DataBase/databaseconnector.h>

class DataBaseConnectorController : public QObject
{

    Q_OBJECT

public:
    DataBaseConnectorController(QObject *parent);

    void showDataBaseConnectionWindow();

private:
    DataBaseConnector *dbConnector = nullptr;
};

#endif // DATABASECONNECTORCONTROLLER_H
