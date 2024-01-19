#ifndef DATO_H
#define DATO_H

#include "../DateTime/date.h"
#include "../DateTime/time.h"


class Dato
{
private:

    const Date data;
    const Time orario;
    double misurazione;
    const std::string unitaMisura;

public:
    /*
     * @brief Dato    costruttore per la classe Dato
     * @param UnitaMisura      definisce il tipo di unita di Misura del Dato
     * @param misurazione      definisce il valore calcolato dal sensore
     * @param data      definisce la data di quando è stato calcolato il Dato
     * @param orario      definisce l'orario di quando è stato calcolato il Dato
     */
    Dato(std::string unitaMis, double misura,Date data,Time orario);
    /*
     * @brief Dato    costruttore di Copia per la classe Dato
     * @param other   è il Dato che si vuole assumere
     */
    Dato(const Dato &other);
    /*
     * @brief getData       la funzione restituisce la data della misurazione
     * @return Date        ritorna la data
     */
     Date getData() const;
     /*
     * @brief getOrario       la funzione restituisce la data della misurazione
     * @return Time        ritorna l'orario
     */
     Time getOrario() const;
     /*
     * @brief setMisurazione      la funzione aggiorna la misurazione
     * @param misurazione      definisce il valore calcolato dal sensore
     * @return bool        ritorna true se l'operazione è andata a buon fine, false altrimenti
     */
     bool setMisurazione(double misura);
     /*
     * @brief getMisurazione      la funzione restituisce la misurazione effettuata
     * @return duoble        ritorna il dato
     */
     double getMisurazione() const ;
     /*
     * @brief getUnitaMisura()    ritorna l'unità di misura del dato
     */
     std::string getUnitaMisura()const;
     /*
     * @brief toString      la funzione restituisce la stampa di tutti gli attributi della classe
     * @return std::string        ritorna una stringa
     */
     std::string toString() const;
     /*
     * @brief cloneDato      la funzione crea il clone di se stesso
     * @return Dato       ritorna un Dato
     */
      Dato cloneDato() const;
     /*
     * @brief ~Dato() distruttore per la classe Dato
     */
     ~Dato() =default;
      /*
     * @brief operator=      la funzione assegna a Dato la misurazione di other
     */
     void operator=(const Dato& other);
     /*
     * @brief operator==      la funzione verifica se il nostro dato è uguale a other
     * @return bool        ritorna un true se vero, false altrimenti
     */
     bool operator==(const Dato& other) const;


};
#endif // DATO_H
