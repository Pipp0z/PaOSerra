#ifndef TEMPERATURA_H
#define TEMPERATURA_H

#include "Sensore.h"

class Temperatura: public Sensore
{
private:
    static bool faraday;
    std::vector<Dato> datiSensore;
public:
    /*
     * @brief Temperatura()    costruttore per la classe Temperatura
     */
    Temperatura();
    /*
     * @brief inserisciDato()    aggiunge un dato al vettore
     * @param dato      definiscite il dato da aggiungere
     * @return bool      true se aggiunto con successo, false altrimenti
     */
    void inserisciDato(Dato dato);
    /*
     * @brief modificaDato()    modifica un dato del vettore
     * @param data      definisce la data del dato da modificare
     * @param orario    definisce l'orario del dato da modificare
     * @param dato      definisce il dato da caricare
     * @return bool      true se modificato con successo, false altrimenti
     */
    bool modificaDato( Dato dato);
    /*
     * @brief ricercaDato()    ricerca un dato presente nel vettore
     * @param data      definisce la data del dato da ricercare
     * @param orario    definisce l'orario del dato da ricercare
     * @return Dato     ritorna il dato trovato, altrimenti void
     */
    Dato ricercaDato(Date data, Time orario) const;
    /*
     * @brief eliminaDato()    elimina un dato presente nel vettore
     * @param data      definisce la data del dato da eliminare
     * @param orario    definisce l'orario del dato da eliminare
     * @return bool      true se eliminato con successo, false altrimenti
     */
    bool eliminaDato(Date data, Time orario);
    /*
     * @brief cloneDati()    ritorna una copia del vettore
     */
    std::vector<Dato> clonaDati() const;
    /*
     * @brief changeStato()    cambia l'unita di misura
     */
    bool static changeStato();
    /*
     * @param ~Temperatura() distruttore per la classe Temperatura
     */
    virtual ~Temperatura() =default;

    bool static getStato();
    bool isEmpty()const;
};
#endif // TEMPERATURA_H
