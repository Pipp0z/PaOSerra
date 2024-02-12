#pragma once

#include "Sensore.h"

enum Suoli{Turba, Argillosa, Sabbiosa};
class PHSuolo: public Sensore
{
private:
    static int tipoSuolo;

public:
    PHSuolo();

    /*
     * @brief changeStato()    cambia l'unita di misura
     * @param int i             tramite un numero intero
     */
    bool static changeStato(int i);
    /*
     * @brief changeStato()     cambia l'unita di misura
     * @param std::string tipo  tramite una stringa
     */
    bool static changeStato(std::string tipo);
    /*
     * @brief getTipoSuolo()   visualizza il tipo di Suolo corrente
     */
    std::string static getTipoSuolo();
    /*
     * @param ~PHSuolo() distruttore per la classe Temperatura
     */
     ~PHSuolo() =default;
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


