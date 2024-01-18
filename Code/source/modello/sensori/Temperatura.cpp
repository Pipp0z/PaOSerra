#include "Temperatura.h"


bool Temperatura::faraday(false);

void Temperatura::inserisciDato(Dato dato){
    datiSensore.push_back(dato);

}

bool Temperatura::modificaDato(Dato dato){
    for (size_t  i = 0; i < datiSensore.size(); ++i) {
        if (datiSensore.at(i).getData() == dato.getData() && datiSensore.at(i).getOrario() == dato.getOrario()){
            datiSensore[i]=dato;
            return true;
        }

    }
    return false;
}
Dato Temperatura::ricercaDato(Date data, Time orario) const{
    for (size_t i = 0; i < datiSensore.size(); ++i) {
        if (datiSensore.at(i).getData() == data && datiSensore.at(i).getOrario() == orario){
            return datiSensore.at(i);
        }

    }
    throw std::invalid_argument("dato non trovato");
}
bool Temperatura::eliminaDato(Date data, Time orario){
    for (size_t i = 0; i < datiSensore.size(); ++i) {
        if (datiSensore.at(i).getData() == data && datiSensore.at(i).getOrario() == orario){
            datiSensore.erase(datiSensore.begin()+i);
            return true;
        }

    }
    return false;
}
std::vector<Dato> Temperatura::clonaDati() const{
    std::vector<Dato> clone;
    if(datiSensore.empty())
        return clone;
    for (size_t i = 0; i < datiSensore.size(); ++i) {
        clone.push_back(datiSensore.at(i));
    }
    return clone;
}

bool Temperatura::changeStato() {
    if(faraday)
        faraday=false;
    else
        faraday=true;
    return true;
}
bool Temperatura::getStato(){
    return faraday;
}
bool Temperatura::isEmpty()const{
    return datiSensore.empty();
}

