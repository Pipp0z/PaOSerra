#ifndef TIME_H
#define TIME_H
#include <iomanip>
#include <string>
#include <stdexcept>


class Time
{
private:
    int seconds;
public:
    /*
     * @brief Time    costruttore per la classe Time
     */
Time();
    /*
     * @brief Time    costruttore di Copia per la classe Time
     * @param other   sono i dati che si vogliono assumere
     */
Time(const Time &other);
    /*
     * @brief Time    costruttore per la classe Time
     * @param sec   sono i sec che si vogliono assumere
     */
Time(int sec);
    /*
     * @brief isValidTime    Funzione per la verifica della validità del tempo
     * @param seconds   sono i sec che si vogliono verificare
     */
static bool isValidTime(int seconds);
    /*
     * @brief getSecondi    ritorna solo i secondi dell'orario
     */
int getSecondi() const ;
    /*
     * @brief getMinuti    ritorna solo i minuti dell'orario
     */
int getMinuti() const ;
    /*
     * @brief getOre    ritorna solo le ore dell'orario
     */
int getOre() const ;
    /*
     * @brief getSeconds    ritorna tutti i secondi
     */
int getSeconds() const;

    /*
     * @brief toString    ritorna una stringa formattata: ore:minuti:secondi
     */
std::string toString() const ;
    /*
     * @brief operator==    ritorna true se i secondi sono uguali all'altro oggetto
     * @param other oggetto da comparare
     */
bool operator==(const Time &other) const ;
    /*
     * @brief convertFromString    ritorna i secondi presenti in una stringa formattata: ore:minuti:secondi
     * @param timeString stringa con l'eventuale data
     */
static int convertFromString(const std::string& timeString);
    /*
     * @brief ~Time() distruttore per la classe Time
     */
~Time() = default;
/*
     * @brief operator=    aggiorna gli attributi dell'oggetto
     * @param other oggetto con i dati da assimilare
     */
Time& operator=(const Time& other) const;

};
#endif // TIME_H
