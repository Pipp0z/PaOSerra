#pragma once

#include "../DateTime/Date.h"
#include "../DateTime/Time.h"

class Dato {
private:
    const Date data;
    const Time orario;
    double misurazione;
    const std::string unitaMisura;

public:
    Dato(std::string unitaMis, double misura,Date data,Time orario);
    Dato(const Dato &other);
    Date getData() const;
    Time getOrario() const;
    bool setMisurazione(double misura);
    double getMisurazione() const ;
    std::string getUnitaMisura()const;
    std::string toString() const;
    Dato cloneDato() const;
    ~Dato() =default;
    void operator=(const Dato& other);
    bool operator==(const Dato& other) const;
};