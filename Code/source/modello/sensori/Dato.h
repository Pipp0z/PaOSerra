#ifndef DATO_H
#define DATO_H

#include "../DateTime/date.h"
#include "../DateTime/time.h"


class Dato
{
private:

    const Date data;
    const Time orario;
    double misurazione; //precisione a un numero dopo la virgola
    const std::string unitaMisura;

public:
    Dato(std::string unitaMis, double misura,Date data,Time orario);
    Dato(std::string unitaMis);
    /*
     * @brief Dato    costruttore per la classe Dato
     * @param misurazione      definisce il valore calcolato dal sensore
     * @param data      definisce la data di quando è stato calcolato il dato
     * @param orario      definisce l'orario di quando è stato calcolato il dato
     */
     Dato(std::string unitaMis, double misura);
    /*
     * @brief getData       la funzione restituisce la data della misurazione
     * @return QDate        ritorna la data
     */
     Date getData() const;
     /*
     * @brief getOrario       la funzione restituisce la data della misurazione
     * @return QTime        ritorna l'orario
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
     * @return Qstring        ritorna una stringa
     */
      Dato cloneDato() const;
     /*
     * @param ~Dato() distruttore per la classe Dato
     */
     virtual ~Dato() =default;

     void operator=(const Dato& other);

     bool operator==(const Dato& other) const;


};
#endif // DATO_H
