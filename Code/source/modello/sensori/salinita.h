#pragma once

#include "Sensore.h"

class Salinita: public Sensore
{
private:
    static unsigned int sogliaSalinita;
public:
    /*
     * @brief Salinita()    costruttore per la classe Temperatura
     */
    Salinita();
    /*
     * @brief aumentaSalinita() aumenta di 1 l'attributo statico sogliaSalinita
     */
    bool static aumentaSalinita();
    /*
     * @brief diminuisciSalinita() diminuisce di 1 l'attributo statico sogliaSalinita
     */
    bool static diminuisciSalinita();
    /*
     * @param ~Salinita() distruttore per la classe Temperatura
     */
     ~Salinita() =default;
    /*
     * @brief getSalinita() visualizza l'attributo statico sogliaSalinita
     */
    int static getSalinita();
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


