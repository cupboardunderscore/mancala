#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    setpath = fila[0];
    qDebug() << setpath;
    QDir dir;
    if (!dir.exists(setpath))
    {
        dir.mkpath(setpath);
    }
    QFile settings(setpath + "/settings");
    if (!settings.exists())
    {
        QStringList tempo = QHostInfo::localHostName().split('.');
        QStringList tempoo = tempo[0].split('-');
        myname = QInputDialog::getText(this, "mancala.", "choose your name", QLineEdit::Normal, tempoo[0]);
        settings.open(QIODevice::ReadWrite);
        QTextStream txtStream(&settings);
        txtStream << myname;
        txtStream << "\n0\nplsdonotchange:3";
        settings.close();
    }
    settings.open(QIODevice::ReadWrite);
    QTextStream txtStream(&settings);
    myname = txtStream.readLine();
    txtStream >> wins;
    settings.close();
    QString tempwins;
    tempwins.setNum(wins);
    if (wins == 0)
    {
        tempwins += " wins :c";
    }
    else if (wins == 1)
    {
        tempwins += " win!";
    }
    else
    {
        tempwins += " wins!";
    }
    changename.setText("change name");
    rules.setText("how to play");
    name.setText("mancala.");
    name.setStyleSheet("font-weight: bold");
    usern.setText("welcome " + myname + "\nyou have " + tempwins);
    sinb.setText("local game");
    mulb.setText("multiplayer");
    host.setText("host game");
    conn.setText("connect to game");
    mulh.addWidget(&host);
    mulh.addWidget(&conn);
    mainh.addWidget(&sinb);
    mainh.addWidget(&mulb);
    mainpage.addWidget(&name);
    mainpage.addWidget(&usern);
    mainpage.addWidget(&changename);
    mainpage.addWidget(&rules);
    mainpage.addLayout(&mainh);
    setLayout(&mainpage);
    QObject::connect(&changename, &QPushButton::clicked, [&]()
    {
        changen();
    });
    QObject::connect(&rules, &QPushButton::clicked, [&]()
    {
        QUrl link("https://www.scholastic.com/content/dam/teachers/blogs/alycia-zimmerman/migrated-files/mancala_rules.pdf");
        QDesktopServices::openUrl(link);
    });
    QObject::connect(&sinb, &QPushButton::clicked, [&]()
    {
        changename.hide();
        rules.hide();
        sinb.hide();
        mulb.hide();
        usern.hide();
        sinn = true;
        frenname = "player 2";
        playgame2();
    });
    QObject::connect(&mulb, &QPushButton::clicked, [&]()
    {
        changename.hide();
        rules.hide();
        sinb.hide();
        mulb.hide();
        usern.hide();
        mainpage.addLayout(&mulh);
        timer(10);
        this->resize(1,1);
    });
    QObject::connect(&host, &QPushButton::clicked, [&]()
    {
        mmmm = true;
        host.hide();
        conn.hide();
        hostgame();
    });
    QObject::connect(&conn, &QPushButton::clicked, [&]()
    {
        mmmm = false;
        host.hide();
        conn.hide();
        conngame();
    });
    QObject::connect(&a0, &QPushButton::clicked, [&]()
    {
        int numnum = 0;
        if (sinn == false)
        {
            if (mmmm == true)
            {
                hostsend(numnum);
            }
            else
            {
                connsend(numnum);
            }
        }
        mancl.x = numnum;
        int r = mancl.movea();
        if (r == 0)
        {
            dibu();
        }
        int w = mancl.check(aas, bbs, abowl, bbowl, bss);
        if (w == 1)
        {
            win();
        }
        else if (w == 2)
        {
            nowin();
        }
        else if (w == 3)
        {
            bothwin();
        }
    });
    QObject::connect(&a1, &QPushButton::clicked, [&]()
    {
        int numnum = 1;
        if (sinn == false)
        {
            if (mmmm == true)
            {
                hostsend(numnum);
            }
            else
            {
                connsend(numnum);
            }
        }
        mancl.x = numnum;
        int r = mancl.movea();
        if (r == 0)
        {
            dibu();
        }
        int w = mancl.check(aas, bbs, abowl, bbowl, bss);
        if (w == 1)
        {
            win();
        }
        else if (w == 2)
        {
            nowin();
        }
        else if (w == 3)
        {
            bothwin();
        }
    });
    QObject::connect(&a2, &QPushButton::clicked, [&]()
    {
        int numnum = 2;
        if (sinn == false)
        {
            if (mmmm == true)
            {
                hostsend(numnum);
            }
            else
            {
                connsend(numnum);
            }
        }
        mancl.x = numnum;
        int r = mancl.movea();
        if (r == 0)
        {
            dibu();
        }
        int w = mancl.check(aas, bbs, abowl, bbowl, bss);
        if (w == 1)
        {
            win();
        }
        else if (w == 2)
        {
            nowin();
        }
        else if (w == 3)
        {
            bothwin();
        }
    });
    QObject::connect(&a3, &QPushButton::clicked, [&]()
    {
        int numnum = 3;
        if (sinn == false)
        {
            if (mmmm == true)
            {
                hostsend(numnum);
            }
            else
            {
                connsend(numnum);
            }
        }
        mancl.x = numnum;
        int r = mancl.movea();
        if (r == 0)
        {
            dibu();
        }
        int w = mancl.check(aas, bbs, abowl, bbowl, bss);
        if (w == 1)
        {
            win();
        }
        else if (w == 2)
        {
            nowin();
        }
        else if (w == 3)
        {
            bothwin();
        }
    });
    QObject::connect(&a4, &QPushButton::clicked, [&]()
    {
        int numnum = 4;
        if (sinn == false)
        {
            if (mmmm == true)
            {
                hostsend(numnum);
            }
            else
            {
                connsend(numnum);
            }
        }
        mancl.x = numnum;
        int r = mancl.movea();
        if (r == 0)
        {
            dibu();
        }
        int w = mancl.check(aas, bbs, abowl, bbowl, bss);
        if (w == 1)
        {
            win();
        }
        else if (w == 2)
        {
            nowin();
        }
        else if (w == 3)
        {
            bothwin();
        }
    });
    QObject::connect(&a5, &QPushButton::clicked, [&]()
    {
        int numnum = 5;
        if (sinn == false)
        {
            if (mmmm == true)
            {
                hostsend(numnum);
            }
            else
            {
                connsend(numnum);
            }
        }
        mancl.x = numnum;
        int r = mancl.movea();
        if (r == 0)
        {
            dibu();
        }
        int w = mancl.check(aas, bbs, abowl, bbowl, bss);
        if (w == 1)
        {
            win();
        }
        else if (w == 2)
        {
            nowin();
        }
        else if (w == 3)
        {
            bothwin();
        }
    });
    QObject::connect(&bs0, &QPushButton::clicked, [&]()
    {
        int numnum = 0;
        mancl.x = numnum;
        int r = mancl.moveb();
        if (r == 0)
        {
            enbu();
        }
        int w = mancl.check(aas, bbs, abowl, bbowl, bss);
        if (w == 1)
        {
            win();
        }
        else if (w == 2)
        {
            nowin();
        }
        else if (w == 3)
        {
            bothwin();
        }
    });
    QObject::connect(&bs1, &QPushButton::clicked, [&]()
    {
        int numnum = 1;
        mancl.x = numnum;
        int r = mancl.moveb();
        if (r == 0)
        {
            enbu();
        }
        int w = mancl.check(aas, bbs, abowl, bbowl, bss);
        if (w == 1)
        {
            win();
        }
        else if (w == 2)
        {
            nowin();
        }
        else if (w == 3)
        {
            bothwin();
        }
    });
    QObject::connect(&bs2, &QPushButton::clicked, [&]()
    {
        int numnum = 2;
        mancl.x = numnum;
        int r = mancl.moveb();
        if (r == 0)
        {
            enbu();
        }
        int w = mancl.check(aas, bbs, abowl, bbowl, bss);
        if (w == 1)
        {
            win();
        }
        else if (w == 2)
        {
            nowin();
        }
        else if (w == 3)
        {
            bothwin();
        }
    });
    QObject::connect(&bs3, &QPushButton::clicked, [&]()
    {
        int numnum = 3;
        mancl.x = numnum;
        int r = mancl.moveb();
        if (r == 0)
        {
            enbu();
        }
        int w = mancl.check(aas, bbs, abowl, bbowl, bss);
        if (w == 1)
        {
            win();
        }
        else if (w == 2)
        {
            nowin();
        }
        else if (w == 3)
        {
            bothwin();
        }
    });
    QObject::connect(&bs4, &QPushButton::clicked, [&]()
    {
        int numnum = 4;
        mancl.x = numnum;
        int r = mancl.moveb();
        if (r == 0)
        {
            enbu();
        }
        int w = mancl.check(aas, bbs, abowl, bbowl, bss);
        if (w == 1)
        {
            win();
        }
        else if (w == 2)
        {
            nowin();
        }
        else if (w == 3)
        {
            bothwin();
        }
    });
    QObject::connect(&bs5, &QPushButton::clicked, [&]()
    {
        int numnum = 5;
        mancl.x = numnum;
        int r = mancl.moveb();
        if (r == 0)
        {
            enbu();
        }
        int w = mancl.check(aas, bbs, abowl, bbowl, bss);
        if (w == 1)
        {
            win();
        }
        else if (w == 2)
        {
            nowin();
        }
        else if (w == 3)
        {
            bothwin();
        }
    });
}

