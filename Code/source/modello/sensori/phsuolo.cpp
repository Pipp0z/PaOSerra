#include "phsuolo.h"
int PHSuolo::tipoSuolo=Suoli::Turba;

PHSuolo::PHSuolo() {}


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

std::string PHSuolo::toString() const{
    std::string s="[PHSuolo: \n";
    s+=toStringSensore();
    s+="] \n";
    return s;
}
