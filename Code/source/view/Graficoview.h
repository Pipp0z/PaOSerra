#pragma once

#include <QWidget>
#include <QtCharts>
#include "../controller/Controller.h"


#include <QChartView>
#include <QLineSeries>
#include <QChart>
#include <QValueAxis>
#include <QDateTime>
#include <QDebug>

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