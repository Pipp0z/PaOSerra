#ifndef VISUALIZZASENSORI_H
#define VISUALIZZASENSORI_H

#include "qboxlayout.h"
#include "qlabel.h"
#include "qpushbutton.h"
#include <QWidget>
#include <QString>
#include <QTime>

class Controller;

class VisualizzaSensori : public QWidget
{
    Q_OBJECT

public:
    explicit VisualizzaSensori(const QString &tipoSensore, QWidget *parent = nullptr);
    void setController(Controller *controller);

private slots:
    void inserisciDato();
    void grafico();
    void visualizzaDati();
    void visualizzaDescrizione();
    void modificaDescrizione();

private:
    QString tipo;
    QVBoxLayout *layoutDati;
    QPushButton *btnInserisci;
    QPushButton *btnGrafico;
    QPushButton *btnVisualizza;
    QPushButton *btnModificaDescrizione;
    Controller *m_controller;
    QLabel *lblDescrizione;
    bool primaInterazione = true;

    // Se necessario, puoi dichiarare altri pulsanti qui
};

#endif // VISUALIZZASENSORI_H
