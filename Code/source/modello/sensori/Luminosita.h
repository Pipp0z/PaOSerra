#pragma once
#include "Sensore.h"

class Luminosita: public Sensore {
private:
    static int intensita;

public:
    Luminosita();
    ~Luminosita() =default;
    bool static aumentaIntensita();
    bool static diminuisciIntensita();
    static int getIntensita() ;
    std::string toString() const override;
    int qualita(Dato d)const override;
    std::string getType() const override;
};

