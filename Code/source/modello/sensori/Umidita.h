#ifndef UMIDITA_H
#define UMIDITA_H

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
};
#endif // UMIDITA_H
