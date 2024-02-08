#include "Modello.h"



Modello::Modello(){
    Serra();
}
bool Modello::saveInfo(const std::string &nomeFile){


    bool check=false;
    std::ofstream file(nomeFile);
    if (!file.is_open()) {
        return false;
    }

    json jsonDati;

    std::string tipoDato="Luminosita";


    jsonDati[tipoDato] = json::array();

    if(!serra.isEmpty("Lumen")){
    json stato={
        {"Stato",Luminosita::getIntensita()},
        {"Descrizione",serra.getDescrizioneSensore("Lumen")}
        };
    jsonDati[tipoDato].push_back(stato);
    std::vector<Dato> const temp=serra.clona("Lumen");
    for (const auto& dato : temp) {
        json jsonDato = {
            {"data", dato.getData().toString()},
            {"orario", dato.getOrario().toString()},
            {"unitaMisura", dato.getUnitaMisura()},
            {"misura", dato.getMisurazione()}
        };

        jsonDati[tipoDato].push_back(jsonDato);
    }
    }


    tipoDato="Temperatura";

    if(!serra.isEmpty("Celsius")){
        json stato={
            {"Stato",Temperatura::getStato()},
            {"Descrizione",serra.getDescrizioneSensore("Celsius")}
        };
        jsonDati[tipoDato].push_back(stato);
        std::vector<Dato> const temp=serra.clona("Celsius");
        for (const auto& dato : temp) {
            json jsonDato = {
                {"data", dato.getData().toString()},
                {"orario", dato.getOrario().toString()},
                {"unitaMisura", dato.getUnitaMisura()},
                {"misura", dato.getMisurazione()}
            };

            jsonDati[tipoDato].push_back(jsonDato);
        }
    }


    tipoDato="Umidita";


    if(!serra.isEmpty("g/m^3")){
        json stato={
            {"Stato",Umidita::getAcceso()},
            {"Descrizione",serra.getDescrizioneSensore("g/m^3")}
        };
        jsonDati[tipoDato].push_back(stato);
        std::vector<Dato> const temp=serra.clona("g/m^3");
        for (const auto& dato : temp) {
            json jsonDato = {
                {"data", dato.getData().toString()},
                {"orario", dato.getOrario().toString()},
                {"unitaMisura", dato.getUnitaMisura()},
                {"misura", dato.getMisurazione()}
            };

            jsonDati[tipoDato].push_back(jsonDato);
        }
    }

    tipoDato="PHSuolo";


    if(!serra.isEmpty("pH")){
        json stato={
            {"Stato",PHSuolo::getTipoSuolo()},
            {"Descrizione",serra.getDescrizioneSensore("pH")}
        };
        jsonDati[tipoDato].push_back(stato);
        std::vector<Dato> const temp=serra.clona("pH");
        for (const auto& dato : temp) {
            json jsonDato = {
                {"data", dato.getData().toString()},
                {"orario", dato.getOrario().toString()},
                {"unitaMisura", dato.getUnitaMisura()},
                {"misura", dato.getMisurazione()}
            };

            jsonDati[tipoDato].push_back(jsonDato);
        }
    }

    tipoDato="Salinita";


    if(!serra.isEmpty("mmho/cm")){
        json stato={
            {"Stato",Salinita::getSalinita()},
            {"Descrizione",serra.getDescrizioneSensore("mmho/cm")}
        };
        jsonDati[tipoDato].push_back(stato);
        std::vector<Dato> const temp=serra.clona("mmho/cm");
        for (const auto& dato : temp) {
            json jsonDato = {
                {"data", dato.getData().toString()},
                {"orario", dato.getOrario().toString()},
                {"unitaMisura", dato.getUnitaMisura()},
                {"misura", dato.getMisurazione()}
            };

            jsonDati[tipoDato].push_back(jsonDato);
        }
    }



    file << jsonDati.dump(2);
        check=true;

    return check;
}


