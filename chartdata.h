#ifndef CHARTDATA_H
#define CHARTDATA_H

#include <QString>// Включение библиотеки Qt для работы с классом QString, представляющим строки текста

// Определение класса ChartData
class ChartData
{
public:
    // Конструктор класса, принимающий новую метку и процент размера
    ChartData(QString newLabel, float newProcentSize){
        label = newLabel;// Инициализация метки
        procentSize = newProcentSize;// Инициализация процента размера
    }

    // Метод для получения значения процента размера
    float getProcentSize(){
        return procentSize;
    }

    // Метод для получения метки
    QString getLabel(){
        return label;
    }
protected:
    float procentSize = 0;// Защищенное поле для хранения процента размера, инициализируется значением 0
    QString label = "";// Защищенное поле для хранения метки, инициализируется пустой строкой
};

// Предполагаемый конец файла (обычно используется для предотвращения множественного включения)
#endif // CHARTDATA_H
