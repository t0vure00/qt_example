#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->lineEditForId->setPlaceholderText("Write ID here");
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_BgetAllPersons_clicked()
{

    QString site_url="http://localhost:3000/example/allpersons";
    QString credentials="automat123:pass123";

    QNetworkRequest request((site_url));

    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    QByteArray data = credentials.toLocal8Bit().toBase64();

    QString headerData = "Basic " + data;

    request.setRawHeader( "Authorization", headerData.toLocal8Bit() );

    allPersonsManager = new QNetworkAccessManager(this);

    connect(allPersonsManager, SIGNAL(finished (QNetworkReply*)),
    this, SLOT(allPersonsSlot(QNetworkReply*)));

    allPersonsReply = allPersonsManager->get(request);
}

void MainWindow::allPersonsSlot(QNetworkReply *reply)
{

    QByteArray response_data = reply->readAll();
    qDebug() << response_data;
    if(response_data.compare("-4078") == 0){//compare funktiolla voi verrata, shocking I know
        ui->labelResult->setText("Virhe tietokantayhteydessä");
    }else{
        QJsonDocument json_doc = QJsonDocument::fromJson(response_data);
        QJsonArray json_array = json_doc.array();
        QString persons;
        foreach (const QJsonValue &value, json_array) {
            QJsonObject json_obj = value.toObject();
            persons += QString::number((json_obj["id_person"].toInt()))
                    + " " + json_obj["fname"].toString() + " " + json_obj["lname"].toString()
                    + " " + QString::number((json_obj["money"].toDouble())) + "\r\n";
        }
        ui->labelResult->setText(persons);
    }


    allPersonsReply->deleteLater();
    reply->deleteLater();
    allPersonsManager->deleteLater();
}

void MainWindow::on_BgetOnePerson_clicked()
{
    id = ui->lineEditForId->text();


    QString site_url="http://localhost:3000/example/oneperson/" + id;
    QString credentials="automat123:pass123";

    QNetworkRequest request((site_url));

    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    QByteArray data = credentials.toLocal8Bit().toBase64();

    QString headerData = "Basic " + data;

    request.setRawHeader( "Authorization", headerData.toLocal8Bit() );

    OnePersonManager = new QNetworkAccessManager(this);

    connect(OnePersonManager, SIGNAL(finished (QNetworkReply*)),
    this, SLOT(OnePersonSlot(QNetworkReply*)));

    OnePersonReply = OnePersonManager->get(request);
}

void MainWindow::OnePersonSlot(QNetworkReply *reply)
{

    QByteArray response_data = reply->readAll();
    qDebug() << response_data;
    if(response_data.compare("") == 0){
        ui->labelResult->setText("Error: Tällä ID ei löydy henkilöä");
    }else if(response_data.compare("-4078") == 0){//compare funktiolla voi verrata, shocking I know
        ui->labelResult->setText("Virhe tietokantayhteydessä");
    }else{
        QJsonDocument json_doc = QJsonDocument::fromJson(response_data);
        QJsonObject json_obj = json_doc.object();
        QString persons;
        persons += QString::number((json_obj["id_person"].toInt()))
                    + " " + json_obj["fname"].toString() + " " + json_obj["lname"].toString()
                    + " " + QString::number((json_obj["money"].toDouble())) + "\r\n";
        ui->labelResult->setText(persons);
    }
        //ui->lineEditForId->setPlaceholderText("Write ID here");

    OnePersonReply->deleteLater();
    reply->deleteLater();
    OnePersonManager->deleteLater();
}

void MainWindow::on_BgetFullName_clicked()
{
    id = ui->lineEditForId->text();


    QString site_url="http://localhost:3000/example/fullname/" + id;
    QString credentials="automat123:pass123";

    QNetworkRequest request((site_url));

    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    QByteArray data = credentials.toLocal8Bit().toBase64();

    QString headerData = "Basic " + data;

    request.setRawHeader( "Authorization", headerData.toLocal8Bit() );

    FullNameManager = new QNetworkAccessManager(this);

    connect(FullNameManager, SIGNAL(finished (QNetworkReply*)),
    this, SLOT(FullNameSlot(QNetworkReply*)));

    FullNameReply = FullNameManager->get(request);
}

void MainWindow::FullNameSlot(QNetworkReply *reply)
{
    QByteArray response_data = reply->readAll();
    qDebug() << response_data;
    if(response_data.compare("") == 0){
        ui->labelResult->setText("Error: Tällä ID ei löydy henkilöä");
    }else if(response_data.compare("-4078") == 0){//compare funktiolla voi verrata, shocking I know
        ui->labelResult->setText("Virhe tietokantayhteydessä");
    }else{
        QJsonDocument json_doc = QJsonDocument::fromJson(response_data);
        QJsonObject json_obj = json_doc.object();
        QString persons;
        persons = json_obj["fullname"].toString() + "\r\n";
        ui->labelResult->setText(persons);
    }
        //ui->lineEditForId->setPlaceholderText("Write ID here");

    FullNameReply->deleteLater();
    reply->deleteLater();
    FullNameManager->deleteLater();
}
