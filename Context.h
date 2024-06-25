#ifndef CONTEXT_H
#define CONTEXT_H

#include <calculete.h>

// Определение класса Context
class Context
{
public:
    Context(Calculete* method):method(method) {}// Конструктор, принимающий указатель на объект типа Calculete

    // Метод для выполнения расчета на основе пути к директории
    // Возвращает результат в виде QVector<ChartData>
    QVector<ChartData> calculeteByPath(QString directory) {
        return method->calculeteByPath(directory);
    }

    // Метод для установки нового метода расчета
    void setCalculate(Calculete* ptrmethod) {
        this->method = ptrmethod;
    }
private:
    // Указатель на объект типа Calculete, используемый для выполнения расчетов
    Calculete* method;
};

#endif // CONTEXT_H
