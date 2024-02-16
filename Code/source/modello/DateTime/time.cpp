#include "Time.h"

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
    seconds = other.getSeconds();
}

bool Time::isValidTime(int seconds) {
    return (seconds >= 0 && seconds < 86400);
}

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

    return ore * 3600 + minuti * 60 + sec;
}

Time& Time::operator=(const Time& other) const {
    if (this != &other) {
        const_cast<Time*>(this)->seconds = other.seconds;
    }

    return *const_cast<Time*>(this);
}