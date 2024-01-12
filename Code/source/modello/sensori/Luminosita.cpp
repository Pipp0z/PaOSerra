#include "Luminosita.h"

int Luminosita::intensita = 75;


void Luminosita::inserisciDato(Dato dato){
    datiSensore.append(dato);

}

bool Luminosita::modificaDato(QDate data, QTime orario, Dato dato){
    for (int i = 0; i < datiSensore.size(); ++i) {
        if (datiSensore.at(i).getData() == data && datiSensore.at(i).getOrario() == orario){
            datiSensore.replace(i,dato);
            return true;
        }

    }
    return false;
}
Dato Luminosita::ricercaDato(QDate data, QTime orario) const{
    for (int i = 0; i < datiSensore.size(); ++i) {
        if (datiSensore.at(i).getData() == data && datiSensore.at(i).getOrario() == orario){
            return datiSensore.at(i);
        }

    }
    Dato d("errore");
    return d;
}
bool Luminosita::eliminaDato(QDate data, QTime orario){
    for (int i = 0; i < datiSensore.size(); ++i) {
        if (datiSensore.at(i).getData() == data && datiSensore.at(i).getOrario() == orario){
            datiSensore.remove(i);
            return true;
        }

    }
    return false;
}
QVector<Dato> Luminosita::clonaDati() const{
    QVector<Dato> clone;
    if(datiSensore.isEmpty())
        return clone;
    for (int i = 0; i < datiSensore.size(); ++i) {
        clone.append(datiSensore.at(i));
    }
    return clone;
}
  int Luminosita::getIntensita() {
    return intensita;
}
