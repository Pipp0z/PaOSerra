#include "serra.h"

bool Serra::inserisciDato(const Dato dato){
    if(dato.getUnitaMisura()=="Lumen"){
        lumen.inserisciDato(dato);
        return true;
    }
    else if(dato.getUnitaMisura()=="Celsius"){
        temper.inserisciDato(dato);
        return true;
    }
    else if(dato.getUnitaMisura()=="g/m^3"){
        umidita.inserisciDato(dato);
        return true;
    }
    else if(dato.getUnitaMisura()=="pH"){
        PHSuolo.inserisciDato(dato);
        return true;
    }
    else if(dato.getUnitaMisura()=="mmho/cm"){
        salinita.inserisciDato(dato);
        return true;
    }

    return false;
}
bool Serra::modificaDato(const Dato dato){
    if(dato.getUnitaMisura()=="Lumen"){
        return lumen.modificaDato(dato);
    }
    else if(dato.getUnitaMisura()=="Celsius"){

        return temper.modificaDato(dato);
    }
    else if(dato.getUnitaMisura()=="g/m^3"){

        return umidita.modificaDato(dato);
    }
    else if(dato.getUnitaMisura()=="pH"){

        return PHSuolo.modificaDato(dato);
    }
    else if(dato.getUnitaMisura()=="mmho/cm"){

        return salinita.modificaDato(dato);
    }

    return false;
}
const Dato Serra::ricercaDato(const Date data, const Time orario, const std::string unitaMis){
    if(unitaMis=="Lumen"){
        return lumen.ricercaDato(data, orario);
    }
    else if(unitaMis=="Celsius"){

        return temper.ricercaDato(data, orario);
    }
    else if(unitaMis=="g/m^3"){

        return umidita.ricercaDato(data, orario);
    }
    else if(unitaMis==""){

        return PHSuolo.ricercaDato(data, orario);
    }
    else if(unitaMis=="mmho/cm"){

        return salinita.ricercaDato(data, orario);
    }
    throw std::invalid_argument("Dato non trovato");
}
bool Serra::eliminaDato(const Date data, const Time orario, const std::string unitaMis){
    if(unitaMis=="Lumen"){
        return lumen.eliminaDato(data, orario);
    }
    else if(unitaMis=="Celsius"){

        return temper.eliminaDato(data, orario);
    }
    else if(unitaMis=="g/m^3"){

         return temper.eliminaDato(data, orario);
    }
    else if(unitaMis=="pH"){

        return PHSuolo.eliminaDato(data, orario);
    }
    else if(unitaMis=="mmho/cm"){

        return salinita.eliminaDato(data, orario);
    }

    return false;
}
const std::vector<Dato> Serra::clona(const std::string unitaMis){
    if(unitaMis=="Lumen"){
        return lumen.clonaDati();
    }
    else if(unitaMis=="Celsius"){

        return temper.clonaDati();
    }
    else if(unitaMis=="g/m^3"){

        return umidita.clonaDati();
    }
    else if(unitaMis=="pH"){

        return PHSuolo.clonaDati();
    }
    else if(unitaMis=="mmho/cm"){

        return salinita.clonaDati();
    }
    throw std::invalid_argument("vettore non trovato");

}
bool Serra::isEmpty(const std::string unitaMis) const{
    if(unitaMis=="Lumen"){
        return lumen.isEmpty();
    }
    else if(unitaMis=="Celsius"){

        return temper.isEmpty();
    }
    else if(unitaMis=="g/m^3"){

        return umidita.isEmpty();
    }
    else if(unitaMis=="pH"){

        return PHSuolo.isEmpty();
    }
    else if(unitaMis=="mmho/cm"){

        return salinita.isEmpty();
    }
    throw std::invalid_argument("vettore non trovato");

}
