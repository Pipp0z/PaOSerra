#include "Graficoview.h"

GraficoView::GraficoView(Controller *controller, const QString tipoMisura, QWidget *parent): QWidget(parent), uniMis(tipoMisura), m_controller(controller) {
    QVector<Dato> dati = m_controller->richiediDatiGrafico(tipoMisura);

    if (dati.isEmpty()) {
        qDebug() << "Nessun dato disponibile per il grafico";
        return;
    }

    QLineSeries *series = new QLineSeries();

    series->setPointsVisible(true);
    series->setPointLabelsVisible(true);
    series->setMarkerSize(10);
    series->setColor(Qt::red);

    for (const Dato &dato : dati) {
        QString temp = QString::fromStdString(dato.getData().toString()) + " " + QString::fromStdString(dato.getOrario().toString());
        qDebug()<<temp;
        qreal x = QDateTime::fromString(temp, "dd/MM/yyyy hh:mm:ss").toMSecsSinceEpoch();
        qDebug()<<x;
        qreal y = dato.getMisurazione();
        *series << QPointF(x, y);
    }

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Grafico dei dati");
    chart->legend()->setVisible(true);

    QDateTimeAxis *axisX = new QDateTimeAxis();
    axisX->setTickCount(10);
    axisX->setFormat("dd/MM/yyyy hh:mm:ss");
    axisX->setTitleText("Data e ora");
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);

    QValueAxis *axisY = new QValueAxis();
    axisY->setTitleText("Misurazione");
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);

    m_chartView = new QChartView(chart);
    m_chartView->setRenderHint(QPainter::Antialiasing);

    resize(800, 600);

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(m_chartView);
    setLayout(layout);
    QLabel *lblqualita = new QLabel("Qualità:");
    QLabel *txtqualita = new QLabel("Nullo");
    layout->addWidget(lblqualita);

    int qualita = m_controller->qualita(tipoMisura);
    QColor colore;
    QString testo;
    switch (qualita) {
    case 0:
        colore = Qt::blue;
        testo = "Basso";
        break;
    case 1:
        colore = Qt::green;
        testo = "Buono";
        break;
    case 2:
        colore = Qt::red;
        testo = "Alto";
        break;
    default:
        colore = Qt::black;
    }

    QLabel *lblColore = new QLabel;
    lblColore->setFixedSize(20, 20);
    lblColore->setAutoFillBackground(true);
    lblColore->setStyleSheet(QString("background-color: %1").arg(colore.name()));
    layout->addWidget(lblColore);
    txtqualita->setText(testo);
    layout->addWidget(txtqualita);
}

GraficoView::~GraficoView() {
    delete m_series;
    delete m_chart;
    delete m_chartView;
}
