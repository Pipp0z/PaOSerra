#include "controller.h"

#include "../view/view.h"
#include "../view/VisualizzaSensori.h"


bool Controller::m_luminositaCreated=false;
bool Controller::m_umiditaCreated=false;
bool Controller::m_salinitaCreated=false;
bool Controller::m_temperaturaCreated=false;
bool Controller::m_phSuoloCreated=false;
Modello Controller::model;

Controller::Controller(View *view, QObject *parent) : QObject(parent), m_view(view) {



    connect(m_view, &View::creaSensoreRequested, this, &Controller::toggleSensore);
    connect(m_view, &View::rimuoviSensoreRequested, this, &Controller::toggleSensore);


    connect(m_view, &View::caricaRequested, this, &Controller::onCaricaClicked);
    connect(m_view, &View::salvaRequested, this, &Controller::onSalvaClicked);
    connect(m_view, &View::datiRandomRequested, this, &Controller::onDatiRandomClicked);



}

Controller::Controller( QObject *parent) : QObject(parent){}

void Controller::toggleSensore(QString tipoSensore) {
    std::string s= tipoSensore.toStdString();
    if(tipoSensore=="Lumen"){
    if (m_luminositaCreated) {
        m_luminositaCreated = false;
        model.rimuoviSensore(s);
        m_view->setLuminositaCreated(false);
    } else {
        m_luminositaCreated = true;
        model.inserisciSensori(new Luminosita);
        m_view->setLuminositaCreated(true);
    }
    }else if(tipoSensore=="g/m^3"){
        if (m_umiditaCreated) {
            m_umiditaCreated = false;
            model.rimuoviSensore(s);
            m_view->setUmiditaCreated(false);
        } else {
            m_umiditaCreated = true;
            model.inserisciSensori(new Umidita);
            m_view->setUmiditaCreated(true);
        }
    }else if(tipoSensore=="mmho/cm"){
        if (m_salinitaCreated) {
            m_salinitaCreated = false;
            model.rimuoviSensore(s);
            m_view->setSalinitaCreated(false);
        } else {
            m_salinitaCreated = true;
            model.inserisciSensori(new Salinita);
            m_view->setSalinitaCreated(true);
        }
    }else if(tipoSensore=="Celsius"){
        if (m_temperaturaCreated) {
            m_temperaturaCreated = false;
            model.rimuoviSensore(s);
            m_view->setTemperaturaCreated(false);
        } else {
            m_temperaturaCreated = true;
            model.inserisciSensori(new Temperatura);
            m_view->setTemperaturaCreated(true);
        }
    }else if(tipoSensore=="pH"){
        if (m_phSuoloCreated) {
            m_phSuoloCreated = false;
            model.rimuoviSensore(s);
            m_view->setPhSuoloCreated(false);
        } else {
            m_phSuoloCreated = true;
            model.inserisciSensori(new PHSuolo);
            m_view->setPhSuoloCreated(true);
        }
    }
}
bool Controller::verificaDisponibilitaSensore(QString tipoSensore){
    if(tipoSensore=="Lumen"){
        return m_luminositaCreated;

    }else if(tipoSensore=="g/m^3"){
        return m_umiditaCreated;

    }else if(tipoSensore=="mmho/cm"){
        return m_salinitaCreated;
    }else if(tipoSensore=="Celsius"){
        return m_temperaturaCreated;
    }else if(tipoSensore=="pH"){
        return m_phSuoloCreated;
    }
    return false;
}

bool Controller::handleInserisciDato(double valore, int giorno, int mese, int anno, QTime ora, QString tipo)
{
    Date data(giorno,mese, anno);
    Time orario(ora.msecsSinceStartOfDay()/1000);
    Dato d(tipo.toStdString(),valore,data,orario);
    model.inserisciDato(d);
    return true;
}

bool Controller::handleRimuoviDato(const std::string orario,const std::string data, std::string tipo)
{
    model.eliminaDato(Date::convertFromString(data),Time::convertFromString(orario), tipo);
    return true;
}
QVector<Dato> Controller::richiediDati(const QString tipo){
    std::vector temp=model.visualizzaDati(tipo.toStdString());
    QVector<Dato> d(temp.begin(), temp.end());
    return d;
}

bool Controller::handleModificaDato(std::string orario, std::string data, double nuovoValore, std::string tipo)
{
    Dato d(tipo,nuovoValore,Date::convertFromString(data),Time::convertFromString(orario));
    model.modificaDato(d);
    return true;
}



void Controller::onCaricaClicked() {

    model.loadInfo("Dati.json");
    if(!model.isEmpty("Lumen")){
        m_luminositaCreated=true;
    m_view->setLuminositaCreated(true);
    }
    if(!model.isEmpty("g/m^3")){
        m_umiditaCreated=true;
        m_view->setUmiditaCreated(true);
    }
    if(!model.isEmpty("mmho/cm")){
        m_salinitaCreated=true;
        m_view->setSalinitaCreated(true);
    }
    if(!model.isEmpty("Celsius")){
        m_temperaturaCreated=true;
        m_view->setTemperaturaCreated(true);
    }
    if(!model.isEmpty("pH")){
        m_phSuoloCreated=true;
        m_view->setPhSuoloCreated(true);
    }

}

void Controller::onSalvaClicked() {
    model.saveInfo("Dati.json");

}

void Controller::onDatiRandomClicked() {
    QDate currentDate = QDate::currentDate();
    QString dateString = currentDate.toString("dd/MM/yyyy");
    model.randomDati(dateString.toStdString());
    m_luminositaCreated=true;
    m_view->setLuminositaCreated(true);
    m_umiditaCreated=true;
    m_view->setUmiditaCreated(true);
    m_salinitaCreated=true;
    m_view->setSalinitaCreated(true);
    m_temperaturaCreated=true;
    m_view->setTemperaturaCreated(true);
    m_phSuoloCreated=true;
    m_view->setPhSuoloCreated(true);

}

QVector<Dato> Controller::richiediDatiGrafico(QString tipo){
    std::vector<Dato> d=model.visualizzaDati(tipo.toStdString());
    QVector<Dato> dati(d.begin(),d.end());
    return dati;
}

void Controller::setDescrizioneSensore(QString tipo,QString nuovaDescrizione){
    model.setDescrizioneSensore(tipo.toStdString(), nuovaDescrizione.toStdString());
}
QString Controller::getDescrizioneSensore(QString tipo){
    return QString::fromStdString(model.getDescrizioneSensore(tipo.toStdString()));
}

int Controller::qualita(QString tipoMisura){
    return model.Qualita(tipoMisura.toStdString());
}
