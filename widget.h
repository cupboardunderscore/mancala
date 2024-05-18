#ifndef WIDGET_H
#define WIDGET_H

#include "mancala.h"

#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QUdpSocket>
#include <QNetworkInterface>
#include <QLabel>
#include <QInputDialog>
#include <QTimer>
#include <QEventLoop>
#include <QVector>
#include <QStandardPaths>
#include <QFile>
#include <QDir>
#include <QHostInfo>
#include <QDesktopServices>

class Widget : public QWidget
{
    Q_OBJECT
    QStringList fila = QStandardPaths::standardLocations(QStandardPaths::AppConfigLocation);
    QString setpath;
    QString myname;
    int wins;
    QPushButton changename, rules, sinb, mulb, host, conn;
    QLabel name, usern, ipwait;
    QVBoxLayout mainpage;
    QHBoxLayout mainh, mulh;
    QUdpSocket socket, socket2;
    QString frenip, frenname;
    mancala mancl;
    QVBoxLayout mancccc;
    QHBoxLayout mancaladis, nameese;
    QVBoxLayout left, right;
    bool mmmm, nono = false, sinn = false;

public:
    QVector<QPushButton *> aas, bss;
    QVector<QLabel *> bbs;
    QPushButton a0, a1, a2, a3, a4, a5;
    QPushButton bs0, bs1, bs2, bs3, bs4, bs5;
    QLabel b0, b1, b2, b3, b4, b5;
    QLabel mn, fn, abowl, bbowl, tirn;
    Widget(QWidget *parent = nullptr);
    void send();
    void receive();
    void hostgame();
    void host2();
    void hostsend(int);
    void conngame();
    void conn2();
    void connsend(int);
    void timer(int);
    void playthedamngame();
    void playgame2();
    void enbu();
    void dibu();
    void changen();
    void win();
    void nowin();
    void bothwin();
    ~Widget();
};
#endif // WIDGET_H
