#ifndef SERRA_H
#define SERRA_H

#include "sensori/sensore.h"
#include "sensori/Luminosita.h"
#include "sensori/Umidita.h"
#include "sensori/Temperatura.h"
#include "sensori/Dato.h"
#include "sensori/PHSuolo.h"
#include "sensori/Salinita.h"
#include <algorithm>
#include <typeindex>

class Serra
{
private:
    std::vector<Sensore* > sensori;
    //Temperatura  Celsius
    //Luminosita   Lumen
    //Umidita      g/m^3
    //PHSuolo      pH
    //Salinita     mmho/cm

public:
    /*
     * @brief Serra() costruttore della classe
     */
    Serra();
    /*
     * @brief rimuoviSensore() inserisce un oggetto di tipo Sensore
     * @param Sensore *s definisce un puntatore di un Sensore
     */
    bool inserisciSensori(Sensore *s);
    /*
     * @brief rimuoviSensore() elimina l'oggetto Sensore specificato
     * @param std::string s definisce l'unita di misura del sensore
     */
    void rimuoviSensore(const std::string s);
    /*
     * @brief cercaSensore() ritorna il puntatore ad un oggetto di tipo Sensore
     * @param std::string s definisce l'unita di misura del sensore
     */
    Sensore* cercaSensore( std::string s);
    /*
     * @brief inserisciDato() inserisce un dato nel vettore con la stessa unita di misura
     * @param dato dato da aggiungere
     */
    bool inserisciDato(const Dato dato);
    /*
     * @brief modificaDato() modifica un dato presente nel vettore con la stessa unita di misura
     * @param dato dato da aggiornare
     */
    bool modificaDato( const Dato dato);
    /*
     * @brief ricerca dato() cerca un Dato specifico
     * @param unitaMis per scegliere il sensore corretto
     * @param data e orario per capire quale dato
     */
    const Dato ricercaDato(const Date data, const Time orario, const std::string unitaMis);
    /*
     * @brief eliminaDato() cerca ed elimina un Dato specifico
     * @param unitaMis per scegliere il sensore corretto
     * @param data e orario per capire quale dato
     */
    bool eliminaDato(const Date data, const Time orario, const std::string unitaMis);
    /*
     * @brief clona() clona un vetttore di Dati specifico
     * @param unitaMis per scegliere il sensore corretto
     */
    const std::vector<Dato> clona(const std::string unitaMis);
    /*
     * @brief isEmpty() restituisce il sensore è vuoto o meno
     * @param unitaMis per scegliere il sensore corretto
     */
    bool isEmpty(const std::string unitaMis) const;
    /*
     * @brief ~Serra() distruttore della classe
     */
    ~Serra();
    /*
     * @brief toString() ritorna una stringa con tutti i dati e sensori della serra
     */
    std::string toString() const;
    /*
     * @brief setDescrizioneSensore() aggiorna la descrizione di un sensore
     * @param unitaMis contiene l'unita di misura per selezionare il sensore
     * @param desc contiene la descrizione da sostituire
     */
    bool setDescrizioneSensore(std::string unitaMis, std::string desc);
    /*
     * @brief getDescrizioneSensore() ritorna
     * @param unitaMis per sapere quale sensore scegliere
     */
    std::string getDescrizioneSensore(std::string unitaMis);
    /*
     * @brief Qualita() metodo che ritorna se l'ultimo valore registrato del sensore è buono(1), se è alto(2) e se è basso(0)
     */
    int Qualita(std::string unitaMis)const;
};

#endif // SERRA_H
