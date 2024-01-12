#ifndef DATO_H
#define DATO_H

#include <QDate>
#include <QTime>
#include <QString>
class Dato
{
private:

    const QDate data;
    const QTime orario;
    double misurazione; //precisione a un numero dopo la virgola
    const QString unitaMisura;

public:
    Dato(QString unitaMis, double misura,QDate data,QTime orario);
    Dato(QString unitaMis);
    /*
     * @brief Dato    costruttore per la classe Dato
     * @param misurazione      definisce il valore calcolato dal sensore
     * @param data      definisce la data di quando è stato calcolato il dato
     * @param orario      definisce l'orario di quando è stato calcolato il dato
     */
     Dato(QString unitaMis, double misura);
    /*
     * @brief getData       la funzione restituisce la data della misurazione
     * @return QDate        ritorna la data
     */
     QDate getData() const;
     /*
     * @brief getOrario       la funzione restituisce la data della misurazione
     * @return QTime        ritorna l'orario
     */
     QTime getOrario() const;
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
     QString getUnitaMisura()const;
     /*
     * @brief toString      la funzione restituisce la stampa di tutti gli attributi della classe
     * @return Qstring        ritorna una stringa
     */
      Dato cloneDato() const;
     /*
     * @param ~Dato() distruttore per la classe Dato
     */
     virtual ~Dato() =default;


     bool operator==(const Dato& other) const;


};
#endif // DATO_H
