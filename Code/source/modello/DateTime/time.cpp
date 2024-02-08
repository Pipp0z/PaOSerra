#include "time.h"
#include <sstream>

Time::Time() {
    seconds=0;
}
Time::Time(int sec) {
    if (sec < 0) {
        throw std::invalid_argument("Orario non valido");
    }

    seconds = sec%(86400);
}
Time::Time(const Time& other) {
    seconds=other.getSeconds();
}
// Funzione per la verifica della validità del tempo
bool Time::isValidTime(int seconds) {
    return (seconds >= 0 && seconds < 86400);  // 24 ore * 60 minuti * 60 secondi
}

// Funzioni di accesso ai membri privati
int Time::getSecondi() const  {
    return (seconds%60);
}
int Time::getMinuti() const  {
    return (seconds%3600)/60;
}
int Time::getOre() const  {
    return (seconds/3600);
}
int Time::getSeconds() const{
    return seconds;
}

// Funzione per la rappresentazione del tempo come stringa
std::string Time::toString() const {
    int ore = seconds / 3600;
    int minuti = (seconds % 3600) / 60;
    int sec = seconds % 60;

    // Utilizzare std::setw e std::setfill per formattare correttamente i numeri con zeri a sinistra
    std::stringstream ss;
    ss << std::setw(2) << std::setfill('0') << ore << ":"
       << std::setw(2) << std::setfill('0') << minuti << ":"
       << std::setw(2) << std::setfill('0') << sec;

    return ss.str();
}
bool Time::operator==(const Time &other) const {
    if(seconds==other.getSeconds())
        return true;
    return false;
}
int Time::convertFromString(const std::string& timeString) {
    int ore, minuti, sec;


    // Utilizzare sscanf per estrarre ore, minuti e secondi dalla stringa
    if (std::sscanf(timeString.c_str(), "%d:%d:%d", &ore, &minuti, &sec) != 3) {
        throw std::invalid_argument("Formato della stringa non valido");
    }

    // Calcolare il totale dei secondi
    return ore * 3600 + minuti * 60 + sec;
}
Time& Time::operator=(const Time& other) const {
    if (this != &other) {
        // Copia i dati da 'other' a 'this'
        const_cast<Time*>(this)->seconds = other.seconds;
    }
    return *const_cast<Time*>(this);
}

