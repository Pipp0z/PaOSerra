#include "Dato.h"


Dato::Dato(QString unitaMis, double misura,QDate data,QTime orario):data(data),orario(orario),misurazione(misura),unitaMisura(unitaMis){}
Dato::Dato(QString unitaMis, double misura):data(QDate::currentDate()),orario(QTime::currentTime()),misurazione(misura),unitaMisura(unitaMis){}

Dato::Dato(QString unitaMis):data(),orario(),misurazione(),unitaMisura(unitaMis){}
QDate Dato::getData() const
{
    return data;
}

QTime Dato::getOrario() const
{
    return orario;
}
bool Dato::setMisurazione(double misura) {
    misurazione=misura;
        return true;

}

double Dato::getMisurazione() const {
    return misurazione;
}
QString Dato::getUnitaMisura() const{
    return unitaMisura;
}
Dato Dato::cloneDato() const{
    Dato d(getUnitaMisura(),getMisurazione(),getData(),getOrario());
    return d;
}

bool Dato::operator==(const Dato& other) const{
    if(unitaMisura==other.unitaMisura && misurazione==other.misurazione && orario==other.orario && data==other.data )
        return true;
    return false;
}

