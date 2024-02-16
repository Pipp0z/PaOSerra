#include "visualizzadatiwindow.h"
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QInputDialog>
#include <QMessageBox>
#include "../controller/controller.h"

VisualizzaDatiWindow::VisualizzaDatiWindow(const QVector<Dato>& dati, Controller* controller, QString tipo, QWidget *parent)
    : QDialog(parent), unitaMis(tipo), m_dati(dati), m_controller(controller)
{
    layoutMain = new QVBoxLayout(this);
    setLayout(layoutMain);

    for (int index = 0; index < m_dati.size(); ++index) {
        QHBoxLayout* rowLayout = new QHBoxLayout();

        const Dato& dato = m_dati[index];

        QLabel* valueLabel = new QLabel(QString("Valore: %1").arg(dato.getMisurazione()));
        rowLayout->addWidget(valueLabel);

        QLabel* timeLabel = new QLabel(QString("Ora: %1").arg(QString::fromStdString(dato.getOrario().toString())));
        rowLayout->addWidget(timeLabel);

        QLabel* dateLabel = new QLabel(QString("Data: %1").arg(QString::fromStdString(dato.getData().toString())));
        rowLayout->addWidget(dateLabel);

        QPushButton* removeButton = createButton("Rimuovi", "Rimuovi questo dato");
        rowLayout->addWidget(removeButton);

        QPushButton* editButton = createButton("Modifica", "Modifica questo dato");
        rowLayout->addWidget(editButton);

        layoutMain->addLayout(rowLayout);

        // Connessione dei segnali clicked dei pulsanti ai rispettivi slot
        connect(removeButton, &QPushButton::clicked, this, [this, index]() { rimuoviDato(index); });
        connect(editButton, &QPushButton::clicked, this, [this, index]() { modificaDato(index); });
    }

    setMinimumSize(400, 200); // Imposta una dimensione minima per la finestra
}

QPushButton* VisualizzaDatiWindow::createButton(const QString& text, const QString& tooltip) {
    QPushButton* button = new QPushButton(text);
    button->setToolTip(tooltip);
    return button;
}

void VisualizzaDatiWindow::rimuoviDato(int index) {
    if (index < 0 || index >= m_dati.size())
        return;

    const Dato& dato = m_dati[index];

    // Rimuovi il dato dal controller
    m_controller->handleRimuoviDato(dato.getOrario().toString(), dato.getData().toString(), unitaMis.toStdString());

    // Rimuovi il dato dalla lista
    m_dati.remove(index);

    // Chiudi la finestra corrente
    close();

    // Apri una nuova istanza della finestra
    VisualizzaDatiWindow* newWindow = new VisualizzaDatiWindow(m_dati, m_controller, unitaMis, parentWidget());
    newWindow->show();
}

void VisualizzaDatiWindow::modificaDato(int index) {
    if (index < 0 || index >= m_dati.size())
        return;

    Dato& dato = m_dati[index];

    // Chiedi all'utente di inserire il nuovo valore del dato
    bool ok;
    double nuovoValore = QInputDialog::getDouble(this, "Modifica Dato", "Inserisci il nuovo valore del dato:", dato.getMisurazione(), 0, 100, 1, &ok);
    if (ok) {
        // Modifica il dato nel controller
        m_controller->handleModificaDato(dato.getOrario().toString(), dato.getData().toString(), nuovoValore, unitaMis.toStdString());

        // Aggiorna il valore del dato nella lista
        dato.setMisurazione(nuovoValore);

        // Chiudi la finestra corrente
        close();

        // Apri una nuova istanza della finestra
        VisualizzaDatiWindow* newWindow = new VisualizzaDatiWindow(m_dati, m_controller, unitaMis, parentWidget());
        newWindow->show();
    }
}
