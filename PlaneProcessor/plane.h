#ifndef PLANE_H
#define PLANE_H

#include <QString>
#include <QVector>
#include <QPointF>

class Plane
{
public:
    Plane();
    Plane(QString icao, QString mode3A, QString callName, float elv);
    ~Plane();

    void append(QPointF point);
    QVector <QPointF> getTrack();
    QString getIcao();
    QString getMode3A();
    QString getCallName();
    float getElv();

private:
    QString icao, mode3A, callName;
    float elv;
    QVector <QPointF> track;
};

#endif // PLANE_H
