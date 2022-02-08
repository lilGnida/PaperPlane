#include "network/newudpconnection.h"
#include "ui_newudpconnection.h"

NewUdpConnection::NewUdpConnection(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::NewUdpConnection)
{
    ui->setupUi(this);

    this->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    this->setAttribute(Qt::WA_TranslucentBackground, true);

    ui->ip_lineEdit->setIpValidation();
    ui->port_lineEdit->setPortValidation();
}

NewUdpConnection::~NewUdpConnection()
{
    delete ui;
}

void NewUdpConnection::on_cancelButton_clicked()
{
    hide();
    emit unblur();
}

void NewUdpConnection::on_acceptButton_clicked()
{
    if (ui->ip_lineEdit->text() != "" && ui->port_lineEdit->text() != "") {
        emit setupNewUdpConnection(ui->ip_lineEdit->text(), ui->port_lineEdit->text());
        hide();
    }
}

