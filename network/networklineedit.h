#ifndef NETWORKLINEEDIT_H
#define NETWORKLINEEDIT_H

#include <QLineEdit>
#include <QMouseEvent>
#include <QRegExp>
#include <QRegExpValidator>

class NetworkLineEdit: public QLineEdit
{
    Q_OBJECT

public:
    NetworkLineEdit();
    explicit NetworkLineEdit(QWidget *parent = 0);

    void setIpValidation();
    void setPortValidation();

};

#endif // NETWORKLINEEDIT_H
