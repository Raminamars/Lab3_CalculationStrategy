#ifndef CALCULETEBYSUBDIRS_H
#define CALCULETEBYSUBDIRS_H

#include<calculete.h>
#include <map>// Включение стандартной библиотеки C++ для работы с контейнером map
#include<QFileInfo>// Включение библиотеки Qt для работы с классом QFileInfo
#include<QDirIterator>
#include<iostream>

// Определение класса CalculeteBySubDirs, наследуемого от базового класса Calculete
class CalculeteBySubDirs : public Calculete
{
public:
    // Конструктор по умолчанию
    CalculeteBySubDirs()= default;

    // Переопределение виртуального метода для расчета данных по указанному пути
    QVector<ChartData> calculeteByPath(QString path){
        QVector<ChartData> chartData;// Вектор для хранения результатов расчетов
        QFileInfo file(path);// Создание объекта QFileInfo для указанного пути

        // Проверка, является ли указанный путь директорией
        if (file.isDir()){
            QDirIterator it(path, QDir::Dirs | QDir::NoDotAndDotDot);// Итератор для обхода поддиректорий
            std::map<QString,qint64> dirGrouped;// Контейнер для группировки директорий и их размеров

            // Итерация по всем поддиректориям
            while (it.hasNext()){
                QVector<QFileInfo> fileData;// Вектор для хранения информации о файлах в поддиректории
                QString dirPath = it.next();// Получение пути к следующей поддиректории

                QDirIterator itSubDir(dirPath,QDirIterator::Subdirectories);// Итератор для обхода поддиректорий
                // Итерация по всем файлам в поддиректории и поддиректориях
                while (itSubDir.hasNext()){
                    QFileInfo itFile(itSubDir.next());// Получение информации о следующем файле
                    // Проверка, что размер файла не равен нулю
                    if (itFile.size()!=0){
                        fileData.push_back(itFile);// Добавление информации о файле в вектор
                    }
                }
                qint64 dirSize = 0;// Переменная для хранения общего размера поддиректории
                // Подсчет общего размера всех файлов в поддиректории
                for (int i = 0; i< fileData.length();i++){
                    dirSize += fileData[i].size();
                }
                // Группировка директорий и их размеров
                dirGrouped[dirPath] += dirSize;
            }
            qint64 totalSize = 0;// Переменная для хранения общего размера всех поддиректорий
            // Подсчет общего размера всех поддиректорий
             for (auto &item : dirGrouped){
                totalSize += item.second;
            }

            // Формирование данных для диаграммы с расчетом процентов размера каждой поддиректории
            for (auto &item : dirGrouped) {
                chartData.push_back(ChartData(item.first,calculatePercentage(item.second,totalSize)));
            }
        } else {
            //TODO : обработать случай когда пользователь выбирает не директорию
        }
        return chartData;
    }
};

#endif // CALCULETEBYSUBDIRS_H
