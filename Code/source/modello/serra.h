#pragma once

#include "sensori/Sensore.h"
#include "sensori/Luminosita.h"
#include "sensori/Umidita.h"
#include "sensori/Temperatura.h"
#include "sensori/Dato.h"
#include "sensori/phsuolo.h"
#include "sensori/Salinita.h"
#include <algorithm>
#include <typeindex>

class Serra {
private:
    std::vector<Sensore* > sensori;
    //Temperatura  Celsius
    //Luminosita   Lumen
    //Umidita      g/m^3
    //PHSuolo      pH
    //Salinita     mmho/cm

public:
    Serra();
    bool inserisciSensori(Sensore *s);
    void rimuoviSensore(const std::string s);
    Sensore* cercaSensore( std::string s);
    bool inserisciDato(const Dato dato);
    bool modificaDato( const Dato dato);
    const Dato ricercaDato(const Date data, const Time orario, const std::string unitaMis);
    bool eliminaDato(const Date data, const Time orario, const std::string unitaMis);
    const std::vector<Dato> clona(const std::string unitaMis);
    bool isEmpty(const std::string unitaMis) const;
    ~Serra();
    std::string toString() const;
    bool setDescrizioneSensore(std::string unitaMis, std::string desc);
    std::string getDescrizioneSensore(std::string unitaMis);
    int qualita(std::string unitaMis)const;
};

