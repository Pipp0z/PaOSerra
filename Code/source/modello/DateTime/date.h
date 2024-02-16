#pragma once

#include <stdexcept>
#include <sstream>
#include <string>
#include <iomanip>

class Date {
private:
    // si usa il calendario commerciale, tutti i mesi da 30 giorni
    int month, day, year;

public:
    Date();
    Date(const Date& other);
    Date ( int dy, int mh, int yr);
    // ritorna true se la data è valida(Calendario di 30giorni)
    static bool isValidDate(const int day, const int month, const int year);
    int getMonth()const;
    int getYear()const;
    int getDay()const;
    std::string toString()const;
    bool operator==(const Date& other) const;
    ~Date() = default;
    static Date convertFromString(const std::string& dateString);
    Date& operator=(const Date& other)const;
};
