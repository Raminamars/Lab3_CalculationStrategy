#include <QCoreApplication>
#include<filedata.h>
#include<iostream>
#include <chartdata.h>
#include <calculetebysize.h>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    CalculeteBySize calc ;
    QVector<ChartData> chartData = calc.calculeteByPath("C:/lab1ramina");
    for (int i = 0; i< chartData.length();i++){
        std::cout << chartData[i].getLabel().toStdString() << chartData[i].getProcentSize() << std::endl;
    }
//    FileData file("C:/lab1ramina");
//    std::cout << file.getSize();
    return a.exec();
}
