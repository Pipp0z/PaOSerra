#include "Visualizzadatiwindow.h"

VisualizzaDatiWindow::VisualizzaDatiWindow(const QVector<Dato>& dati, Controller* controller, QString tipo, QWidget *parent): QDialog(parent), unitaMis(tipo), m_dati(dati), m_controller(controller) {
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
        
        connect(removeButton, &QPushButton::clicked, this, [this, index]() { rimuoviDato(index); });
        connect(editButton, &QPushButton::clicked, this, [this, index]() { modificaDato(index); });
    }

    setMinimumSize(400, 200);
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

    m_controller->handleRimuoviDato(dato.getOrario().toString(), dato.getData().toString(), unitaMis.toStdString());

    m_dati.remove(index);

    close();

    VisualizzaDatiWindow* newWindow = new VisualizzaDatiWindow(m_dati, m_controller, unitaMis, parentWidget());
    newWindow->show();
}

void VisualizzaDatiWindow::modificaDato(int index) {
    if (index < 0 || index >= m_dati.size())
        return;

    Dato& dato = m_dati[index];

    bool ok;
    double nuovoValore = QInputDialog::getDouble(this, "Modifica Dato", "Inserisci il nuovo valore del dato:", dato.getMisurazione(), 0, 100, 1, &ok);
    if (ok) {
        m_controller->handleModificaDato(dato.getOrario().toString(), dato.getData().toString(), nuovoValore, unitaMis.toStdString());
        dato.setMisurazione(nuovoValore);
        close();

        VisualizzaDatiWindow* newWindow = new VisualizzaDatiWindow(m_dati, m_controller, unitaMis, parentWidget());
        newWindow->show();
    }
}
