#ifndef _CALCULATOR_HPP_
#define _CALCULATOR_HPP_

#include <QWidget>
#include <QObject>
#include <QDebug>

struct Calculator : QObject
{
    Q_OBJECT

public slots:
    void newDigit(qint32 d)
    {
        qDebug() << "received digit: " << d;
    }
};

#endif // _CALCULATOR_HPP_