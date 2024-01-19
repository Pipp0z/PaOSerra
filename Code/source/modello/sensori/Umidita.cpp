#include "Umidita.h"


bool Umidita::acceso(true);
Umidita::Umidita(){}

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

std::string Umidita::toString() const{
    std::string s="[Umidita: \n";
    s+=toStringSensore();
    s+="] \n";
    return s;
}
