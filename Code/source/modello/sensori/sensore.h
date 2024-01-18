#ifndef SENSORE_H
#define SENSORE_H
#include <Vector>
#include "../DateTime/date.h"
#include "../DateTime/time.h"
#include "Dato.h"

class Sensore
{
private:
    std::vector<Dato> datiSensore;
public:
    Sensore();
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
    virtual ~Sensore()=default;
    bool isEmpty()const;
};

#endif // SENSORE_H
