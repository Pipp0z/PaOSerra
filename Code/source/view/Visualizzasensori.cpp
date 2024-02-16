#include "Visualizzasensori.h"

QString nomeTipo(QString tipo){
    if(tipo=="Lumen"){
        return "Luminosità";
    } else if(tipo=="g/m^3"){
        return "Umidità";
    } else if(tipo=="Celsius"){
        return "Temperatura";
    } else if(tipo=="mmho/cm"){
        return "Salinità";
    } else if(tipo=="pH"){
        return "PhSuolo";
    }
    return "unknown";
}

VisualizzaSensori::VisualizzaSensori(const QString &tipoSensore, QWidget *parent): QWidget(parent), tipo(tipoSensore) {
    layoutDati = new QVBoxLayout();

    setWindowTitle("Visualizza Sensore " + nomeTipo(tipo));
    lblDescrizione = new QLabel("", this);
    btnModificaDescrizione = new QPushButton("Modifica Descrizione", this);

    btnInserisci = new QPushButton("Inserisci Dato", this);
    btnVisualizza = new QPushButton("Visualizza Dati", this);
    btnGrafico = new QPushButton("Grafico", this);

    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->addWidget(lblDescrizione);
    mainLayout->addWidget(btnInserisci);
    mainLayout->addWidget(btnGrafico);
    mainLayout->addWidget(btnModificaDescrizione);
    mainLayout->addWidget(btnVisualizza);
    mainLayout->addLayout(layoutDati);

    setLayout(mainLayout);
    connect(btnModificaDescrizione, &QPushButton::clicked, this, &VisualizzaSensori::modificaDescrizione);
    connect(btnInserisci, &QPushButton::clicked, this, &VisualizzaSensori::inserisciDato);
    connect(btnVisualizza, &QPushButton::clicked, this, &VisualizzaSensori::visualizzaDati);
    connect(btnGrafico, &QPushButton::clicked, this, &VisualizzaSensori::grafico);
    visualizzaDescrizione();

    setMinimumSize(300, 200);
}

void VisualizzaSensori::setController(Controller *controller) {
    m_controller = controller;
}

void VisualizzaSensori::inserisciDato() {
    double valore = QInputDialog::getDouble(this, "Inserisci Dato", "Inserisci il valore del dato:", 0, 0, 100, 1);

    QTime ora = QTime::currentTime();

    QStringList giorni;
    for (int i = 1; i <= 28; ++i) {
        giorni << QString::number(i);
    }
    bool ok;
    QString giorno = QInputDialog::getItem(this, "Inserisci Dato", "Seleziona il giorno:", giorni, 0, false, &ok);
    if (!ok) return;

    QStringList mesi;
    for (int i = 1; i <= 13; ++i) {
        mesi << QString::number(i);
    }
    QString mese = QInputDialog::getItem(this, "Inserisci Dato", "Seleziona il mese:", mesi, 0, false, &ok);
    if (!ok) return;

    QStringList anni;
    for (int i = 2001; i <= 2026; ++i) {
        anni << QString::number(i);
    }
    QString anno = QInputDialog::getItem(this, "Inserisci Dato", "Seleziona l'anno:", anni, 0, false, &ok);
    if (!ok) return;

    bool successo = m_controller->handleInserisciDato(valore, giorno.toInt(), mese.toInt(), anno.toInt(), ora, tipo);

    if (successo) {
        QMessageBox::information(this, "Successo", "Dato inserito con successo!");
    } else {
        QMessageBox::warning(this, "Errore", "Si è verificato un errore durante l'inserimento del dato.");
    }
}


void VisualizzaSensori::visualizzaDati() {
    QVector<Dato> dati = m_controller->richiediDati(tipo);

    VisualizzaDatiWindow* datiWindow = new VisualizzaDatiWindow(dati, m_controller,tipo, this);
    datiWindow->exec();
}

void VisualizzaSensori::grafico() {
    GraficoView *graficoView = new GraficoView(m_controller, tipo);
    graficoView->show();
}
void VisualizzaSensori::modificaDescrizione() {
    QString nuovaDescrizione = QInputDialog::getText(this, "Modifica Descrizione", "Inserisci la nuova descrizione:");
    m_controller->setDescrizioneSensore(tipo, nuovaDescrizione);
    visualizzaDescrizione();
}

void VisualizzaSensori::visualizzaDescrizione() {
    QString descrizione = m_controller->getDescrizioneSensore(tipo);
    lblDescrizione->setText("Descrizione: " + descrizione);
}