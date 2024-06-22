#include <QCoreApplication>
#include<iostream>
#include <chartdata.h>
#include <calculetebysize.h>
#include <calculetebytype.h>
#include <calculetebysubdirs.h>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    CalculeteBySize calculeteBySize;
    CalculeteBySubDirs calculeteBySubDirs;
    CalculeteByType calculeteByType;
    QVector<ChartData> chartData = calculeteBySize.calculeteByPath("/lab1ramina");
    std::cout << "--------------------------------------------by files size-------------------------------------" << std::endl;
    for (int i = 0; i< chartData.length();i++){
        std::cout << chartData[i].getLabel().toStdString() << "   " << chartData[i].getProcentSize() << std::endl;
    }
    std::cout << "--------------------------------------------by dirs size--------------------------------------" << std::endl;
    chartData = calculeteBySubDirs.calculeteByPath("C:/Users/Ramina/Documents/Lab3_CalculationStrategy/lab1ramina");
    for (int i = 0; i< chartData.length();i++){
        std::cout << chartData[i].getLabel().toStdString() << "   " << chartData[i].getProcentSize() << std::endl;
    }
    std::cout << "--------------------------------------------by types size-------------------------------------" << std::endl;
    chartData = calculeteByType.calculeteByPath("C:/Users/Ramina/Documents/Lab3_CalculationStrategy/lab1ramina");
    for (int i = 0; i< chartData.length();i++){
        std::cout << chartData[i].getLabel().toStdString() << "   " << chartData[i].getProcentSize() << std::endl;
    }
    return a.exec();
}
