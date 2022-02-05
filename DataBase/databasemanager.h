#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include <QString>
#include <QSqlDatabase>
#include <QSqlTableModel>
#include <QSqlQueryModel>
#include <QSqlQuery>
#include <QDebug>

class DataBaseManager
{
public:
    DataBaseManager(QString &dbPath);
    ~DataBaseManager();

    QSqlTableModel *DB_tableModel;
    bool getConnectionStatus();
    bool isValid();
    QString getPath();

private:
    QSqlDatabase db;
};

#endif // DATABASEMANAGER_H
