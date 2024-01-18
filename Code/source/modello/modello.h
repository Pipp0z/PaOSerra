#ifndef MODELLO_H
#define MODELLO_H

#include "serra.h"
#include <iostream>
#include <fstream>
#include "json.hpp"

using json = nlohmann::json;


class modello
{
private:
    Serra serra;
public:
    modello();
    /*
     * @brief saveInfo() funzione per salvare su un file XML
     * @param nomeFile costante contiene nome del file
     * @param serra
     */
    bool saveInfo(const std::string& nomeFile);
    bool loadInfo(const std::string& nomeFile);
    void inserisciDato(Dato dato);
    /*
     * @brief modificaDato()    modifica un dato del vettore
     * @param data      definisce la data del dato da modificare
     * @param orario    definisce l'orario del dato da modificare
     * @param dato      definisce il dato da caricare
     * @return bool      true se modificato con successo, false altrimenti
     */
    bool modificaDato(Date data, Time orario, Dato dato);
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

};

#endif // MODELLO_H
