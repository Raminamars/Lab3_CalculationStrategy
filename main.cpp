#include <QCoreApplication>
#include<filedata.h>
#include<iostream>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    FileData file("C:/lab1ramina");
    std::cout << file.getSize();
    return a.exec();
}
