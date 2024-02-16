#include "Graficoview.h"
// #include <QChartView>
// #include <QLineSeries>
// #include <QChart>
// #include <QValueAxis>
// #include <QDateTime>
// #include <QDebug>

GraficoView::GraficoView(Controller *controller, const QString tipoMisura, QWidget *parent)
    : QWidget(parent), uniMis(tipoMisura), m_controller(controller)
{
    // Chiedi al controller di restituire i dati per il grafico
    QVector<Dato> dati = m_controller->richiediDatiGrafico(tipoMisura);

    // Verifica se ci sono dati validi
    if (dati.isEmpty()) {
        qDebug() << "Nessun dato disponibile per il grafico";
        return;
    }

    // Crea una serie di dati per il grafico
    QLineSeries *series = new QLineSeries();

    // Imposta le proprietà dei puntini
    series->setPointsVisible(true);
    series->setPointLabelsVisible(true);
    series->setMarkerSize(10); // Imposta la dimensione del puntino
    series->setColor(Qt::red); // Imposta il colore dei puntini

    // Aggiungi i dati alla serie
    for (const Dato &dato : dati) {

        QString temp = QString::fromStdString(dato.getData().toString()) + " " + QString::fromStdString(dato.getOrario().toString());
        qDebug()<<temp;
        qreal x = QDateTime::fromString(temp, "dd/MM/yyyy hh:mm:ss").toMSecsSinceEpoch();
        qDebug()<<x;
        qreal y = dato.getMisurazione();
        *series << QPointF(x, y); // Utilizza l'operatore << per aggiungere i punti
    }

    // Crea il grafico e aggiungi la serie ad esso
    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Grafico dei dati");
    chart->legend()->setVisible(true); // Visualizza la legenda

    // Imposta l'asse X
    QDateTimeAxis *axisX = new QDateTimeAxis();
    axisX->setTickCount(10); // Imposta il numero di tick desiderato sull'asse X
    axisX->setFormat("dd/MM/yyyy hh:mm:ss");
    axisX->setTitleText("Data e ora");
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);

    // Imposta l'asse Y
    QValueAxis *axisY = new QValueAxis();
    axisY->setTitleText("Misurazione");
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);

    // Crea la visualizzazione del grafico
    m_chartView = new QChartView(chart);
    m_chartView->setRenderHint(QPainter::Antialiasing);

    resize(800, 600);

    // Aggiungi il grafico al layout
    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(m_chartView);
    setLayout(layout);
    QLabel *lblQualita = new QLabel("Qualità:");
    layout->addWidget(lblQualita);

    int qualita = m_controller->qualita(tipoMisura);
    QColor colore;
    switch (qualita) {
    case 0:
        colore = Qt::blue;
        break;
    case 1:
        colore = Qt::green;
        break;
    case 2:
        colore = Qt::red;
        break;
    default:
        colore = Qt::black; // Colore di default nel caso in cui il valore restituito non sia valido
    }
    QLabel *lblColore = new QLabel;
    lblColore->setFixedSize(20, 20); // Imposta le dimensioni del quadrato
    lblColore->setAutoFillBackground(true);
    lblColore->setStyleSheet(QString("background-color: %1").arg(colore.name()));
    layout->addWidget(lblColore);
}


GraficoView::~GraficoView() {
    delete m_series;
    delete m_chart;
    delete m_chartView;
}
