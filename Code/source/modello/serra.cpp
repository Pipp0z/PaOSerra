#include "serra.h"


Serra::Serra(){

}

bool Serra::inserisciSensori(Sensore* s){
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
std::type_index trovaTipo(std::string unitaMis){
    if (unitaMis == "Lumen") {
        return typeid(Luminosita);
    } else if (unitaMis == "Celsius") {
        return typeid(Temperatura);
    } else if (unitaMis == "g/m^3") {
        return typeid(Umidita);
    } else if (unitaMis == "pH") {
        return typeid(PHSuolo);
    } else if (unitaMis == "mmho/cm") {
        return typeid(Salinita);
    } else {
        throw;
    }
}
void Serra::rimuoviSensore(const std::string s) {
    std::type_index tipoSensore= trovaTipo(s);


    auto it = std::remove_if(sensori.begin(), sensori.end(),
                             [tipoSensore](const Sensore* sensor) {
                                 return std::type_index(typeid(*sensor)) == tipoSensore;
                             });

    sensori.erase(it, sensori.end());
}

Sensore* Serra::cercaSensore( std::string s) {
    std::type_index tipoSensore= trovaTipo(s);

    for (const Sensore* sensor : sensori) {
        if (std::type_index(typeid(*sensor)) == tipoSensore) {
            return const_cast<Sensore*>(sensor);
        }
    }
    return nullptr;
}




bool Serra::inserisciDato(const Dato dato){
    std::type_index newSensorType= trovaTipo(dato.getUnitaMisura());



    for ( Sensore* sensore : sensori) {
        std::type_index sensorType(typeid(*sensore));
        if (sensorType == newSensorType) {
            sensore->inserisciDato(dato);
            return true;
        }
    }
    return false;
}
bool Serra::modificaDato(const Dato dato){
    std::type_index tipoSensore= trovaTipo(dato.getUnitaMisura());

    for ( Sensore* sensore : sensori) {
        std::type_index sensorType(typeid(*sensore));
        if (sensorType == tipoSensore) {
            sensore->modificaDato(dato);
            return true;
        }
    }
    return false;
}
const Dato Serra::ricercaDato(const Date data, const Time orario, const std::string unitaMis){
    std::type_index tipoSensore= trovaTipo(unitaMis);

        for ( Sensore* sensore : sensori) {
            std::type_index sensorType(typeid(*sensore));
            if (sensorType == tipoSensore) {
                 return sensore->ricercaDato(data, orario);
            }
        }


    throw std::invalid_argument("Dato non trovato");
}
bool Serra::eliminaDato(const Date data, const Time orario, const std::string unitaMis){
    std::type_index tipoSensore= trovaTipo(unitaMis);

    for ( Sensore* sensore : sensori) {
        std::type_index sensorType(typeid(*sensore));
        if (sensorType == tipoSensore) {
            return sensore->eliminaDato(data, orario);
        }
    }
    return false;
}
const std::vector<Dato> Serra::clona(const std::string unitaMis){
    std::type_index tipoSensore= trovaTipo(unitaMis);
    std::vector<Dato> temp;
    for ( Sensore* sensore : sensori) {
        std::type_index sensorType(typeid(*sensore));
        if (sensorType == tipoSensore) {
            return sensore->clonaDati();
        }
    }


    throw std::invalid_argument("Vettore non trovato");

}
bool Serra::isEmpty(const std::string unitaMis) const{

    std::type_index tipoSensore= trovaTipo(unitaMis);

    for ( Sensore* sensore : sensori) {
        std::type_index sensorType(typeid(*sensore));
        if (sensorType == tipoSensore) {
            return sensore->isEmpty();
        }
    }

    throw std::invalid_argument("Errore nella funzione");

}
std::string Serra::toString() const{
    std::string s="Serra: \n";
    for ( Sensore* sensore : sensori) {
        s+=sensore->toString();
    }

    return s;
}
bool Serra::setDescrizioneSensore(std::string unitaMis, std::string desc){
    std::type_index tipoSensore= trovaTipo(unitaMis);

    for ( Sensore* sensore : sensori) {
        std::type_index sensorType(typeid(*sensore));
        if (sensorType == tipoSensore) {
            return sensore->setDescrizione(desc);
        }
    }

    throw std::invalid_argument("Errore nella funzione");
}
std::string Serra::getDescrizioneSensore(std::string unitaMis){
    std::type_index tipoSensore= trovaTipo(unitaMis);

    for ( Sensore* sensore : sensori) {
        std::type_index sensorType(typeid(*sensore));
        if (sensorType == tipoSensore) {
            return sensore->getDescrizione();
        }
    }

    throw std::invalid_argument("Errore nella funzione");
}