bool Modello::loadInfo(const std::string& nomeFile){

bool check=false;
    std::ifstream file(nomeFile);
    if (!file.is_open()) {

        return false;
    }

    serra.rimuoviSensore("Lumen");
    serra.rimuoviSensore("g/m^3");
    serra.rimuoviSensore("pH");
    serra.rimuoviSensore("Celsius");
    serra.rimuoviSensore("mmho/cm");

    serra.inserisciSensori(new Luminosita);
    serra.inserisciSensori(new Umidita);
    serra.inserisciSensori(new PHSuolo);
    serra.inserisciSensori(new Temperatura);
    serra.inserisciSensori(new Salinita);
    json jsonDati;
    file >> jsonDati;

    std::string tipoDato="Luminosita";
    bool er=false;

    for (const auto& jsonDato : jsonDati[tipoDato]) {
        if(er){
            Dato dato = {
                jsonDato["unitaMisura"].get<std::string>(),
                jsonDato["misura"].get<double>(),
                Date::convertFromString(jsonDato["data"]),
                Time::convertFromString(jsonDato["orario"])
            };
            serra.inserisciDato(dato);
        }else{
            serra.setDescrizioneSensore("Lumen",jsonDato["Descrizione"]);
            while(Luminosita::getIntensita()!=jsonDato["Stato"].get<int>()){
                if(Luminosita::getIntensita()>jsonDato["Stato"].get<int>()){
                    Luminosita::diminuisciIntensita();
                }else{
                    Luminosita::aumentaIntensita();
                }
            }
            er=true;

        }
    }
    tipoDato="Temperatura";
     er=false;

    for (const auto& jsonDato : jsonDati[tipoDato]) {
        if(er){
            Dato dato = {
                jsonDato["unitaMisura"].get<std::string>(),
                jsonDato["misura"].get<double>(),
                Date::convertFromString(jsonDato["data"]),
                Time::convertFromString(jsonDato["orario"])
            };
            serra.inserisciDato(dato);
        }else{
            serra.setDescrizioneSensore("Celsius",jsonDato["Descrizione"]);
            if(Temperatura::getStato()!=jsonDato["Stato"].get<bool>()){
                Temperatura::changeStato();
            }
            er=true;

        }
    }

    tipoDato="Umidita";
    er=false;

    for (const auto& jsonDato : jsonDati[tipoDato]) {
        if(er){
            Dato dato = {
                jsonDato["unitaMisura"].get<std::string>(),
                jsonDato["misura"].get<double>(),
                Date::convertFromString(jsonDato["data"]),
                Time::convertFromString(jsonDato["orario"])
            };
            serra.inserisciDato(dato);
        }else{
            serra.setDescrizioneSensore("g/m^3",jsonDato["Descrizione"]);
            if(Umidita::getAcceso()!=jsonDato["Stato"].get<bool>()){
                Umidita::changeStato();
            }
            er=true;

        }
    }

    tipoDato="PHSuolo";
    er=false;

    for (const auto& jsonDato : jsonDati[tipoDato]) {
        if(er){
            Dato dato = {
                jsonDato["unitaMisura"].get<std::string>(),
                jsonDato["misura"].get<double>(),
                Date::convertFromString(jsonDato["data"]),
                Time::convertFromString(jsonDato["orario"])
            };
            serra.inserisciDato(dato);
        }else{
            serra.setDescrizioneSensore("pH",jsonDato["Descrizione"]);
            if(PHSuolo::getTipoSuolo()!=jsonDato["Stato"]){
                PHSuolo::changeStato(jsonDato["Stato"].get<std::string>());
            }
            er=true;

        }
    }

    tipoDato="Salinita";
    er=false;

    for (const auto& jsonDato : jsonDati[tipoDato]) {
        if(er){
            Dato dato = {
                jsonDato["unitaMisura"].get<std::string>(),
                jsonDato["misura"].get<double>(),
                Date::convertFromString(jsonDato["data"]),
                Time::convertFromString(jsonDato["orario"])
            };
            serra.inserisciDato(dato);
        }else{
            serra.setDescrizioneSensore("mmho/cm",jsonDato["Descrizione"]);
            while(Salinita::getSalinita()!=jsonDato["Stato"].get<int>()){
                if(Salinita::getSalinita()>jsonDato["Stato"].get<int>()){
                    Salinita::diminuisciSalinita();
                }else{
                    Salinita::aumentaSalinita();
                }
            }
            er=true;

        }
    }
    check=true;
    return check;
}

bool Modello::randomDati(std::string data){
    serra.inserisciSensori(new Luminosita);
    serra.inserisciSensori(new Umidita);
    serra.inserisciSensori(new PHSuolo);
    serra.inserisciSensori(new Temperatura);
    serra.inserisciSensori(new Salinita);

    std::random_device rd;
    std::mt19937 gen(rd());
    const std::vector<std::string> unitaMisure = {"Lumen", "Celsius", "g/m^3", "pH", "mmho/cm"};
    std::uniform_real_distribution<> misuraDist(0.0, 100.0);
     std::uniform_int_distribution<> unitaDist(0, unitaMisure.size() - 1);


    std::uniform_int_distribution<> orarioMinutiDist(0, 59);
    std::uniform_int_distribution<> orarioSecondiDist(0, 59);
    int orario = orarioMinutiDist(gen)*60 + orarioSecondiDist(gen);


    for(int i=0;i<23;++i){
        Time time(orario+(i*3600));
        std::string unitaMisura = unitaMisure[unitaDist(gen)];
        double misura = misuraDist(gen);
        Dato d(unitaMisura,misura, Date::convertFromString(data),time);

        serra.inserisciDato(d);
    }
    return true;
}
std::string Modello::toString()const{
    return serra.toString();
}
bool Modello::inserisciDato(Dato dato){
    return serra.inserisciDato(dato);
}
bool Modello::modificaDato(Dato dato){
    return serra.modificaDato(dato);
}
const Dato Modello::ricercaDato(const Date data, const Time orario, const std::string unitaMis) {
    return serra.ricercaDato(data, orario, unitaMis);
}
bool Modello::eliminaDato(const Date data, const Time orario, const std::string unitaMis){
    return serra.eliminaDato(data, orario, unitaMis);
}
bool Modello::setDescrizioneSensore(std::string unitaMis, std::string desc){
    return serra.setDescrizioneSensore(unitaMis, desc);
}
std::string Modello::getDescrizioneSensore(std::string unitaMis){
    return serra.getDescrizioneSensore(unitaMis);
}

int Modello::Qualita(std::string unitaMis)const{
    return serra.Qualita(unitaMis);
}
