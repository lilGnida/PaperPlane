#include "DataBase/databasemanager.h"

DataBaseManager::DataBaseManager(QString &dbPath)
{
    if (dbPath != "") {
        db = QSqlDatabase::addDatabase("QSQLITE", "Aeroplan");
        db.setDatabaseName(dbPath);

        DB_tableModel = new QSqlTableModel(nullptr, db);

        DB_tableModel->setTable("aero");
        DB_tableModel->setEditStrategy(QSqlTableModel::OnFieldChange);
        DB_tableModel->setHeaderData(0, Qt::Horizontal, QObject::tr("icao"));
        DB_tableModel->setHeaderData(1, Qt::Horizontal, QObject::tr("aircraft"));
        DB_tableModel->setHeaderData(2, Qt::Horizontal, QObject::tr("category"));
        DB_tableModel->setHeaderData(3, Qt::Horizontal, QObject::tr("defenition"));
    }
}

DataBaseManager::~DataBaseManager()
{
    if (db.isOpen()) {
        db.close();
    }
}

bool DataBaseManager::getConnectionStatus()
{
    if (!db.open()) {
        qDebug() << "Error: connection with aero database failed";
        return false;
    } else {
        qDebug() << "Aero database: connection ok";
        return true;
    }
}

bool DataBaseManager::isValid()
{
    return db.isValid();
}

QString DataBaseManager::getPath()
{
    return db.databaseName();
}
