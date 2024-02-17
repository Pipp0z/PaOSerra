#pragma once
#include <typeindex>
#include <vector>
#include "../DateTime/Date.h"
#include "../DateTime/Time.h"
#include "Dato.h"

class Sensore {
private:
    std::vector<Dato> datiSensore;
    std::string descrizione;
public:
    Sensore();
    void inserisciDato(Dato dato);
    bool modificaDato( Dato dato);
    Dato ricercaDato(Date data, Time orario) const ;
    bool eliminaDato(Date data, Time orario);
    std::vector<Dato> clonaDati() const ;
    bool isEmpty()const ;
    std::string getDescrizione() const;
    bool setDescrizione(std::string s);
    virtual ~Sensore()=default;
    virtual std::string toString()const ;
    virtual int qualita(Dato d)const =0;
    Dato ultimoDato() const;
    virtual std::string getType() const;
};


