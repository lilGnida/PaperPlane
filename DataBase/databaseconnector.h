#ifndef DATABASECONNECTOR_H
#define DATABASECONNECTOR_H

#include <QDialog>
#include <QString>
#include <QFileDialog>
#include <DataBase/databasemanager.h>

namespace Ui {
class DataBaseConnector;
}

class DataBaseConnector : public QDialog
{
    Q_OBJECT

public:
    explicit DataBaseConnector(QWidget *parent = nullptr);
    ~DataBaseConnector();

private slots:
    void on_chooseButton_clicked();

    void on_cancelButton_clicked();

private:
    Ui::DataBaseConnector *ui;
    DataBaseManager *db;
    QString dbPath = "";
    bool connectionStatus = false;

};

#endif // DATABASECONNECTOR_H
