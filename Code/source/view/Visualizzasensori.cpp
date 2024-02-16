#include "visualizzasensori.h"
#include "../controller/controller.h"
#include <QInputDialog>
#include "GraficoView.h"
#include "VisualizzaDatiWindow.h"

QString nomeTipo(QString tipo){
    if(tipo=="Lumen"){
        return "Luminosità";
    } else if(tipo=="g/m^3"){
        return "Umidità";
    } else if(tipo=="Celsius"){
        return "Temperatura";
    } else if(tipo=="mmho/cm"){
        return "Salinità";
    } else if(tipo=="g/m^3"){
        return "Ph Suolo";
    }
    return "unknown";
}

VisualizzaSensori::VisualizzaSensori(const QString &tipoSensore, QWidget *parent)
    : QWidget(parent), tipo(tipoSensore)
{
    // Inizializza layoutDati come un layout verticale
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
    mainLayout->addLayout(layoutDati); // Aggiungi il layoutDati sotto i pulsanti

    setLayout(mainLayout);
    connect(btnModificaDescrizione, &QPushButton::clicked, this, &VisualizzaSensori::modificaDescrizione);
    connect(btnInserisci, &QPushButton::clicked, this, &VisualizzaSensori::inserisciDato);
    connect(btnVisualizza, &QPushButton::clicked, this, &VisualizzaSensori::visualizzaDati);
    connect(btnGrafico, &QPushButton::clicked, this, &VisualizzaSensori::grafico);
    visualizzaDescrizione();
}






void VisualizzaSensori::setController(Controller *controller) {
    m_controller = controller;
}

void VisualizzaSensori::inserisciDato() {
    // Chiedi all'utente di inserire il valore del dato direttamente nella funzione
    double valore = QInputDialog::getDouble(this, "Inserisci Dato", "Inserisci il valore del dato:", 0, 0, 100, 1);

    // Chiedi all'utente di selezionare l'ora
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

    // Ora hai raccolto tutti i dati dall'utente, puoi inviarli al controller per l'inserimento
    bool successo = m_controller->handleInserisciDato(valore, giorno.toInt(), mese.toInt(), anno.toInt(), ora, tipo);

    // Mostra un messaggio di conferma o di avviso all'utente
    if (successo) {
        QMessageBox::information(this, "Successo", "Dato inserito con successo!");
    } else {
        QMessageBox::warning(this, "Errore", "Si è verificato un errore durante l'inserimento del dato.");
    }
}


void VisualizzaSensori::visualizzaDati() {
    // Prendi i dati dal controller
    QVector<Dato> dati = m_controller->richiediDati(tipo);

    // Apri la finestra per visualizzare i dati
    VisualizzaDatiWindow* datiWindow = new VisualizzaDatiWindow(dati, m_controller,tipo, this);
    datiWindow->exec(); // Modalità modale per evitare l'interazione con la finestra principale mentre la finestra dei dati è aperta
}






void VisualizzaSensori::grafico() {
    // Crea una nuova finestra della classe GraficoView e passa il controller
    GraficoView *graficoView = new GraficoView(m_controller, tipo);
    graficoView->show(); // Mostra la finestra
}
void VisualizzaSensori::modificaDescrizione() {
    // Chiedi all'utente di inserire la nuova descrizione del sensore
    QString nuovaDescrizione = QInputDialog::getText(this, "Modifica Descrizione", "Inserisci la nuova descrizione:");

    // Invia la nuova descrizione al controller per l'aggiornamento
    m_controller->setDescrizioneSensore(tipo, nuovaDescrizione);

    // Visualizza la nuova descrizione
    visualizzaDescrizione();
}

// Aggiungi una nuova funzione privata visualizzaDescrizione() per ottenere e visualizzare la descrizione del sensore:
void VisualizzaSensori::visualizzaDescrizione() {
    // Ottieni la descrizione del sensore dal controller
    QString descrizione = m_controller->getDescrizioneSensore(tipo);

    // Visualizza la descrizione nel QLabel
    lblDescrizione->setText("Descrizione: " + descrizione);
}
