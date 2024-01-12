#include "modello.h"

modello::modello() {}
bool modello::saveInfo(const QString &nomeFile, Serra serra){


    bool check=false;
    QDomDocument doc;
    QDomElement root = doc.createElement("root");
    doc.appendChild(root);
    int i=0;
    QDomElement UnitaMis = doc.createElement("Luminosita");
    UnitaMis.setAttribute("Intensita", Luminosita::getIntensita());
    root.appendChild(UnitaMis);
    QVector<Dato>const temp=serra.clona("Lumen");
    for ( i=0; temp.size(); i++)
    {
        QDomElement dato = doc.createElement("Dato");
        dato.setAttribute("Data",temp.at(i).getData().toString("yyyy-MM-dd"));
        dato.setAttribute("Time",temp.at(i).getOrario().toString("hh:mm:ss"));
        dato.setAttribute("Misurazione",QString::number(temp.at(i).getMisurazione()));
        dato.setAttribute("UnitaMisura",temp.at(i).getUnitaMisura());
        UnitaMis.appendChild(dato);
    }


         UnitaMis = doc.createElement("Temperatura");
         UnitaMis.setAttribute("Stato", Temperatura::getStato());

        QVector<Dato>const temp2=serra.clona("Celsius");
        for (i=0; temp2.size(); i++)
        {
            QDomElement dato = doc.createElement("Dato");
            dato.setAttribute("Data",temp2.at(i).getData().toString("yyyy-MM-dd"));
            dato.setAttribute("Time",temp2.at(i).getOrario().toString("hh:mm:ss"));
            dato.setAttribute("Misurazione",QString::number(temp2.at(i).getMisurazione()));
            dato.setAttribute("UnitaMisura",temp2.at(i).getUnitaMisura());
            UnitaMis.appendChild(dato);

        }


        UnitaMis = doc.createElement("Umidita");
        UnitaMis.setAttribute("Acceso", Umidita::getAcceso());

        QVector<Dato>const temp3=serra.clona("g/m^3");
        for ( i=0; temp3.size(); i++)
        {
            QDomElement dato = doc.createElement("Dato");
            dato.setAttribute("Data",temp3.at(i).getData().toString("yyyy-MM-dd"));
            dato.setAttribute("Orario",temp3.at(i).getOrario().toString("hh:mm:ss"));
            dato.setAttribute("Misurazione",QString::number(temp3.at(i).getMisurazione()));
            dato.setAttribute("UnitaMisura",temp3.at(i).getUnitaMisura());
            UnitaMis.appendChild(dato);

        }

        QFile file( nomeFile );
        if(file.open(QFile::WriteOnly | QFile::Text)){
            QTextStream in(&file);
            in<<doc.toString();
            file.flush();
            file.close();
        check=true;
    }
    return check;
}


bool modello::loadInfo(const QString& nomeFile, Serra *serra){
bool check=false;
    QDomDocument doc;
    QFile xmlFile(nomeFile);
    if (!xmlFile.open(QIODevice::ReadOnly ))
    {
        // Error while loading file
    }
    doc.setContent(&xmlFile);
    xmlFile.close();

    QDomElement root = doc.documentElement();
    QDomElement unitaMis = root.firstChild().toElement();
    QDomElement node = unitaMis.firstChild().toElement();
    int intensita = unitaMis.attribute("Intensita").toInt();

    while(intensita!=Luminosita::getIntensita()){
        if(intensita>Luminosita::getIntensita())
            Luminosita::aumentaIntensita();
        else
            Luminosita::diminuisciIntensita();
    }

    while(node.isNull() == false)
    {

        if(node.tagName() == "Dato"){
            while(!node.isNull()){
                QDate data = QDate::fromString(node.attribute("Data", "Data"));
                QTime orario = QTime::fromString(node.attribute("Orario", "Orario"));
                QString unitaMis = node.attribute("UnitaMisura","UnitaMisura");
                int misura = node.attribute("Misurazione","Misurazione").toInt();
                Dato d(unitaMis,misura,data,orario);
                serra->inserisciDato(d);
                check=true;
                node = node.nextSibling().toElement();
            }
        }
        node = node.nextSibling().toElement();
    }
    node.nextSiblingElement("Temperatura");

    return check;
}
