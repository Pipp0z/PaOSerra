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
Time();
Time(const Time &other);
Time(int sec);
// Funzione per la verifica della validità del tempo
static bool isValidTime(int seconds);

// Funzioni di accesso ai membri privati
int getSecondi() const ;
int getMinuti() const ;
int getOre() const ;
int getSeconds() const;

// Funzione per la rappresentazione del tempo come stringa
std::string toString() const ;
bool operator==(const Time &other) const ;
static int convertFromString(const std::string& timeString);
~Time() = default;
Time& operator=(const Time& other) const;

};
#endif // TIME_H
