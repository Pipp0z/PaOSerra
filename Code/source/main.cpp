#include "modello/Modello.h"
#include <iostream>

int main()
{
    Modello m;
    m.randomDati("18/01/2024");
    Luminosita::aumentaIntensita();
    m.rimuoviSensore("Lumen");
    std::cout<<m.toString()<<std::endl;
    try{
    m.setDescrizioneSensore("Lumen", "Nera come la tua schiena, vestita da Sera");
    }catch(const std::invalid_argument& e){
        std::cout<<"Sensore non creato, metodo non disponibile"<<std::endl;
    }


     m.saveInfo("Dati.json");
      Temperatura::changeStato();


    m.loadInfo("Dati.json");

    std::cout<<m.toString()<<std::endl;
}
