#include "networkcontroller.h"
#include <QDebug>

NetworkController::NetworkController(MainWindow *wnd)
    : window(wnd)
{
    newUdpConnection = new NewUdpConnection;
    connectionManager = new ConnectionManagement;

    //connect
    connect(newUdpConnection, &NewUdpConnection::setupNewUdpConnection, this, &NetworkController::setupNewUdpConnection);
}

NetworkController::~NetworkController() {

}

void NetworkController::showNewUdpConnectionWindow()
{
    newUdpConnection->show();
}

void NetworkController::showConnectionManagmentWindow()
{
    connectionManager->showConnectionManagementWindow();
}

void NetworkController::setupNewUdpConnection(QString ip, QString port)
{
    qDebug() << "new udp connection with ip: " << ip << " and port: " << port << " was set";

    QProcess *asterixDecoderProcess = new QProcess(this);

    asterixDecoderProcess->setProgram("AsterixDecoder");
    connect(asterixDecoderProcess, &QProcess::readyRead, [this, asterixDecoderProcess]() {
        readyRead(asterixDecoderProcess);
    });

    asterixDecoderProcess->start();

    QByteArray byte_ip = ip.toUtf8();
    QByteArray byte_port = port.toUtf8();
    byte_ip.append("\n");
    byte_port.append("\n");

    asterixDecoderProcess->write(byte_ip);
    asterixDecoderProcess->write(byte_port);

    processList.append(asterixDecoderProcess);
}

void NetworkController::readyRead(QProcess *process)
{
    qDebug() << process->readAll();
}
