#include "networklineedit.h"

NetworkLineEdit::NetworkLineEdit(QWidget *parent) :
    QLineEdit(parent)
{

}

void NetworkLineEdit::setIpValidation()
{
    QString ipRange = "(?:[0-1]?[0-9]?[0-9]|2[0-4][0-9]|25[0-5])";
    QRegExp ipRegex ("^" + ipRange + "\\." + ipRange + "\\." + ipRange + "\\." + ipRange + "$");
    QRegExpValidator *ipValidator = new QRegExpValidator(ipRegex, this);

    setValidator(ipValidator);
}

void NetworkLineEdit::setPortValidation()
{
    QString portRange = "(?:[0-9]?[0-9]?[0-9]?[0-9]?[0-9])";
    QRegExp portRegex ("^" + portRange + "$");
    QRegExpValidator *portValidator = new QRegExpValidator(portRegex, this);

    setValidator(portValidator);
}