void Widget::hostgame()
{
    QString tempip;
    const QHostAddress &localhost = QHostAddress(QHostAddress::LocalHost);
    for (const QHostAddress &address: QNetworkInterface::allAddresses())
    {
        if (address.protocol() == QAbstractSocket::IPv4Protocol && address != localhost)
        {
            tempip = address.toString();
        }
    }
    ipwait.setText("your ip adress: " + tempip + "\nwaiting for connection...");
    mainpage.addWidget(&ipwait);
    if (!socket.bind(55555, QUdpSocket::ShareAddress))
    {
        qDebug() << "Chyba pri inicializaci socketu";
    }
    QObject::connect(&socket, &QUdpSocket::readyRead, [&]()
    {
        if (nono == false)
        {
            QByteArray datagram;
            datagram.resize(socket.pendingDatagramSize());
            QHostAddress address;
            quint16 port;
            socket.readDatagram(datagram.data(), datagram.size(), &address, &port);
            QHostAddress tempipp(address.toIPv4Address());
            frenip = tempipp.toString();
            frenname = datagram.data();
            socket.close();
            ipwait.setText(frenname + " connected with ip: " + frenip);
            qDebug() << datagram.data() << tempipp;
            host2();
            nono = true;
        }
    });
}

void Widget::host2()
{
    QString tempwins;
    tempwins.setNum(wins);
    tempwins = myname + " (" + tempwins + ")";
    QHostAddress frenaddress(frenip);
    QByteArray datagram2 = tempwins.toUtf8();
    timer(1000);
    socket2.writeDatagram(datagram2.data(), datagram2.size(), frenaddress, 55556);
    playthedamngame();
    ipwait.hide();
    if (!socket.bind(55555, QUdpSocket::ShareAddress))
    {
        qDebug() << "Chyba pri inicializaci socketu";
    }
    QObject::connect(&socket, &QUdpSocket::readyRead, [&]()
    {
        QByteArray datagram;
        datagram.resize(socket.pendingDatagramSize());
        QHostAddress address;
        quint16 port;
        socket.readDatagram(datagram.data(), datagram.size(), &address, &port);
        QHostAddress tempipp(address.toIPv4Address());
        if (tempipp.toString() == frenip)
        {
            qDebug() << datagram.data();
            QString te = datagram.data();
            mancl.x = te.toInt();
            int r = mancl.moveb();
            if (r == 0)
            {
                enbu();
            }
            int w = mancl.check(aas, bbs, abowl, bbowl, bss);
            if (w == 1)
            {
                win();
            }
            else if (w == 2)
            {
                nowin();
            }
            else if (w == 3)
            {
                bothwin();
            }
        }
    });
}

