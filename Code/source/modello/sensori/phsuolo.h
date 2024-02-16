#pragma once

#include "Sensore.h"

enum Suoli{Turba, Argillosa, Sabbiosa};
class PHSuolo: public Sensore {
private:
    static int tipoSuolo;

public:
    PHSuolo();
    bool static changeStato(int i);
    bool static changeStato(std::string tipo);
    std::string static getTipoSuolo();
    ~PHSuolo() =default;
    std::string toString() const override;
    int Qualita(Dato d)const override;
    std::string getType() const override;
};