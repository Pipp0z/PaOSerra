#ifndef MODELLO_H
#define MODELLO_H

#include "serra.h"
#include "json.hpp"
#include <fstream>
#include <random>

using json = nlohmann::json;


class Modello
{
private:
    Serra serra;
public:
    /*
     * @brief Modello() costruttore della classe
     */
    Modello();
    /*
     * @brief saveInfo() funzione per salvare su un file JSON
     * @param nomeFile costante contiene nome del file
     */
    bool saveInfo(const std::string& nomeFile);
    /*
     * @brief loadInfo() funzione per caricare un salvataggio da un file JSON
     * @param nomeFile costante contiene nome del file
     */
    bool loadInfo(const std::string& nomeFile);
    /*
     * @brief inserisciDato()    inserisce un dato nel vettore corrispondente al tipo di unita di misura
     * @param dato      definisce il dato da caricare
     * @return bool      true se modificato con successo, false altrimenti
     */
    bool inserisciDato(Dato dato);
    /*
     * @brief modificaDato()    modifica un dato del vettore
     * @param data      definisce la data del dato da modificare
     * @param orario    definisce l'orario del dato da modificare
     * @param dato      definisce il dato da caricare
     * @return bool      true se modificato con successo, false altrimenti
     */
    bool modificaDato(Dato dato);
    /*
     * @brief ricercaDato()    ricerca un dato presente nel vettore
     * @param data      definisce la data del dato da ricercare
     * @param orario    definisce l'orario del dato da ricercare
     * @param UnitaMis    definisce l'unita di misura del dato da cercare
     * @return Dato     ritorna il dato trovato, altrimenti void
     */
    const Dato ricercaDato(const Date data, const Time orario, const std::string unitaMis);
    /*
     * @brief eliminaDato()    elimina un dato presente nel vettore
     * @param data      definisce la data del dato da eliminare
     * @param orario    definisce l'orario del dato da eliminare
     * @param UnitaMis    definisce l'unita di misura del dato da eliminare
     * @return bool      true se eliminato con successo, false altrimenti
     */
    bool eliminaDato(const Date data, const Time orario, const std::string unitaMis);
    /*
     * @brief cloneDati()    ritorna una copia del vettore
     */
    bool randomDati(std::string data);
    /*
     * @brief toString()    ritorna tutti i dati e sensori presenti in serra
     */
    std::string toString()const;
    /*
     * @brief setDescrizioneSensore()    aggiorna la descrizione di un sensore
     * @param unitaMis  definisce l'unita di misura del sensore
     * @param desc contiene la descrizione da aggiungere
     */
    bool setDescrizioneSensore(std::string unitaMis, std::string desc);
    /*
     * @brief getDescrizioneSensore()    ritorna una stringa con la descrizione di un sensore
     * @param unitaMis  definisce l'unita di misura del sensore
     */
    std::string getDescrizioneSensore(std::string unitaMis);
    /*
     * @brief Qualita() metodo che ritorna se l'ultimo valore registrato del sensore è buono(1), se è alto(2) e se è basso(0)
     */
    int Qualita(std::string unitaMis)const;
};

#endif // MODELLO_H
