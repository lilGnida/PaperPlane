#include "DataBase/databaseconnector.h"
#include "ui_databaseconnector.h"

DataBaseConnector::DataBaseConnector(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DataBaseConnector)
{
    ui->setupUi(this);

    this->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    this->setAttribute(Qt::WA_TranslucentBackground, true);

    if (/*db->isValid() && db->getConnectionStatus()*/ dbPath != "") {
        ui->lineEdit->setText(db->getPath());
    }

    if (connectionStatus) {
        ui->connectionStatus->setText("Статус: Подключена");
    }
}

DataBaseConnector::~DataBaseConnector()
{
    delete ui;
}

void DataBaseConnector::on_chooseButton_clicked()
{
    dbPath = QFileDialog::getOpenFileName(this, tr("Выберите базу данных"), "", tr("DataBase (*.db)"));
    db = new DataBaseManager(dbPath);

    if (db->getConnectionStatus()) {
        ui->connectionStatus->setText("Статус: Подключена");
        ui->lineEdit->setText(db->getPath());
        connectionStatus = true;
    }
}

void DataBaseConnector::on_cancelButton_clicked()
{
    hide();
}

