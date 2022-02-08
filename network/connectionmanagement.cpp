#include "connectionmanagement.h"
#include "ui_connectionmanagement.h"

ConnectionManagement::ConnectionManagement(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ConnectionManagement)
{
    ui->setupUi(this);

    this->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    this->setAttribute(Qt::WA_TranslucentBackground, true);
}

ConnectionManagement::~ConnectionManagement()
{
    delete ui;
}

void ConnectionManagement::showConnectionManagementWindow()
{
    tableModel = new QStandardItemModel(0, 5,this);

    tableModel->setHeaderData(0, Qt::Horizontal, QObject::tr("IP отправителя"));
    tableModel->setHeaderData(1, Qt::Horizontal, QObject::tr("Порт"));
    tableModel->setHeaderData(2, Qt::Horizontal, QObject::tr("Статус"));
    tableModel->setHeaderData(3, Qt::Horizontal, QObject::tr("Скорость"));
    tableModel->setHeaderData(4, Qt::Horizontal, QObject::tr("Обработано самолетов"));

    ui->tableView->setModel(tableModel);
    ui->tableView->show();
    show();
}

void ConnectionManagement::on_exitButton_clicked()
{
    hide();
    emit unblur();
}

