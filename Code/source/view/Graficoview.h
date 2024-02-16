// In graficoview.h
#ifndef GRAFICOVIEW_H
#define GRAFICOVIEW_H

#include <QWidget>
#include <QtCharts>
#include "../controller/controller.h"

class GraficoView : public QWidget {
    Q_OBJECT

public:
    GraficoView(Controller *controller, QString tipoMisura, QWidget *parent = nullptr);
    ~GraficoView();

private:
    QString uniMis;
    Controller *m_controller;
    QChartView *m_chartView;
    QChart *m_chart;
    QLineSeries *m_series;
};

#endif // GRAFICOVIEW_H
