#include "Luminosita.h"

int Luminosita::intensita = 75;


void Luminosita::inserisciDato(Dato dato){
    datiSensore.push_back(dato);

}

bool Luminosita::modificaDato(Dato dato){
    for (size_t  i = 0; i < datiSensore.size(); ++i) {
        if (datiSensore.at(i).getData() == dato.getData() && datiSensore.at(i).getOrario() == dato.getOrario()){
            datiSensore[i]=dato;
            return true;
        }

    }
    return false;
}
Dato Luminosita::ricercaDato(Date data, Time orario) const{
    for (size_t i = 0; i < datiSensore.size(); ++i) {
        if (datiSensore.at(i).getData() == data && datiSensore.at(i).getOrario() == orario){
            return datiSensore.at(i);
        }

    }
    throw std::invalid_argument("dato non trovato");
}
bool Luminosita::eliminaDato(Date data, Time orario){
    for (size_t i = 0; i < datiSensore.size(); ++i) {
        if (datiSensore.at(i).getData() == data && datiSensore.at(i).getOrario() == orario){
            datiSensore.erase(datiSensore.begin()+i);
            return true;
        }

    }
    return false;
}
std::vector<Dato> Luminosita::clonaDati() const{
    std::vector<Dato> clone;
    if(datiSensore.empty())
        return clone;
    for (size_t i = 0; i < datiSensore.size(); ++i) {
        clone.push_back(datiSensore.at(i));
    }
    return clone;
}
  int Luminosita::getIntensita() {
    return intensita;
}
  bool Luminosita::aumentaIntensita(){
      if(intensita<=0)
          return false;
      intensita--;
      return true;
  }
  bool Luminosita::diminuisciIntensita(){
      if(intensita>=10)
          return false;
      intensita++;
      return true;
  }
  bool Luminosita::isEmpty()const{
      return datiSensore.empty();
  }
