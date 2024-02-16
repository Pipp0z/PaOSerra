#pragma once

#include "Sensore.h"

class Temperatura: public Sensore
{
private:
    static bool faraday;

public:
    /*
     * @brief Temperatura()    costruttore di Default per la classe Temperatura
     */
    Temperatura();
    /*
     * @brief changeStato() cambia il valore dell'attributo statico faraday
     */
    bool static changeStato();
    /*
     * @param ~Temperatura() distruttore per la classe Temperatura
     */
     ~Temperatura() =default;
    /*
     * @brief getStato() visualizza il valore dell'attributo statico faraday
     */
    bool static getStato();
    /*
     * @brief toString() visualizza il vettore di Dati e la descrizione
     */
    std::string toString() const override;
    /*
     * @brief viewDato visualizza un solo Dato di tipo Temperatura con la misurazione e unita di misura selezionata
     */
    std::string static viewDato(Dato d);
    /*
     * @brief Qualita() metodo che calcola se l'ultimo valore registrato del sensore è buono(1), se è alto(2) e se è basso(0)
     */
    int Qualita(Dato d)const override;
     /*
     * @brief getType() ritorna il tipo della classe
     */
    std::string getType() const override;
};

