#pragma once

#include "Sensore.h"

class Temperatura: public Sensore {
private:
    static bool faraday;

public:
    Temperatura();
    bool static changeStato();
    ~Temperatura() =default;
    bool static getStato();
    std::string toString() const override;
    std::string static viewDato(Dato d);
    int Qualita(Dato d)const override;
    std::string getType() const override;
};

