#include "serra.h"

bool Serra::inserisciDato(const Dato dato){
    if(dato.getUnitaMisura()=="Lumen"){
        lumen.inserisciDato(dato);
        return true;
    }
    if(dato.getUnitaMisura()=="Celsius"){
        temper.inserisciDato(dato);
        return true;
    }
    if(dato.getUnitaMisura()=="g/m^3"){
        umidita.inserisciDato(dato);
        return true;
    }

    return false;
}
bool Serra::modificaDato(const QDate data,const QTime orario,const Dato dato){
    if(dato.getUnitaMisura()=="Lumen"){
        return lumen.modificaDato(data, orario,dato);
    }
    if(dato.getUnitaMisura()=="Celsius"){

        return temper.modificaDato(data, orario,dato);
    }
    if(dato.getUnitaMisura()=="g/m^3"){

        return umidita.modificaDato(data, orario,dato);;
    }

    return false;
}
const Dato Serra::ricercaDato(const QDate data, const QTime orario, const QString unitaMis){
    if(unitaMis=="Lumen"){
        return lumen.ricercaDato(data, orario);
    }
    if(unitaMis=="Celsius"){

        return temper.ricercaDato(data, orario);
    }
    if(unitaMis=="g/m^3"){

        return umidita.ricercaDato(data, orario);
    }
    Dato d("errore");
    return d;
}
bool Serra::eliminaDato(const QDate data, const QTime orario, const QString unitaMis){
    if(unitaMis=="Lumen"){
        return lumen.eliminaDato(data, orario);
    }
    if(unitaMis=="Celsius"){

        return temper.eliminaDato(data, orario);
    }
    if(unitaMis=="g/m^3"){

         return temper.eliminaDato(data, orario);
    }

    return false;
}
const QVector<Dato> Serra::clona(const QString unitaMis){
    if(unitaMis=="Lumen"){
        return lumen.clonaDati();
    }
    if(unitaMis=="Celsius"){

        return temper.clonaDati();
    }
    if(unitaMis=="g/m^3"){

        return umidita.clonaDati();
    }
    QVector<Dato> clone;
   return  clone;
}
