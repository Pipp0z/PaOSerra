#include "modello.h"

modello::modello() {}
bool modello::saveInfo(const std::string &nomeFile){


    bool check=false;
    std::ofstream file(nomeFile);
    if (!file.is_open()) {
        std::cerr << "Errore nell'apertura del file per la scrittura: " << nomeFile << std::endl;
        return false;
    }

    json jsonDati;

    std::string tipoDato="Luminosita";

    json stato={{"Stato",Luminosita::getIntensita()}};
    jsonDati[tipoDato].push_back(stato);
    if(!serra.isEmpty("Lumen")){
    jsonDati[tipoDato] = json::array();
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

    stato={{"Stato",Temperatura::getStato()}};
    jsonDati[tipoDato].push_back(stato);
    if(!serra.isEmpty("Celsius")){
        jsonDati[tipoDato] = json::array();
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

    stato={{"Stato",Umidita::getAcceso()}};
    jsonDati[tipoDato].push_back(stato);
    if(!serra.isEmpty("g/m^3")){
        jsonDati[tipoDato] = json::array();
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

    stato={{"Stato",PHSuolo::getTipoSuolo()}};
    jsonDati[tipoDato].push_back(stato);
    if(!serra.isEmpty("pH")){
        jsonDati[tipoDato] = json::array();
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

    stato={{"Stato",Salinita::getSalinita()}};
    jsonDati[tipoDato].push_back(stato);
    if(!serra.isEmpty("mmho/cm")){
        jsonDati[tipoDato] = json::array();
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




        check=true;

    return check;
}


bool modello::loadInfo(const std::string& nomeFile){
bool check=false;
    std::ifstream file(nomeFile);
    if (!file.is_open()) {
        std::cerr << "Errore nell'apertura del file per la lettura: " << nomeFile << std::endl;
        return false;
    }

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
