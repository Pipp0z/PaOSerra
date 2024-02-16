#include "View.h"

View::View(QWidget *parent) : QWidget(parent) {
    m_layout = new QGridLayout(this);

    m_btnCreaLuminosita = new QPushButton("Crea Sensore Luminosità", this);
    m_btnVisualizzaLuminosita = new QPushButton("Visualizza Sensore Luminosità", this);
    m_btnRimuoviLuminosita = new QPushButton("Rimuovi Sensore Luminosità", this);

    m_btnCreaUmidita = new QPushButton("Crea Sensore Umidità", this);
    m_btnVisualizzaUmidita = new QPushButton("Visualizza Sensore Umidità", this);
    m_btnRimuoviUmidita = new QPushButton("Rimuovi Sensore Umidità", this);

    m_btnCreaTemperatura = new QPushButton("Crea Sensore Temperatura", this);
    m_btnVisualizzaTemperatura = new QPushButton("Visualizza Sensore Temperatura", this);
    m_btnRimuoviTemperatura = new QPushButton("Rimuovi Sensore Temperatura", this);

    m_btnCreaSalinita = new QPushButton("Crea Sensore Salinità", this);
    m_btnVisualizzaSalinita = new QPushButton("Visualizza Sensore Salinità", this);
    m_btnRimuoviSalinita = new QPushButton("Rimuovi Sensore Salinità", this);

    m_btnCreaPhSuolo = new QPushButton("Crea Sensore PhSuolo", this);
    m_btnVisualizzaPhSuolo = new QPushButton("Visualizza Sensore PhSuolo", this);
    m_btnRimuoviPhSuolo = new QPushButton("Rimuovi Sensore PhSuolo", this);

    m_btnCarica = new QPushButton("Carica", this);
    m_btnSalva = new QPushButton("Salva", this);
    m_btnDatiRandom = new QPushButton("Dati Random", this);

    m_btnRicercaSensore = new QPushButton("Ricerca Sensore", this);
    m_layout->addWidget(m_btnRicercaSensore, 6, 0, 1, 3);

    m_layout->addWidget(m_btnCreaLuminosita, 0, 0);
    m_layout->addWidget(m_btnVisualizzaLuminosita, 0, 1);
    m_layout->addWidget(m_btnRimuoviLuminosita, 0, 2);

    m_layout->addWidget(m_btnCreaUmidita, 1, 0);
    m_layout->addWidget(m_btnVisualizzaUmidita, 1, 1);
    m_layout->addWidget(m_btnRimuoviUmidita, 1, 2);

    m_layout->addWidget(m_btnCreaSalinita, 2, 0);
    m_layout->addWidget(m_btnVisualizzaSalinita, 2, 1);
    m_layout->addWidget(m_btnRimuoviSalinita, 2, 2);

    m_layout->addWidget(m_btnCreaTemperatura, 3, 0);
    m_layout->addWidget(m_btnVisualizzaTemperatura, 3, 1);
    m_layout->addWidget(m_btnRimuoviTemperatura, 3, 2);

    m_layout->addWidget(m_btnCreaPhSuolo, 4, 0);
    m_layout->addWidget(m_btnVisualizzaPhSuolo, 4, 1);
    m_layout->addWidget(m_btnRimuoviPhSuolo, 4, 2);

    m_layout->addWidget(m_btnCarica, 5, 0);
    m_layout->addWidget(m_btnSalva, 5, 1);
    m_layout->addWidget(m_btnDatiRandom, 5, 2);

    setLayout(m_layout);

    m_btnVisualizzaLuminosita->setEnabled(false);
    m_btnRimuoviLuminosita->setEnabled(false);
    m_btnVisualizzaUmidita->setEnabled(false);
    m_btnRimuoviUmidita->setEnabled(false);
    m_btnRimuoviTemperatura->setEnabled(false);
    m_btnVisualizzaTemperatura->setEnabled(false);
    m_btnRimuoviSalinita->setEnabled(false);
    m_btnVisualizzaSalinita->setEnabled(false);
    m_btnRimuoviPhSuolo->setEnabled(false);
    m_btnVisualizzaPhSuolo->setEnabled(false);
    m_btnCarica->setEnabled(true);
    m_btnSalva->setEnabled(true);
    m_btnDatiRandom->setEnabled(true);

    connect(m_btnCreaLuminosita, &QPushButton::clicked, this, [this]() { onInserisciSensoreClicked("Lumen"); });
    connect(m_btnVisualizzaLuminosita, &QPushButton::clicked, this,  [this]() { onVisualizzaSensoreClicked("Lumen"); });
    connect(m_btnRimuoviLuminosita, &QPushButton::clicked, this,  [this]() { onRimuoviSensoreClicked("Lumen"); });

    connect(m_btnCreaUmidita, &QPushButton::clicked, this, [this]() { onInserisciSensoreClicked("g/m^3"); });
    connect(m_btnVisualizzaUmidita, &QPushButton::clicked, this, [this]() { onVisualizzaSensoreClicked("g/m^3"); });
    connect(m_btnRimuoviUmidita, &QPushButton::clicked, this, [this]() { onRimuoviSensoreClicked("g/m^3"); });

    connect(m_btnCreaSalinita, &QPushButton::clicked, this, [this]() { onInserisciSensoreClicked("mmho/cm"); });
    connect(m_btnVisualizzaSalinita, &QPushButton::clicked, this, [this]() { onVisualizzaSensoreClicked("mmho/cm"); });
    connect(m_btnRimuoviSalinita, &QPushButton::clicked, this,  [this]() { onRimuoviSensoreClicked("mmho/cm"); });

    connect(m_btnCreaTemperatura, &QPushButton::clicked, this,[this]() { onInserisciSensoreClicked("Celsius"); });
    connect(m_btnVisualizzaTemperatura, &QPushButton::clicked, this,[this]() { onVisualizzaSensoreClicked("Celsius"); });
    connect(m_btnRimuoviTemperatura, &QPushButton::clicked, this,  [this]() { onRimuoviSensoreClicked("Celsius"); });

    connect(m_btnCreaPhSuolo, &QPushButton::clicked, this, [this]() { onInserisciSensoreClicked("pH"); });
    connect(m_btnVisualizzaPhSuolo, &QPushButton::clicked, this, [this]() { onVisualizzaSensoreClicked("pH"); });
    connect(m_btnRimuoviPhSuolo, &QPushButton::clicked, this,  [this]() { onRimuoviSensoreClicked("pH"); });

    connect(m_btnRicercaSensore, &QPushButton::clicked, this, &View::onRicercaSensoreClicked);
    connect(m_btnCarica, &QPushButton::clicked, this, &View::onCaricaClicked);
    connect(m_btnSalva, &QPushButton::clicked, this, &View::onSalvaClicked);
    connect(m_btnDatiRandom, &QPushButton::clicked, this, &View::onDatiRandomClicked);
}

