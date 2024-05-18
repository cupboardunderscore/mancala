#include "mancala.h"

int mancala::movea()
{
    if (a[x] == 0)
    {
        return 1;
    }
    int z = 0;
    int temp = a[x];
    a[x] = 0;
    x = x - 1;
    while (temp > 0)
    {
        if (z == 0)
        {
            while (x >= 0)
            {
                a[x] = a[x] + 1;
                temp = temp - 1;
                if (temp == 0)
                {
                    if (a[x] == 1 && b[5-x] !=0)
                    {
                        abowl = abowl + 1 + b[5-x];
                        a[x] = 0;
                        b[5-x] = 0;
                    }
                    break;
                }
                x = x - 1;
            }
            if (x < 0)
            {
                abowl = abowl + 1;
                temp = temp - 1;
                if (temp == 0)
                {
                    return 1;
                }
                z = 1;
                x = 5;
            }
        }
        else if (z == 1)
        {
            while (x >= 0)
            {
                b[x] = b[x] + 1;
                temp = temp - 1;
                if (temp == 0)
                {
                    break;
                }
                x = x - 1;
            }
            if (x < 0)
            {
                z = 0;
                x = 5;
            }
        }
    }
    return 0;
}

int mancala::moveb()
{
    if (b[x] == 0)
    {
        return 1;
    }
    int z = 0;
    int temp = b[x];
    b[x] = 0;
    x = x - 1;
    while (temp > 0)
    {
        if (z == 0)
        {
            while (x >= 0)
            {
                b[x] = b[x] + 1;
                temp = temp - 1;
                if (temp == 0)
                {
                    if (b[x] == 1 && a[5-x] != 0)
                    {
                        bbowl = bbowl + 1 + a[5-x];
                        b[x] = 0;
                        a[5-x] = 0;
                    }
                    break;
                }
                x = x - 1;
            }
            if (x < 0)
            {
                bbowl = bbowl + 1;
                temp = temp - 1;
                if (temp == 0)
                {
                    return 1;
                }
                z = 1;
                x = 5;
            }
        }
        else if (z == 1)
        {
            while (x >= 0)
            {
                a[x] = a[x] + 1;
                temp = temp - 1;
                if (temp == 0)
                {
                    break;
                }
                x = x - 1;
            }
            if (x < 0)
            {
                z = 0;
                x = 5;
            }
        }
    }
    return 0;
}

int mancala::check(QVector<QPushButton *> &aext, QVector<QLabel *> &bext, QLabel &abowlext, QLabel &bbowlext, QVector<QPushButton *> &bsext)
{
    bool z = false;
    if (a[0]+a[1]+a[2]+a[3]+a[4]+a[5]+abowl+b[0]+b[1]+b[2]+b[3]+b[4]+b[5]+bbowl != 48)
    {
        qDebug() << "count err";
    }
    if (a[0]+a[1]+a[2]+a[3]+a[4]+a[5] == 0)
    {
        bbowl = bbowl + b[0]+b[1]+b[2]+b[3]+b[4]+b[5];
        for (int i = 0; i < 6; i++)
        {
            b[i] = 0;
        }
        z = true;
    }
    else if (b[0]+b[1]+b[2]+b[3]+b[4]+b[5] == 0)
    {
        abowl = abowl + a[0]+a[1]+a[2]+a[3]+a[4]+a[5];
        for (int i = 0; i < 6; i++)
        {
            a[i] = 0;
        }
        z = true;
    }
    for (int i = 0; i < 6; i++)
    {
        QString temp;
        temp.setNum(b[i]);
        bext[i]->setText(temp);
        bsext[i]->setText(temp);
    }
    for (int i = 0; i < 6; i++)
    {
        QString temp;
        temp.setNum(a[5-i]);
        aext[i]->setText(temp);
    }
    QString tempa, tempb;
    tempa.setNum(abowl);
    tempb.setNum(bbowl);
    abowlext.setText(tempa);
    bbowlext.setText(tempb);
    if (z == true)
    {
        if (abowl > bbowl)
        {
            return 1;
        }
        else if (abowl < bbowl)
        {
            return 2;
        }
        else if (abowl == bbowl)
        {
            return 3;
        }
    }
    return 0;
}
