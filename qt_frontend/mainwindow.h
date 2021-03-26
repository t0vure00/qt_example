#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QtNetwork>//sama kuin pro tiedostossa
#include <QNetworkAccessManager>
#include <QJsonDocument>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_BgetAllPersons_clicked();
    void allPersonsSlot(QNetworkReply *reply);

    void on_BgetOnePerson_clicked();
    void OnePersonSlot(QNetworkReply *reply);

    void on_BgetFullName_clicked();
    void FullNameSlot(QNetworkReply *reply);

private:
    Ui::MainWindow *ui;
    QNetworkAccessManager *allPersonsManager;//tehdään manageri
    QNetworkReply *allPersonsReply;

    QNetworkAccessManager *OnePersonManager;//tehdään manageri
    QNetworkReply *OnePersonReply;

    QNetworkAccessManager *FullNameManager;//tehdään manageri
    QNetworkReply *FullNameReply;

    QString id;
};
#endif // MAINWINDOW_H
