#pragma once

#include "Sensore.h"

class Umidita: public Sensore
{
private:
    static bool acceso;

public:
    /*
     * @brief Umidita()    costruttore per la classe Umidita
     */
    Umidita();
    /*
     * @brief ~Umidita() distruttore per la classe Umidita
     */
     ~Umidita() =default;
    /*
     * @brief changeStato() cambia il valore dell'attributo statico acceso
     */
    bool static changeStato();
    /*
     * @brief getAcceso() visualizza il valore dell'attributo statico acceso
     */
    bool static getAcceso();
    /*
     * @brief toString() visualizza il vettore di Dati e la descrizione
     */
    std::string toString() const override;
    /*
     * @brief Qualita() metodo che calcola se l'ultimo valore registrato del sensore è buono(1), se è alto(2) e se è basso(0)
     */
    int Qualita(Dato d)const override;
     /*
     * @brief getType() ritorna il tipo della classe
     */
    std::type_index getType() const override;
};