void Widget::hostsend(int data)
{
    QString temp;
    temp.setNum(data);
    QHostAddress frenaddress(frenip);
    QByteArray datagram2 = temp.toUtf8();
    socket2.writeDatagram(datagram2.data(), datagram2.size(), frenaddress, 55556);
}

void Widget::conngame()
{
    frenip = QInputDialog::getText(this, "mancala.", "enter host ip:");
    QString tempwins;
    tempwins.setNum(wins);
    tempwins = myname + " (" + tempwins + ")";
    QHostAddress frenaddress(frenip);
    QByteArray datagram2 = tempwins.toUtf8();
    socket.writeDatagram(datagram2.data(), datagram2.size(), frenaddress, 55555);
    if (!socket2.bind(55556, QUdpSocket::ShareAddress))
    {
        qDebug() << "Chyba pri inicializaci socketu";
    }
    QObject::connect(&socket2, &QUdpSocket::readyRead, [&]()
    {
        if (nono == false)
        {
            QByteArray datagram;
            datagram.resize(socket2.pendingDatagramSize());
            QHostAddress address;
            quint16 port;
            socket2.readDatagram(datagram.data(), datagram.size(), &address, &port);
            QHostAddress tempipp(address.toIPv4Address());
            if (tempipp.toString() == frenip)
            {
                frenname = datagram.data();
                socket2.close();
                ipwait.setText(frenname + " connected with ip: " + frenip);
                mainpage.addWidget(&ipwait);
                qDebug() << datagram.data() << tempipp;
                conn2();
                nono = true;
            }
        }
    });
}

