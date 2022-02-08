#ifndef NEWUDPCONNECTION_H
#define NEWUDPCONNECTION_H

#include <QWidget>
#include <QRegExp>
#include <QRegExpValidator>
#include "network/networklineedit.h"

namespace Ui {
class NewUdpConnection;
}

class NewUdpConnection : public QWidget
{
    Q_OBJECT

public:
    explicit NewUdpConnection(QWidget *parent = nullptr);
    ~NewUdpConnection();

private slots:
    void on_cancelButton_clicked();

    void on_acceptButton_clicked();

private:
    Ui::NewUdpConnection *ui;

signals:
    void setupNewUdpConnection(QString ip, QString port);
    void unblur();
};

#endif // NEWUDPCONNECTION_H
