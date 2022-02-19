#include "plane.h"

Plane::Plane()
{}

Plane::Plane(QString icao, QString mode3A, QString callName, float elv)
{
    this->icao = icao;
    this->mode3A = mode3A;
    this->callName = callName;
    this->elv = elv;
}

Plane::~Plane()
{}

void Plane::append(QPointF point)
{
    track.append(point);
}

QVector<QPointF> Plane::getTrack()
{
    return track;
}

QString Plane::getIcao()
{
    return icao;
}

QString Plane::getMode3A()
{
    return mode3A;
}

QString Plane::getCallName()
{
    return callName;
}

float Plane::getElv()
{
    return elv;
}
