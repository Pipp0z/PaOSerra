#include "Luminosita.h"

int Luminosita::intensita = 75;

Luminosita::Luminosita(){}

  int Luminosita::getIntensita() {
    return intensita;
}
  bool Luminosita::aumentaIntensita(){
      if(intensita>=100)
          return false;
      intensita+=5;
      return true;
  }
  bool Luminosita::diminuisciIntensita(){
      if(intensita<=0)
          return false;
      intensita-=5;
      return true;
  }

  std::string Luminosita::toString() const{
      std::string s="[Luminosita: \n";
      s+=toStringSensore();
      s+="] \n";
      return s;
  }
