#ifndef CALCULETEBYTYPE_H
#define CALCULETEBYTYPE_H

#include<calculete.h>

class CalculeteByType : public Calculete
{
public:
    CalculeteByType()= default;
    QVector<ChartData> calculeteByPath(QString path);
};

#endif // CALCULETEBYTYPE_H
