#ifndef DATABASECONNECTORCONTROLLER_H
#define DATABASECONNECTORCONTROLLER_H

#include <QObject>
#include <QMainWindow>
#include <DataBase/databaseconnector.h>

class MainWindow;

class DataBaseConnectorController : public QObject
{
    Q_OBJECT

public:
    DataBaseConnectorController(MainWindow *wnd);
    ~DataBaseConnectorController();

    void showDataBaseConnectionWindow();
    void unblurMainWindow();

private:
    DataBaseConnector *dbConnector = nullptr;
    MainWindow *window = nullptr;
};

#endif // DATABASECONNECTORCONTROLLER_H
