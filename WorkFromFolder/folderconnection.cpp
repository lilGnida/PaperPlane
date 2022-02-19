#include "folderconnection.h"
#include "ui_folderconnection.h"

FolderConnection::FolderConnection(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FolderConnection)
{
    ui->setupUi(this);

    this->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    this->setAttribute(Qt::WA_TranslucentBackground, true);
}

FolderConnection::~FolderConnection()
{
    delete ui;
}

void FolderConnection::on_chooseFolder_clicked()
{
    path = QFileDialog::getExistingDirectory(this, trUtf8("Выберите директорию"));
    ui->folderPath->setText(path);
}


void FolderConnection::on_exitButton_clicked()
{
    hide();
    emit unblur();
}


void FolderConnection::on_runButton_clicked(bool checked)
{
    if (!checked) {
        if (ui->runButton->text() == "Старт") {
            ui->runButton->setText("Стоп");

            emit sendDirPath(ui->folderPath->text());
        } else {
            ui->runButton->setText("Старт");
        }
    }
}

