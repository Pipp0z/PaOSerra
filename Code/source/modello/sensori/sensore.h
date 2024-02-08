#ifndef SENSORE_H
#define SENSORE_H
#include <vector>
#include "../DateTime/date.h"
#include "../DateTime/time.h"
#include "Dato.h"

class Sensore
{
private:
    std::vector<Dato> datiSensore;
    std::string descrizione;
public:
    Sensore();
    /*
     * @brief inserisciDato()    modifica un dato del vettore
     * @param dato      definisce il dato da caricare
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
     Dato ricercaDato(Date data, Time orario) const ;
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
     std::vector<Dato> clonaDati() const ;
     /*
     * @brief isEmpty()    ritorna true se il vettore è vuoto, false altrimenti
     */
     bool isEmpty()const ;
     /*
     * @brief getDescrizione()    ritorna la descrizione del sensore
     */
     std::string getDescrizione() const;
     /*
     * @brief setDescrizione()    cambia il contenuto di descrizione del sensore
     */
     bool setDescrizione(std::string s);
     /*
     * @brief ~Sensore()    distruttore della classe Sensore
     */
     virtual ~Sensore()=default;
     /*
     * @brief toStringSensore() visualizza il vettore di Dati e la descrizione
     */
     std::string toStringSensore()const;
     /*
     * @brief toString() metodo virtuale implementato nelle classi figlie
     */
     virtual std::string toString()const =0;
     /*
     * @brief Qualita() metodo virtuale implementato nelle classi figlie
     */
     virtual int Qualita(Dato d)const =0;
     /*
     * @brief ultimoDato() ritorna l'ultimo Dato inserito, altrimenti lancia una eccezione
     */
     Dato ultimoDato() const;
};

#endif // SENSORE_H
