#pragma once
#include "Sensore.h"

class Luminosita: public Sensore
{
private:
    static int intensita;

public:
    /*
     * @brief Luminosita()    costruttore per la classe Luminosita
     */
    Luminosita();

    /*
     * @brief ~Luminosita() distruttore per la classe Luminosita
     */
     ~Luminosita() =default;
    /*
     * @brief aumentaIntensita() aumenta di 5 l'attributo statico intensita della classe Luminosita
     */
    bool static aumentaIntensita();
     /*
     * @brief diminuisciIntensita() diminuisce di 5 l'attributo statico intensita della classe Luminosita
     */
    bool static diminuisciIntensita();
    /*
     * @brief getIntensita() visualizza l'attributo statico intensita della classe Luminosita
     */
    static int getIntensita() ;
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

