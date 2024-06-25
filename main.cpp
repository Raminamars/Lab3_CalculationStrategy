#include <QCoreApplication>// Включение библиотеки Qt для создания консольного приложения
#include<iostream>// Включение стандартной библиотеки C++ для ввода-вывода
#include <chartdata.h>
#include <calculetebysize.h>
#include <calculetebytype.h>
#include <calculetebysubdirs.h>

int main(int argc, char *argv[])
{// Создание объекта приложения Qt
    QCoreApplication a(argc, argv);

    // Создание объектов различных стратегий для расчетов
    CalculeteBySize calculeteBySize;
    CalculeteBySubDirs calculeteBySubDirs;
    CalculeteByType calculeteByType;

    // Расчет данных по размеру файлов в указанном пути
    QVector<ChartData> chartData = calculeteBySize.calculeteByPath("/lab1ramina");
    // Вывод заголовка для данных, рассчитанных по размеру файлов
    std::cout << "--------------------------------------------by files size-------------------------------------" << std::endl;
    // Вывод данных по размеру файлов
    for (int i = 0; i< chartData.length();i++){
        std::cout << chartData[i].getLabel().toStdString() << "   " << chartData[i].getProcentSize() << std::endl;
    }

    // Вывод заголовка для данных, рассчитанных по размеру поддиректорий
    std::cout << "--------------------------------------------by dirs size--------------------------------------" << std::endl;
    // Расчет данных по размеру поддиректорий в указанном пути
    chartData = calculeteBySubDirs.calculeteByPath("C:/Users/Ramina/Documents/Lab3_CalculationStrategy/lab1ramina");
    // Вывод данных по размеру поддиректорий
    for (int i = 0; i< chartData.length();i++){
        std::cout << chartData[i].getLabel().toStdString() << "   " << chartData[i].getProcentSize() << std::endl;
    }

    // Вывод заголовка для данных, рассчитанных по типам файлов
    std::cout << "--------------------------------------------by types size-------------------------------------" << std::endl;
    // Расчет данных по типам файлов в указанном пути
    chartData = calculeteByType.calculeteByPath("C:/Users/Ramina/Documents/Lab3_CalculationStrategy/lab1ramina");
    // Вывод данных по типам файлов
    for (int i = 0; i< chartData.length();i++){
        std::cout << chartData[i].getLabel().toStdString() << "   " << chartData[i].getProcentSize() << std::endl;
    }

    // Запуск основного цикла приложения Qt
    return a.exec();
}
