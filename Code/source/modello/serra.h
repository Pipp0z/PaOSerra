#ifndef SERRA_H
#define SERRA_H

#include "sensori/Luminosita.h"
#include "sensori/Umidita.h"
#include "sensori/Temperatura.h"
#include "sensori/Dato.h"
#include "sensori/PHSuolo.h"
#include "sensori/Salinita.h"
class Serra
{
private:
    Temperatura temper; // Celsius
    Luminosita lumen; // Lumen
    Umidita umidita; // g/m^3
    PHSuolo PHSuolo; //pH
    Salinita salinita; //mmho/cm(media 0.75)

public:
    Serra();
    bool inserisciDato(const Dato dato);
    bool modificaDato( const Dato dato);
    const Dato ricercaDato(const Date data, const Time orario, const std::string unitaMis);
    bool eliminaDato(const Date data, const Time orario, const std::string unitaMis);
    const std::vector<Dato> clona(const std::string unitaMis);
    bool isEmpty(const std::string unitaMis) const;
    virtual ~Serra() =default;

};

#endif // SERRA_H