void Widget::conn2()
{
    playthedamngame();
    ipwait.hide();
    QHostAddress frenaddress(frenip);
    if (!socket2.bind(55556, QUdpSocket::ShareAddress))
    {
        qDebug() << "Chyba pri inicializaci socketu";
    }
    QObject::connect(&socket2, &QUdpSocket::readyRead, [&]()
    {
        QByteArray datagram;
        datagram.resize(socket2.pendingDatagramSize());
        QHostAddress address;
        quint16 port;
        socket2.readDatagram(datagram.data(), datagram.size(), &address, &port);
        QHostAddress tempipp(address.toIPv4Address());
        if (tempipp.toString() == frenip)
        {
            qDebug() << datagram.data();
            QString te = datagram.data();
            mancl.x = te.toInt();
            int r = mancl.moveb();
            if (r == 0)
            {
                enbu();
            }
            int w = mancl.check(aas, bbs, abowl, bbowl, bss);
            if (w == 1)
            {
                win();
            }
            else if (w == 2)
            {
                nowin();
            }
            else if (w == 3)
            {
                bothwin();
            }
        }
    });
}

void Widget::connsend(int data)
{
    QString temp;
    temp.setNum(data);
    QHostAddress frenaddress(frenip);
    QByteArray datagram2 = temp.toUtf8();
    socket.writeDatagram(datagram2.data(), datagram2.size(), frenaddress, 55555);
}

void Widget::timer(int delay)
{
    QTimer timer;
    timer.setInterval(delay);
    QEventLoop loop;
    connect(&timer, SIGNAL(timeout()), &loop, SLOT(quit()));
    timer.start();
    loop.exec();
}

void Widget::playthedamngame()
{
    dibu();
    if (mmmm == true)
    {
        enbu();
    }
    QString tempwins;
    tempwins.setNum(wins);
    mn.setText(myname + " (" + tempwins + ")");
    fn.setText(frenname);
    abowl.setText("0");
    bbowl.setText("0");
    aas.push_back(&a5);
    aas.push_back(&a4);
    aas.push_back(&a3);
    aas.push_back(&a2);
    aas.push_back(&a1);
    aas.push_back(&a0);
    bbs.push_back(&b0);
    bbs.push_back(&b1);
    bbs.push_back(&b2);
    bbs.push_back(&b3);
    bbs.push_back(&b4);
    bbs.push_back(&b5);
    bss.push_back(&bs0);
    bss.push_back(&bs1);
    bss.push_back(&bs2);
    bss.push_back(&bs3);
    bss.push_back(&bs4);
    bss.push_back(&bs5);
    for (auto i : aas)
    {
        left.addWidget(i,Qt::AlignCenter,Qt::AlignCenter);
        i->setText("4");
    }
    for (auto i : bbs)
    {
        right.addWidget(i,Qt::AlignCenter,Qt::AlignCenter);
        i->setText("4");
    }
    mancaladis.addLayout(&left);
    mancaladis.addLayout(&right);
    nameese.addWidget(&mn,Qt::AlignCenter,Qt::AlignCenter);
    nameese.addWidget(&fn,Qt::AlignCenter,Qt::AlignCenter);
    mancccc.addLayout(&nameese,Qt::AlignCenter);
    mancccc.addWidget(&bbowl,Qt::AlignCenter,Qt::AlignCenter);
    mancccc.addLayout(&mancaladis,Qt::AlignCenter);
    mancccc.addWidget(&abowl,Qt::AlignCenter,Qt::AlignCenter);
    mancccc.addWidget(&tirn);
    mainpage.addLayout(&mancccc);
}

