#include "modello/modello.h"
#include <iostream>

int main()
{
    Modello m;
    m.randomDati("18/01/2024");
    m.setDescrizioneSensore("Lumen", "Nera come la tua schiena, vestita di Nero");
    std::cout<<m.toString()<<std::endl;
    Luminosita::diminuisciIntensita();
    m.loadInfo("Dati.json");
    std::cout<<m.toString()<<std::endl;
}
