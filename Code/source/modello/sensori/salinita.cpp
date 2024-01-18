#include "salinita.h"

unsigned int Salinita::sogliaSalinita=7;

Salinita::Salinita() {}
void Salinita::inserisciDato(Dato dato){
    datiSensore.push_back(dato);

}

bool Salinita::modificaDato(Dato dato){
    for (size_t  i = 0; i < datiSensore.size(); ++i) {
        if (datiSensore.at(i).getData() == dato.getData() && datiSensore.at(i).getOrario() == dato.getOrario()){
            datiSensore[i]=dato;
            return true;
        }

    }
    return false;
}
Dato Salinita::ricercaDato(Date data, Time orario) const{
    for (size_t i = 0; i < datiSensore.size(); ++i) {
        if (datiSensore.at(i).getData() == data && datiSensore.at(i).getOrario() == orario){
            return datiSensore.at(i);
        }

    }
    throw std::invalid_argument("dato non trovato");
}
bool Salinita::eliminaDato(Date data, Time orario){
    for (size_t i = 0; i < datiSensore.size(); ++i) {
        if (datiSensore.at(i).getData() == data && datiSensore.at(i).getOrario() == orario){
            datiSensore.erase(datiSensore.begin()+i);
            return true;
        }

    }
    return false;
}
std::vector<Dato> Salinita::clonaDati() const{
    std::vector<Dato> clone;
    if(datiSensore.empty())
        return clone;
    for (size_t i = 0; i < datiSensore.size(); ++i) {
        clone.push_back(datiSensore.at(i));
    }
    return clone;
}
bool Salinita::aumentaSalinita(){
    if(sogliaSalinita<=0)
        return false;
    sogliaSalinita--;
    return true;
}
bool Salinita::diminuisciSalinita(){
    if(sogliaSalinita>=10)
        return false;
    sogliaSalinita++;
    return true;
}
int  Salinita::getSalinita(){
    return sogliaSalinita;
}
bool Salinita::isEmpty()const{
    return datiSensore.empty();
}
