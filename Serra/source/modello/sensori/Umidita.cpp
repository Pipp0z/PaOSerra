#include "Umidita.h"


bool Umidita::acceso(true);

void Umidita::inserisciDato(Dato dato){
    datiSensore.append(dato);

}

bool Umidita::modificaDato(QDate data, QTime orario, Dato dato){
    for (int i = 0; i < datiSensore.size(); ++i) {
        if (datiSensore.at(i).getData() == data && datiSensore.at(i).getOrario() == orario){
            datiSensore.replace(i,dato);
            return true;
        }

    }
    return false;
}
Dato Umidita::ricercaDato(QDate data, QTime orario) const{
    for (int i = 0; i < datiSensore.size(); ++i) {
        if (datiSensore.at(i).getData() == data && datiSensore.at(i).getOrario() == orario){
            return datiSensore.at(i);
        }

    }
    Dato d("errore");
    return d;
}
bool Umidita::eliminaDato(QDate data, QTime orario){
    for (int i = 0; i < datiSensore.size(); ++i) {
        if (datiSensore.at(i).getData() == data && datiSensore.at(i).getOrario() == orario){
            datiSensore.remove(i);
            return true;
        }

    }
    return false;
}
QVector<Dato> Umidita::clonaDati() const{
    QVector<Dato> clone;
    if(datiSensore.isEmpty())
        return clone;
    for (int i = 0; i < datiSensore.size(); ++i) {
        clone.append(datiSensore.at(i));
    }
    return clone;
}
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
