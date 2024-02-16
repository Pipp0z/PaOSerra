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
    s+=Sensore::toString();
    s+="] \n";
    return s;
}
int Umidita::Qualita(Dato d)const {
    double misura=d.getMisurazione();

    if(misura>15){
        return 2;
    }else if(misura<10)
        return 0;

    return 1;
}
std::string Umidita::getType() const{
    return "g/m^3";
}
