#ifndef CALCULETE_H
#define CALCULETE_H

#include<chartdata.h>

// Определение класса Calculete
class Calculete
{
public:
    // Конструктор по умолчанию
    Calculete()= default;

    // Виртуальный метод для расчета данных по указанному пути
    virtual QVector<ChartData> calculeteByPath(QString path);

    // Метод для расчета процента от общего значения
    double calculatePercentage(qint64 value, qint64 total) {
        // Проверка на случай деления на ноль
        if (total == 0) return 0.0;
        // Вычисление процента
        double percentage = (double)(value) / total * 100;
        return percentage;
    }
};

#endif // CALCULETE_H
