#ifndef NETWORKCONTROLLER_H
#define NETWORKCONTROLLER_H

#include <QMainWindow>
#include <QThread>
#include <QVector>
#include <QByteArray>
#include <QProcess>
#include "network/newudpconnection.h"
#include "network/connectionmanagement.h"

class MainWindow;

class NetworkController: public QObject
{
    Q_OBJECT

public:
    NetworkController(MainWindow *wnd);
    ~NetworkController();

    void showNewUdpConnectionWindow();
    void showConnectionManagmentWindow();
    void unblurMainWindow();
    void setupNewUdpConnection(QString ip, QString port);

public slots:
    void readyRead(QProcess *process);

private:
    NewUdpConnection *newUdpConnection = nullptr;
    ConnectionManagement *connectionManager = nullptr;
    MainWindow *window = nullptr;

    QVector <QProcess*> processList;
};

#endif // NETWORKCONTROLLER_H
