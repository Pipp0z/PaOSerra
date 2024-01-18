#include "phsuolo.h"
int PHSuolo::tipoSuolo=Suoli::Turba;

PHSuolo::PHSuolo() {}

void PHSuolo::inserisciDato(Dato dato){
        datiSensore.push_back(dato);

    }

    bool PHSuolo::modificaDato(Dato dato){
        for (size_t  i = 0; i < datiSensore.size(); ++i) {
            if (datiSensore.at(i).getData() == dato.getData() && datiSensore.at(i).getOrario() == dato.getOrario()){
                datiSensore[i]=dato;
                return true;
            }

        }
        return false;
    }
    Dato PHSuolo::ricercaDato(Date data, Time orario) const{
        for (size_t i = 0; i < datiSensore.size(); ++i) {
            if (datiSensore.at(i).getData() == data && datiSensore.at(i).getOrario() == orario){
                return datiSensore.at(i);
            }

        }
        throw std::invalid_argument("dato non trovato");
    }
    bool PHSuolo::eliminaDato(Date data, Time orario){
        for (size_t i = 0; i < datiSensore.size(); ++i) {
            if (datiSensore.at(i).getData() == data && datiSensore.at(i).getOrario() == orario){
                datiSensore.erase(datiSensore.begin()+i);
                return true;
            }

        }
        return false;
    }
    std::vector<Dato> PHSuolo::clonaDati() const{
        std::vector<Dato> clone;
        if(datiSensore.empty())
            return clone;
        for (size_t i = 0; i < datiSensore.size(); ++i) {
            clone.push_back(datiSensore.at(i));
        }
        return clone;
    }

bool PHSuolo::changeStato(int i) {
    tipoSuolo=i;

    return true;
}
bool PHSuolo::changeStato(std::string tipo) {
    if(tipo=="Turba"){
        tipoSuolo=0;
    }else if(tipo=="Sabbiosa"){
        tipoSuolo=1;
    }else if(tipo=="Argillosa"){
        tipoSuolo=2;
    }
    //se non dovesse essere nessuna di queste, rimane il valore di default
    return true;
}
std::string PHSuolo::getTipoSuolo(){
    switch (tipoSuolo) {
    case 0:
        return "Turba";
        break;
    case 1:
        return  "Sabbiosa";
        break;
    case 2:
        return  "Argillosa";
        break;
    default:
        return "Sconosciuta";
        break;
    }

}

bool PHSuolo::isEmpty()const{
    return datiSensore.empty();
}
