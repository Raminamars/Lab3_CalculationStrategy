#ifndef CALCULETE_H
#define CALCULETE_H

#include<chartdata.h>

class Calculete
{
public:
    Calculete()= default;
    virtual QVector<ChartData> calculeteByPath(QString path);
    double calculatePercentage(qint64 value, qint64 total) {
        if (total == 0) return 0.0;
        double percentage = static_cast<double>(value) / total * 100;
//        if (percentage < 0.01 && value > 0) {
//            return 0.01; // Если процент < 0.01%, вернуть 0.01%
//        }
        return percentage;
    }
};

#endif // CALCULETE_H
