#include "Dato.h"

Dato::Dato(std::string unitaMis, double misura,Date data,Time orario):data(data),orario(orario),unitaMisura(unitaMis) {
    if(misura<0)
        misura=-misura;
    misurazione=misura;
}

Dato::Dato(Dato const &other):data(other.getData()),orario(other.getOrario()),misurazione(other.getMisurazione()),unitaMisura(other.getUnitaMisura()) {}

Date Dato::getData() const {
    return data;
}

Time Dato::getOrario() const {
    return orario;
}

bool Dato::setMisurazione(double misura) {
    if(misura<0)
        misura=-misura;
    misurazione=misura;
    return true;
}

double Dato::getMisurazione() const {
    return misurazione;
}

std::string Dato::getUnitaMisura() const {
    return unitaMisura;
}

Dato Dato::cloneDato() const {
    Dato d(unitaMisura,misurazione,data,orario);
    return d;
}

bool Dato::operator==(const Dato& other) const {
    if(unitaMisura==other.unitaMisura && misurazione==other.misurazione && orario==other.orario && data==other.data )
        return true;
    return false;
}

void Dato::operator=(const Dato& other) {
    misurazione=other.getMisurazione();
}

std::string Dato::toString() const {
    return "Dato: Data ["+ this->getData().toString()+"] Orario ["+ this->getOrario().toString()+"] Misura [" + std::to_string(this->getMisurazione())+"] Unita Misura ["+ this->getUnitaMisura()+"]\n";
}