void Widget::playgame2()
{
    enbu();
    QString tempwins;
    tempwins.setNum(wins);
    mn.setText(myname + " (" + tempwins + ")");
    fn.setText(frenname);
    abowl.setText("0");
    bbowl.setText("0");
    aas.push_back(&a5);
    aas.push_back(&a4);
    aas.push_back(&a3);
    aas.push_back(&a2);
    aas.push_back(&a1);
    aas.push_back(&a0);
    bbs.push_back(&b0);
    bbs.push_back(&b1);
    bbs.push_back(&b2);
    bbs.push_back(&b3);
    bbs.push_back(&b4);
    bbs.push_back(&b5);
    bss.push_back(&bs0);
    bss.push_back(&bs1);
    bss.push_back(&bs2);
    bss.push_back(&bs3);
    bss.push_back(&bs4);
    bss.push_back(&bs5);
    for (auto i : aas)
    {
        left.addWidget(i,Qt::AlignCenter,Qt::AlignCenter);
        i->setText("4");
    }
    for (auto i : bss)
    {
        right.addWidget(i,Qt::AlignCenter,Qt::AlignCenter);
        i->setText("4");
    }
    mancaladis.addLayout(&left);
    mancaladis.addLayout(&right);
    nameese.addWidget(&mn,Qt::AlignCenter,Qt::AlignCenter);
    nameese.addWidget(&fn,Qt::AlignCenter,Qt::AlignCenter);
    mancccc.addLayout(&nameese,Qt::AlignCenter);
    mancccc.addWidget(&bbowl,Qt::AlignCenter,Qt::AlignCenter);
    mancccc.addLayout(&mancaladis,Qt::AlignCenter);
    mancccc.addWidget(&abowl,Qt::AlignCenter,Qt::AlignCenter);
    mancccc.addWidget(&tirn);
    mainpage.addLayout(&mancccc);
}

void Widget::enbu()
{
    if (sinn == false)
    {
        tirn.setText("your turn. c:");
        a0.setEnabled(true);
        a1.setEnabled(true);
        a2.setEnabled(true);
        a3.setEnabled(true);
        a4.setEnabled(true);
        a5.setEnabled(true);
    }
    else
    {
        tirn.setText(myname + "'s turn. c:");
        a0.setEnabled(true);
        a1.setEnabled(true);
        a2.setEnabled(true);
        a3.setEnabled(true);
        a4.setEnabled(true);
        a5.setEnabled(true);
        bs0.setEnabled(false);
        bs1.setEnabled(false);
        bs2.setEnabled(false);
        bs3.setEnabled(false);
        bs4.setEnabled(false);
        bs5.setEnabled(false);
    }
}

void Widget::dibu()
{
    if (sinn == false)
    {
        QStringList tempften = frenname.split('(');
        tempften[0].resize(tempften[0].size()-1);
        tirn.setText("wait for " + tempften[0] + " to make their turn. c:");
        a0.setEnabled(false);
        a1.setEnabled(false);
        a2.setEnabled(false);
        a3.setEnabled(false);
        a4.setEnabled(false);
        a5.setEnabled(false);
    }
    else
    {
        tirn.setText("player 2's turn. c:");
        a0.setEnabled(false);
        a1.setEnabled(false);
        a2.setEnabled(false);
        a3.setEnabled(false);
        a4.setEnabled(false);
        a5.setEnabled(false);
        bs0.setEnabled(true);
        bs1.setEnabled(true);
        bs2.setEnabled(true);
        bs3.setEnabled(true);
        bs4.setEnabled(true);
        bs5.setEnabled(true);
    }
}

