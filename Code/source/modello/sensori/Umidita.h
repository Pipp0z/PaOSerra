#pragma once

#include "Sensore.h"

class Umidita: public Sensore {
private:
    static bool acceso;

public:
    Umidita();
    ~Umidita() =default;
    bool static changeStato();
    bool static getAcceso();
    std::string toString() const override;
    int Qualita(Dato d) const override;
    std::string getType() const override;
};

