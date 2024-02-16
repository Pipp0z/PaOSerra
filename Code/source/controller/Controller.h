#pragma once

#include <QObject>
#include <QMessageBox>
#include <QDebug>
#include <QChart>
#include "../modello/Modello.h"
#include <QTime>

class View;
class VisualizzaSensori;

class Controller : public QObject {
    Q_OBJECT
public:
    explicit Controller(View *view, QObject *parent = nullptr);
    explicit Controller( QObject *parent = nullptr);
public slots:
    bool handleInserisciDato(double valore, int giorno,int mese,int anno,QTime ora, QString tipo );
    bool handleRimuoviDato(const std::string orario, const std::string data,std::string tipo);
    bool handleModificaDato(std::string orario, std::string data, double nuovoValore, std::string tipo);
    QVector<Dato> richiediDati(const QString tipo);
    QVector<Dato> richiediDatiGrafico(QString tipo);
    void setDescrizioneSensore(QString tipo,QString nuovaDescrizione);
    QString getDescrizioneSensore(QString tipo);
    int qualita(QString tipoMisura);
    bool verificaDisponibilitaSensore(QString scelta);

private slots:
    void toggleSensore(QString tipoSensore);
    void onCaricaClicked();
    void onSalvaClicked();
    void onDatiRandomClicked();

private:
    VisualizzaSensori *m_viewS;
    View *m_view;
    static bool m_luminositaCreated;
    static bool m_umiditaCreated;
    static bool m_salinitaCreated;
    static bool m_temperaturaCreated;
    static bool m_phSuoloCreated;
    static Modello model;
};