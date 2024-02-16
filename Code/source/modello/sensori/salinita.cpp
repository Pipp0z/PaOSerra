#include "Salinita.h"

unsigned int Salinita::sogliaSalinita=7;

Salinita::Salinita() {}

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

std::string Salinita::toString() const{
    std::string s="[Salinita: \n";
    s+=Sensore::toString();
    s+="] \n";
    return s;
}
int Salinita::Qualita(Dato d)const {
    double misura=d.getMisurazione();
    if(misura>4)//per fare rientrare i range nel caso si usi dati randomici o errori del sensore
        misura=1.50*misura/100;
    if(misura>2){
        return 2;
    }else if(misura<1)
        return 0;

    return 1;
}
std::string Salinita::getType() const{
    return "mmho/cm";
}
