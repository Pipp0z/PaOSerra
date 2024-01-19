#include "Temperatura.h"


bool Temperatura::faraday(false);
Temperatura::Temperatura(){}


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

std::string Temperatura::toString() const{
    std::string s="[Temperatura: \n";
    s+=toStringSensore();
    s+="] \n";
    return s;
}
