#ifndef LUMINOSITA_H
#define LUMINOSITA_H
#include <vector>

#include "Sensore.h"

class Luminosita: public Sensore
{
private:
    static int intensita;
    std::vector<Dato> datiSensore;
public:
    /*
     * @brief Luminosita()    costruttore per la classe Luminosita
     */
    Luminosita();
    /*
     * @brief inserisciDato()    aggiunge un dato al vettore
     * @param dato      definiscite il dato da aggiungere
     * @return bool      true se aggiunto con successo, false altrimenti
     */
    void inserisciDato(Dato dato);
    /*
     * @brief modificaDato()    modifica un dato del vettore
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
     * @param ~Luminosita() distruttore per la classe Luminosita
     */
    virtual ~Luminosita() =default;
    bool static aumentaIntensita();
    bool static diminuisciIntensita();
    static int getIntensita();
    bool isEmpty()const;
};
#endif // LUMINOSITA_H
