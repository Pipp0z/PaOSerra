#include "Temperatura.h"
std::string sostituisciParola(std::string testo, const std::string parolaDaCercare, const std::string nuovaParola) {
    size_t pos = 0;

    // Continua a cercare e sostituire finché la parola viene trovata
    while ((pos = testo.find(parolaDaCercare, pos)) != std::string::npos) {
        testo.replace(pos, parolaDaCercare.length(), nuovaParola);
        pos += nuovaParola.length();  // Imposta la posizione di partenza per la successiva ricerca
    }
    return testo;
}

bool Temperatura::faraday(false);
std::string static viewDato(Dato d){
    if(!Temperatura::getStato()){
    d.setMisurazione((d.getMisurazione()* 9/5) + 32);
    return sostituisciParola(d.toString() , "Celsius", "Faraday");
    }else{
        return d.toString();
    }
}
Temperatura::Temperatura(){}


bool Temperatura::changeStato() {
    if(faraday)
        faraday=false;
    else
        faraday=true;
    return true;
}
bool Temperatura::getStato(){
    return faraday;
}

std::string Temperatura::toString() const{
    std::string s="[Temperatura: \n";
    if(!Temperatura::getStato()){
           s+=toStringSensore();
    }else{
        std::vector<Dato> temp = clonaDati();
        for (size_t i = 0; i < temp.size(); ++i) {
            temp[i].setMisurazione((temp[i].getMisurazione()* 9/5) + 32);
            s+=sostituisciParola(temp[i].toString() , "Celsius", "Faraday");

        }
    }
    s+="] \n";
    return s;
}
