#include "modello/Modello.h"
#include <iostream>

int main()
{
    Modello m;
    m.randomDati("18/01/2024");
    m.setDescrizioneSensore("Lumen", "Nera come la tua schiena, vestita di Nero");
  Temperatura::changeStato();
     m.saveInfo("Dati.json");
      Temperatura::changeStato();
    std::cout<<m.toString()<<std::endl;

    m.loadInfo("Dati.json");

    std::cout<<m.toString()<<std::endl;
}
