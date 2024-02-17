#pragma once

#include "Serra.h"
#include "../../json/single_include/nlohmann/json.hpp"
#include <fstream>
#include <random>

using json = nlohmann::json;


class Modello
{
private:
    Serra serra;
public:
    Modello();
    bool saveInfo(const std::string& nomeFile);
    bool loadInfo(const std::string& nomeFile);
    bool inserisciDato(Dato dato);
    bool modificaDato(Dato dato);
    const Dato ricercaDato(const Date data, const Time orario, const std::string unitaMis);
    bool eliminaDato(const Date data, const Time orario, const std::string unitaMis);
    bool randomDati(std::string data);
    std::string toString()const;
    bool setDescrizioneSensore(std::string unitaMis, std::string desc);
    std::string getDescrizioneSensore(std::string unitaMis);
    // ritorna se l'ultimo valore registrato del sensore è buono(1), se è alto(2) e se è basso(0)
    int qualita(std::string unitaMis)const;
    bool inserisciSensori(Sensore *s);
    void rimuoviSensore(const std::string s);
    Sensore* cercaSensore( std::string s);
    std::vector<Dato> visualizzaDati(std::string s);
    bool isEmpty(std::string s);
};
