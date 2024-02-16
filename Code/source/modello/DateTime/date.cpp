#include "date.h"

int max (int a, int b)
{
    if (a>b) return(a) ; else return (b);
}

int min (int a, int b)
{
    if (a>b) return(b); else return (a);
}
// constructor definition
Date::Date ()
{
    month = day = year = 1;
}
Date::Date(const Date& other)
{
    month =other.getMonth();
    day =other.getDay();
    year =other.getYear();
}

// Funzione per la verifica della validità della data
bool Date::isValidDate(const int day,const int month,const int year) {
    if (year < 0 || month < 1 || month > 12 || day < 1||day>30)
        return false;
    return true;
}

Date::Date(int dy, int mh, int yr) {
    if (!isValidDate(dy, mh, yr)) {
        throw std::invalid_argument("Data non valida");
    }

    day = dy;
    month = mh;
    year = yr;
}


int Date::getMonth()const{
    return month;
}
int Date::getYear()const{
    return year;
}
int Date::getDay()const{
    return day;
}

std::string Date::toString()const{
    std::stringstream ss;
    ss << std::setw(2) << std::setfill('0') << day << "/"
       << std::setw(2) << std::setfill('0') << month << "/"
       << std::setw(2) << std::setfill('0') << year;
    return ss.str();
}
bool Date::operator==(const Date &other) const {
    if(year==other.getYear()&&month==other.getMonth()&&day==other.getDay())
        return true;
    return false;
}
Date Date::convertFromString(const std::string& dateString) {
    Date convertedDate;

    // Utilizzare sscanf per estrarre giorno, mese e anno dalla stringa
    if (std::sscanf(dateString.c_str(), "%d/%d/%d", &convertedDate.day, &convertedDate.month, &convertedDate.year) != 3) {
        throw std::invalid_argument("Formato della stringa non valido");
    }
    if (!isValidDate(convertedDate.day,convertedDate.month,convertedDate.year)){
        throw std::invalid_argument("Data non valida");
    }

    return convertedDate;
}

Date& Date::operator=(const Date& other) const {
    if (this != &other) {
        // Copia i dati da 'other' a 'this'
        const_cast<Date*>(this)->year = other.year;
        const_cast<Date*>(this)->month = other.month;
        const_cast<Date*>(this)->day = other.day;
    }
    return *const_cast<Date*>(this);
}

