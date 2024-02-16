#include "Sensore.h"

Sensore::Sensore() {}
void Sensore::inserisciDato(Dato dato)  {
    datiSensore.push_back(dato);

}

bool Sensore::modificaDato(Dato dato){
    for (size_t  i = 0; i < datiSensore.size(); ++i) {
        if (datiSensore.at(i).getData() == dato.getData() && datiSensore.at(i).getOrario() == dato.getOrario()){
            datiSensore[i]=dato;
            return true;
        }

    }
    return false;
}
Dato Sensore::ricercaDato(Date data, Time orario) const{
    for (size_t i = 0; i < datiSensore.size(); ++i) {
        if (datiSensore.at(i).getData() == data && datiSensore.at(i).getOrario() == orario){
            return datiSensore.at(i);
        }

    }
    throw std::invalid_argument("dato non trovato");
}
bool Sensore::eliminaDato(Date data, Time orario){
    for (size_t i = 0; i < datiSensore.size(); ++i) {
        if (datiSensore.at(i).getData() == data && datiSensore.at(i).getOrario() == orario){
            datiSensore.erase(datiSensore.begin()+i);
            return true;
        }

    }
    return false;
}
std::vector<Dato> Sensore::clonaDati() const{
    std::vector<Dato> clone;
    if(datiSensore.empty())
        return clone;
    for (size_t i = 0; i < datiSensore.size(); ++i) {
        clone.push_back(datiSensore.at(i));
    }
    return clone;
}

bool Sensore::isEmpty()const{
    return datiSensore.empty();
}
std::string Sensore::toString() const{
    std::string s;
    s+="Descrizione: "+getDescrizione()+"\n";
    for(size_t i=0;i<datiSensore.size();++i){
        s+=datiSensore[i].toString();
    }
    s+="\n";
    return s;
}
std::string Sensore::getDescrizione() const{
    return descrizione;
}
bool Sensore::setDescrizione(std::string s){
    descrizione=s;
    return true;
}
Dato Sensore::ultimoDato() const{
    if(!datiSensore.empty()){
        return datiSensore.back();
    }
    throw;
}
std::string Sensore::getType() const{
    return "";
}
