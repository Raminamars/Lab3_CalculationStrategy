#include <QCoreApplication>// Включение библиотеки Qt для создания консольного приложения
#include<iostream>// Включение стандартной библиотеки C++ для ввода-вывода
#include <calculetebysize.h>
#include <calculetebytype.h>
#include <calculetebysubdirs.h>
#include <context.h>

int main(int argc, char *argv[])
{// Создание объекта приложения Qt
    QCoreApplication a(argc, argv);

    // Создание объектов различных стратегий для расчетов
    CalculeteBySize* calculeteBySize = new CalculeteBySize();
    CalculeteBySubDirs* calculeteBySubDirs = new CalculeteBySubDirs();
    CalculeteByType* calculeteByType = new CalculeteByType();
    Context* context1 = new Context(calculeteBySize);

    // Расчет данных по размеру файлов в указанном пути
    context1->setCalculate(calculeteBySize);
    QVector<ChartData> chartData = context1->calculeteByPath("/lab1ramina");

    // Вывод заголовка для данных, рассчитанных по размеру файлов
    std::cout << "--------------------------------------------by files size-------------------------------------" << std::endl;
    // Вывод данных по размеру файлов
    for (int i = 0; i< chartData.length();i++){
        if (chartData[i].getProcentSize() >= 0.01 || chartData[i].getProcentSize() == 0)
            std::cout << chartData[i].getLabel().toStdString() << "   " << chartData[i].getProcentSize() << std::endl;
        else
            std::cout << chartData[i].getLabel().toStdString() << "   " << "<0.01%" << std::endl;
    }

    // Вывод заголовка для данных, рассчитанных по размеру поддиректорий
    std::cout << "--------------------------------------------by dirs size--------------------------------------" << std::endl;
    // Расчет данных по размеру поддиректорий в указанном пути

    context1->setCalculate(calculeteBySubDirs);

    chartData = context1->calculeteByPath("C:/Users/Ramina/Documents/Lab3_CalculationStrategy/lab1ramina");
    // Вывод данных по размеру поддиректорий
    for (int i = 0; i< chartData.length();i++){
        if (chartData[i].getProcentSize() >= 0.01 || chartData[i].getProcentSize() == 0)
            std::cout << chartData[i].getLabel().toStdString() << "   " << chartData[i].getProcentSize() << std::endl;
        else
            std::cout << chartData[i].getLabel().toStdString() << "   " << "<0.01%" << std::endl;
    }

    // Вывод заголовка для данных, рассчитанных по типам файлов
    std::cout << "--------------------------------------------by types size-------------------------------------" << std::endl;
    // Расчет данных по типам файлов в указанном пути

    context1->setCalculate(calculeteByType);

    chartData = context1->calculeteByPath("C:/Users/Ramina/Documents/Lab3_CalculationStrategy/lab1ramina");
    // Вывод данных по типам файлов
    for (int i = 0; i< chartData.length();i++){
        if (chartData[i].getProcentSize() >= 0.01 || chartData[i].getProcentSize() == 0)
            std::cout << chartData[i].getLabel().toStdString() << "   " << chartData[i].getProcentSize() << std::endl;
        else
            std::cout << chartData[i].getLabel().toStdString() << "   " << "<0.01%" << std::endl;
    }

    // Запуск основного цикла приложения Qt
    return a.exec();
}
