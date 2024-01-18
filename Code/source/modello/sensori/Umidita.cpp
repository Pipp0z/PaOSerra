#include "Umidita.h"


bool Umidita::acceso(true);

void Umidita::inserisciDato(Dato dato){
    datiSensore.push_back(dato);

}

bool Umidita::modificaDato(Dato dato){
    for (size_t  i = 0; i < datiSensore.size(); ++i) {
        if (datiSensore.at(i).getData() == dato.getData() && datiSensore.at(i).getOrario() == dato.getOrario()){
            datiSensore[i]=dato;
            return true;
        }

    }
    return false;
}
Dato Umidita::ricercaDato(Date data, Time orario) const{
    for (size_t i = 0; i < datiSensore.size(); ++i) {
        if (datiSensore.at(i).getData() == data && datiSensore.at(i).getOrario() == orario){
            return datiSensore.at(i);
        }

    }
    throw std::invalid_argument("dato non trovato");
}
bool Umidita::eliminaDato(Date data, Time orario){
    for (size_t i = 0; i < datiSensore.size(); ++i) {
        if (datiSensore.at(i).getData() == data && datiSensore.at(i).getOrario() == orario){
            datiSensore.erase(datiSensore.begin()+i);
            return true;
        }

    }
    return false;
}
std::vector<Dato> Umidita::clonaDati() const{
    std::vector<Dato> clone;
    if(datiSensore.empty())
        return clone;
    for (size_t i = 0; i < datiSensore.size(); ++i) {
        clone.push_back(datiSensore.at(i));
    }
    return clone;
}
bool Umidita::changeStato(){
    if(acceso)
        acceso=false;
    else
        acceso=true;
    return true;
}
bool  Umidita::getAcceso(){
    return acceso;
}
bool Umidita::isEmpty()const{
    return datiSensore.empty();
}
