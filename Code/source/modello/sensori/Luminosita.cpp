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
  int Luminosita::Qualita(Dato d)const {
      if(d.getMisurazione()>85){
          return 2;
      }else if(d.getMisurazione()<65)
          return 0;

      return 1;
  }
