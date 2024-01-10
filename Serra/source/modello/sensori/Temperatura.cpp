#include "Temperatura.h"


bool Temperatura::faraday(true);

void Temperatura::inserisciDato(Dato dato){
    datiSensore.append(dato);

}

bool Temperatura::modificaDato(QDate data, QTime orario, Dato dato){
    for (int i = 0; i < datiSensore.size(); ++i) {
        if (datiSensore.at(i).getData() == data && datiSensore.at(i).getOrario() == orario){
            datiSensore.replace(i,dato);
            return true;
        }

    }
    return false;
}
Dato Temperatura::ricercaDato(QDate data, QTime orario) const{
    for (int i = 0; i < datiSensore.size(); ++i) {
        if (datiSensore.at(i).getData() == data && datiSensore.at(i).getOrario() == orario){
            return datiSensore.at(i);
        }

    }
    Dato d("errore");
    return d;
}
bool Temperatura::eliminaDato(QDate data, QTime orario){
    for (int i = 0; i < datiSensore.size(); ++i) {
        if (datiSensore.at(i).getData() == data && datiSensore.at(i).getOrario() == orario){
            datiSensore.remove(i);
            return true;
        }

    }
    return false;
}

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

QVector<Dato> Temperatura::clonaDati() const{
    QVector<Dato> clone;
    if(datiSensore.isEmpty())
        return clone;
    for (int i = 0; i < datiSensore.size(); ++i) {
        clone.append(datiSensore.at(i));
    }
    return clone;
}
