#ifndef mancala_h
#define mancala_h

#include <QDebug>
#include <QPushButton>
#include <QVector>
#include <QLabel>

class mancala
{
    int a[6] = {4,4,4,4,4,4};
    int abowl = 0;
    int b[6] = {4,4,4,4,4,4};
    int bbowl = 0;
public:
    int x = 0;
    int movea();
    int moveb();
    int check(QVector<QPushButton *> &aext, QVector<QLabel *> &bext, QLabel &abowlext, QLabel &bbowlext, QVector<QPushButton *> &bsext);
};

#endif /* mancala_h */
