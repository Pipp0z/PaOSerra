#ifndef SALINITA_H
#define SALINITA_H

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

};

#endif // SALINITA_H