void View::setLuminositaCreated(bool created) {
     updateButtonsState(m_btnCreaLuminosita, m_btnRimuoviLuminosita, m_btnVisualizzaLuminosita, created);
}

void View::setUmiditaCreated(bool created) {
    updateButtonsState(m_btnCreaUmidita, m_btnRimuoviUmidita, m_btnVisualizzaUmidita, created);
}

void View::setSalinitaCreated(bool created) {
    updateButtonsState(m_btnCreaSalinita, m_btnRimuoviSalinita, m_btnVisualizzaSalinita, created);
}

void View::setTemperaturaCreated(bool created) {
    updateButtonsState(m_btnCreaTemperatura, m_btnRimuoviTemperatura, m_btnVisualizzaTemperatura, created);
}

void View::setPhSuoloCreated(bool created) {
    updateButtonsState(m_btnCreaPhSuolo, m_btnRimuoviPhSuolo, m_btnVisualizzaPhSuolo, created);
}

void View::updateButtonsState(QPushButton *inserisci, QPushButton *rimuovi, QPushButton *visualizza, bool created) {
    inserisci->setEnabled(!created);
    rimuovi->setEnabled(created);
    visualizza->setEnabled(created);
}

void View::onInserisciSensoreClicked(const QString tipoSensore) {
    emit creaSensoreRequested(tipoSensore);
}

void View::onRimuoviSensoreClicked(const QString tipoSensore) {
    emit rimuoviSensoreRequested(tipoSensore);
}

void View::onVisualizzaSensoreClicked(const QString tipoSensore) {
    VisualizzaSensori *finestraVisualizzaSensori = new VisualizzaSensori(tipoSensore);
    Controller *controller = new Controller();
    finestraVisualizzaSensori->setController(controller);
    finestraVisualizzaSensori->show();
}

void View::onCaricaClicked() {
    emit caricaRequested();
}

void View::onSalvaClicked() {
    emit salvaRequested();
}

void View::onDatiRandomClicked() {
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(nullptr, "Conferma", "Sovrascriverai i dati attuali,\n vuoi davvero generare dati randomici?", QMessageBox::Yes|QMessageBox::No);
    if (reply == QMessageBox::Yes) {
        emit datiRandomRequested();
    }
}

void View::onRicercaSensoreClicked() {
    QStringList unitaMisura;
    unitaMisura << "Lumen" << "g/m^3" << "mmho/cm" << "Celsius" << "pH";
    QString scelta = QInputDialog::getItem(this, "Ricerca Sensore", "Seleziona l'unità di misura del sensore:", unitaMisura, 0, false);

    if (scelta.isEmpty()) {
        return; 
    }

    Controller *controller = new Controller();
    bool sensoreDisponibile = controller->verificaDisponibilitaSensore(scelta);

    if (sensoreDisponibile) {
        onVisualizzaSensoreClicked(scelta);
    } else {
        QMessageBox::critical(this, "Errore", "Sensore non disponibile.");
    }
}