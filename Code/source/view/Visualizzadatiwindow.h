#pragma once

#include <QDialog>
#include <QVector>
#include "../modello/sensori/Dato.h"
#include "qboxlayout.h"
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QInputDialog>
#include <QMessageBox>
#include "../controller/Controller.h"

class QPushButton;
class Controller;

class VisualizzaDatiWindow : public QDialog {
    Q_OBJECT

public:
    explicit VisualizzaDatiWindow(const QVector<Dato>& dati, Controller* controller, QString tipo, QWidget *parent = nullptr);

private slots:

private:
    QString unitaMis;
    QVector<Dato> m_dati;
    Controller* m_controller;
    QVBoxLayout* layoutMain;
    QPushButton* createButton(const QString& text, const QString& tooltip);
    void rimuoviDato( int index);
    void modificaDato( int index);
};