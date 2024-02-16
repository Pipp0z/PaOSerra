#pragma once

#include <QWidget>
#include <QMessageBox>
#include <QDebug>
#include "../controller/Controller.h"
#include "Visualizzasensori.h"
#include <QPushButton>
#include <QVBoxLayout>
#include <QInputDialog>

class QPushButton;
class QGridLayout;

class View : public QWidget {
    Q_OBJECT
public:
    explicit View(QWidget *parent = nullptr);
    void setLuminositaCreated(bool created);
    void setUmiditaCreated(bool created);
    void setSalinitaCreated(bool created);
    void setTemperaturaCreated(bool created);
    void setPhSuoloCreated(bool created);

signals:
    void creaSensoreRequested(QString tipoSensore);
    void rimuoviSensoreRequested(QString tipoSensore);
    void visualizzaSensoreRequested(QString tipoSensore);
    void caricaRequested();
    void salvaRequested();
    void datiRandomRequested();

private slots:
    void onInserisciSensoreClicked(const QString tipoSensore);
    void onRimuoviSensoreClicked(const QString tipoSensore);
    void onVisualizzaSensoreClicked(const QString tipoSensore);
    void onCaricaClicked();
    void onSalvaClicked();
    void onDatiRandomClicked();
    void onRicercaSensoreClicked();

private:
    void updateButtonsState(QPushButton *inserisci, QPushButton *rimuovi, QPushButton *visualizza, bool created);

    QGridLayout *m_layout;
    QPushButton *m_btnCreaLuminosita;
    QPushButton *m_btnVisualizzaLuminosita;
    QPushButton *m_btnRimuoviLuminosita;
    QPushButton *m_btnCreaUmidita;
    QPushButton *m_btnVisualizzaUmidita;
    QPushButton *m_btnRimuoviUmidita;
    QPushButton *m_btnCreaSalinita;
    QPushButton *m_btnVisualizzaSalinita;
    QPushButton *m_btnRimuoviSalinita;
    QPushButton *m_btnCreaTemperatura;
    QPushButton *m_btnVisualizzaTemperatura;
    QPushButton *m_btnRimuoviTemperatura;
    QPushButton *m_btnCreaPhSuolo;
    QPushButton *m_btnVisualizzaPhSuolo;
    QPushButton *m_btnRimuoviPhSuolo;
    QPushButton *m_btnCarica;
    QPushButton *m_btnSalva;
    QPushButton *m_btnDatiRandom;
    QPushButton *m_btnRicercaSensore;
};