void Widget::changen()
{
    QFile settings(setpath + "/settings");
    QString tempwins;
    tempwins.setNum(wins);
    QStringList tempo = QHostInfo::localHostName().split('.');
    QStringList tempoo = tempo[0].split('-');
    myname = QInputDialog::getText(this, "mancala.", "choose your name", QLineEdit::Normal, tempoo[0]);
    settings.open(QIODevice::ReadWrite | QIODevice::Truncate);
    QTextStream txtStream(&settings);
    txtStream << myname;
    txtStream << "\n" << tempwins << "\nplsdonotchange:3";
    settings.close();
    if (wins == 0)
    {
        tempwins += " wins :c";
    }
    else if (wins == 1)
    {
        tempwins += " win!";
    }
    else
    {
        tempwins += " wins!";
    }
    usern.setText("welcome " + myname + "\nyou have " + tempwins);
}

void Widget::win()
{
    wins = wins + 1;
    QFile settings(setpath + "/settings");
    QString tempwins;
    tempwins.setNum(wins);
    settings.open(QIODevice::ReadWrite | QIODevice::Truncate);
    QTextStream txtStream(&settings);
    txtStream << myname;
    txtStream << "\n" << tempwins << "\nplsdonotchange:3";
    settings.close();
    mn.setText(myname + " (" + tempwins + ")");
    if (wins == 1)
    {
        if (sinn == false)
        {
            tempwins = "your first win!";
        }
        else
        {
            tempwins = "their first win!";
        }
    }
    else
    {
        tempwins += " wins total!";
    }
    dibu();
    if (sinn == false)
    {
        tirn.setText("you won! you have " + tempwins);
    }
    else
    {
        enbu();
        sinn = false;
        dibu();
        sinn = true;
        tirn.setText(myname + " won! they have " + tempwins);
    }
}

void Widget::nowin()
{
    dibu();
    if (sinn == false)
    {
        QStringList frwinz = frenname.split('(');
        QStringList frwinzs = frwinz[1].split(')');
        int frwins = frwinzs[0].toInt();
        QString frwitemp;
        frwitemp.setNum(frwins + 1);
        frenname = frwinz[0] + "(" + frwitemp + ")";
        fn.setText(frenname);
        tirn.setText("you didn't win, maybe next time c:");
    }
    else
    {
        enbu();
        sinn = false;
        dibu();
        sinn = true;
        tirn.setText("player 2 won!");
    }
}

void Widget::bothwin()
{
    wins = wins + 1;
    QFile settings(setpath + "/settings");
    QString tempwins;
    tempwins.setNum(wins);
    settings.open(QIODevice::ReadWrite | QIODevice::Truncate);
    QTextStream txtStream(&settings);
    txtStream << myname;
    txtStream << "\n" << tempwins << "\nplsdonotchange:3";
    settings.close();
    mn.setText(myname + " (" + tempwins + ")");
    if (wins == 1)
    {
        if (sinn == false)
        {
            tempwins = "your first win!";
        }
        else
        {
            tempwins = "their first win!";
        }
    }
    else
    {
        tempwins += " wins total!";
    }
    dibu();
    if (sinn == false)
    {
        tirn.setText("you both won! you have " + tempwins);
        QStringList frwinz = frenname.split('(');
        QStringList frwinzs = frwinz[1].split(')');
        int frwins = frwinzs[0].toInt();
        QString frwitemp;
        frwitemp.setNum(frwins + 1);
        frenname = frwinz[0] + "(" + frwitemp + ")";
        fn.setText(frenname);
        tirn.setText("you didn't win, maybe next time c:");
    }
    else
    {
        enbu();
        sinn = false;
        dibu();
        sinn = true;
        tirn.setText("you both won!" + myname + "has " + tempwins);
    }
}

Widget::~Widget() {}