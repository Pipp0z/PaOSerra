#pragma once

#include <iomanip>
#include <string>
#include <stdexcept>
#include <sstream>

class Time {
private:
    int seconds;
public:
    Time();
    Time(const Time &other);
    Time(int sec);
    // Funzione per la verifica della validità del tempo
    static bool isValidTime(int seconds);
    int getSecondi() const;
    int getMinuti() const;
    int getOre() const;
    int getSeconds() const;
    std::string toString() const;
    bool operator==(const Time &other) const;
    static int convertFromString(const std::string& timeString);
    ~Time() = default;
    Time& operator=(const Time& other) const;
};