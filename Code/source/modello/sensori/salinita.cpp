#include "salinita.h"

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
    s+=toStringSensore();
    s+="] \n";
    return s;
}
