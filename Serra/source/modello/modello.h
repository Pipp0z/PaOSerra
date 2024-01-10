#ifndef MODELLO_H
#define MODELLO_H

#include "serra.h"
#include <QObject>
#include <QDomDocument>
#include <QFile>
#include <QString>
#include <QDate>
#include <QTime>
#include <QtXml>
#include <QVector>


class modello
{
public:
    modello();

    bool saveInfo(const QString& nomeFile, Serra serra);
    bool loadInfo(const QString& nomeFile, Serra *serra);

};

#endif // MODELLO_H
