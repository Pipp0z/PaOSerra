#include "Dato.h"


Dato::Dato(std::string unitaMis, double misura,Date data,Time orario):data(data),orario(orario),misurazione(misura),unitaMisura(unitaMis){}
Dato::Dato(std::string unitaMis, double misura):data(QDate::currentDate()),orario(QTime::currentTime()),misurazione(misura),unitaMisura(unitaMis){}

Dato::Dato(std::string unitaMis):data(),orario(),misurazione(),unitaMisura(unitaMis){}
Date Dato::getData() const
{
    return data;
}

Time Dato::getOrario() const
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
std::string Dato::getUnitaMisura() const{
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
void Dato::operator=(const Dato& other){
    misurazione=other.getMisurazione();

}
