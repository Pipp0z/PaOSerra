#pragma once

#include "Sensore.h"

class Salinita: public Sensore {
private:
    static unsigned int sogliaSalinita;
public:
    Salinita();
    bool static aumentaSalinita();
    bool static diminuisciSalinita();
    ~Salinita() =default;
    int static getSalinita();
    std::string toString() const override;
    int Qualita(Dato d)const override;
    std::string getType() const override;
};


