#ifndef SERRA_H
#define SERRA_H

#include<QVector>
#include "sensori/Luminosita.h"
#include "sensori/Umidita.h"
#include "sensori/Temperatura.h"
#include "sensori/Dato.h"
class Serra
{
private:
    Temperatura temper; // Celsius
    Luminosita lumen; // Lumen
    Umidita umidita; // g/m^3
public:
    Serra();
    bool inserisciDato(const Dato dato);
    bool modificaDato( const QDate data, const QTime orario, const Dato dato);
    const Dato ricercaDato(const QDate data, const QTime orario, const QString unitaMis);
    bool eliminaDato(const QDate data, const QTime orario, const QString unitaMis);
    const QVector<Dato> clona(const QString unitaMis);

};

#endif // SERRA_H
