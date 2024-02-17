#include "Serra.h"

Serra::Serra() {}

bool Serra::inserisciSensori(Sensore* s) {
    std::type_index newSensorType(typeid(*s));
    for (const Sensore* sensor : sensori) {
        std::type_index sensorType(typeid(*sensor));
        if (sensorType == newSensorType) {
            return false;
        }
    }
    sensori.push_back(s);
    return true;
}

void Serra::rimuoviSensore(const std::string s) {
    for (auto it = sensori.begin(); it != sensori.end();) {
        if ((*it)->getType() == s) {
            delete *it;
            it = sensori.erase(it);
        } else {
            ++it;
        }
    }
}

Sensore* Serra::cercaSensore( std::string s) {
    for (const Sensore* sensor : sensori) {
        if (sensor->getType() == s) {
            return const_cast<Sensore*>(sensor);
        }
    }
    return nullptr;
}

bool Serra::inserisciDato(const Dato dato) {
    for ( Sensore* sensore : sensori) {
        if (sensore->getType() == dato.getUnitaMisura()) {
            sensore->inserisciDato(dato);
            return true;
        }
    }
    return false;
}

bool Serra::modificaDato(const Dato dato){
    for ( Sensore* sensore : sensori) {
        if (sensore->getType() == dato.getUnitaMisura()) {
            sensore->modificaDato(dato);
            return true;
        }
    }
    return false;
}

const Dato Serra::ricercaDato(const Date data, const Time orario, const std::string unitaMis) {
    for ( Sensore* sensore : sensori) {
        if (sensore->getType() == unitaMis) {
                return sensore->ricercaDato(data, orario);
        }
    }
    throw std::invalid_argument("Dato non trovato");
}

bool Serra::eliminaDato(const Date data, const Time orario, const std::string unitaMis) {
    for ( Sensore* sensore : sensori) {
        if (sensore->getType() == unitaMis) {
            return sensore->eliminaDato(data, orario);
        }
    }
    return false;
}

const std::vector<Dato> Serra::clona(const std::string unitaMis) {
    std::vector<Dato> temp;
    for ( Sensore* sensore : sensori) {
        if (sensore->getType() == unitaMis) {
            return sensore->clonaDati();
        }
    }
    throw std::invalid_argument("Vettore non trovato");
}

bool Serra::isEmpty(const std::string unitaMis) const {
    for ( Sensore* sensore : sensori) {
        if (sensore->getType() == unitaMis) {
            return sensore->isEmpty();
        }
    }
    return true;
}

std::string Serra::toString() const {
    std::string s = "Serra: \n";
    for ( Sensore* sensore : sensori) {
        s+=sensore->toString();
    }
    return s;
}

bool Serra::setDescrizioneSensore(std::string unitaMis, std::string desc) {
    for ( Sensore* sensore : sensori) {
        if (sensore->getType() == unitaMis) {
            return sensore->setDescrizione(desc);
        }
    }
    throw std::invalid_argument("Errore nella funzione setDescrizione");
}

std::string Serra::getDescrizioneSensore(std::string unitaMis) {
    for ( Sensore* sensore : sensori) {
        if (sensore->getType() == unitaMis) {
            return sensore->getDescrizione();
        }
    }
    return "";
}

Serra::~Serra() {
    for (Sensore* sensore : sensori) {
        delete sensore;
    }
}

int Serra::qualita(std::string unitaMis) const {
    for ( Sensore* sensore : sensori) {
        if (sensore->getType() == unitaMis) {
            return sensore->qualita(sensore->ultimoDato());
        }
    }
    throw std::invalid_argument("Errore nella funzione");
}