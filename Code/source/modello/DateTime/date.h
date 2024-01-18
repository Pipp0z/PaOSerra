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
    Date();
    Date(const Date& other);
    Date ( int dy, int mh, int yr);  // constructor
        // function to display date
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


#endif // DATE_H
