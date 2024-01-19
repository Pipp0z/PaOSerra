#ifndef DATE_H
#define DATE_H
#include <stdexcept>
#include <sstream>
#include <string>


class Date
{
private:
    int month, day, year;
    //usiamo il calendario commerciale, tutti i mesi da 30 giorni

public:
    /*
     * @brief Date() costruttore di Date
     */
    Date();
    /*
     *@brief Date() costruttore di copia di Date
     *@param other oggetto di tipo Date da copiare
     */
    Date(const Date& other);
    /*
     * @brief Date() costruttore di Date
     * @param dy usato per i giorni
     * @param mh usato per i mesi
     * @param yr usato per gli anni
     */
    Date ( int dy, int mh, int yr);
    /*
     * @brief isValidDate() ritorna true se la data è valida(Calendario di 30giorni)
     * @param day usato per i giorni
     * @param mounth usato per i mesi
     * @param year usato per gli anni
     */
    static bool isValidDate(const int day, const int month, const int year);
    /*
     * @brief getMonth() ritorna month
     */
    int getMonth()const;
    /*
     * @brief getYear() ritorna year
     */
    int getYear()const;
    /*
     * @brief getDay() ritorna day;
     */
    int getDay()const;
    /*
     * @brief toString() ritorna la data formattata così: giorno/mese/anno
     */
    std::string toString()const;
    /*
     * @brief operator==() operatore per confrontare due Date
     * @param other oggetto Date da comparare
     */
    bool operator==(const Date& other) const;
    /*
     * @brief ~Date() distruttore per la classe Date
     */
    ~Date() = default;
    /*
     * @brief convertFromString() ritorna un tipo Date partendo da una stringa
     * @param dateString oggetto con formattato giorno/mese/anno
     */
    static Date convertFromString(const std::string& dateString);
    /*
     * @brief operator=() operatore per acquisire i dati di un altro oggetto
     * @param other oggetto da cui prendere i dati
     */
    Date& operator=(const Date& other)const;
};


#endif // DATE_H
