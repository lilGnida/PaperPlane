#ifndef CONNECTIONMANAGEMENT_H
#define CONNECTIONMANAGEMENT_H

#include <QWidget>
#include <QStandardItemModel>

namespace Ui {
class ConnectionManagement;
}

class ConnectionManagement : public QWidget
{
    Q_OBJECT

public:
    explicit ConnectionManagement(QWidget *parent = nullptr);
    ~ConnectionManagement();

    void showConnectionManagementWindow();

private slots:
    void on_exitButton_clicked();

signals:
    void unblur();

private:
    Ui::ConnectionManagement *ui;
    QStandardItemModel *tableModel;
};

#endif // CONNECTIONMANAGEMENT_H
