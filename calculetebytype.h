#ifndef CALCULETEBYTYPE_H
#define CALCULETEBYTYPE_H

#include<calculete.h>
#include <map>
#include<QFileInfo>
#include<QDirIterator>

// Определение класса CalculeteByType, наследуемого от базового класса Calculete
class CalculeteByType : public Calculete
{
public:
    // Конструктор по умолчанию
    CalculeteByType()= default;

    // Переопределение виртуального метода для расчета данных по указанному пути
    QVector<ChartData> calculeteByPath(QString path){
        QVector<ChartData> chartData;// Вектор для хранения результатов расчетов
        QVector<QFileInfo> fileData;// Вектор для хранения информации о файлах
        QFileInfo file(path);// Создание объекта QFileInfo для указанного пути

        // Проверка, является ли указанный путь директорией
        if (file.isDir()){
            QDirIterator it(path, QDirIterator::Subdirectories);// Итератор для обхода поддиректорий
            // Итерация по всем файлам в директории и поддиректориях
            while (it.hasNext()){
                QFileInfo itFile(it.next());// Получение информации о следующем файле
                // Проверка, что размер файла не равен нулю
                if (itFile.size()!=0){
                    fileData.push_back(itFile);// Добавление информации о файле в вектор
                }
            }

            qint64 dirSize = 0;// Переменная для хранения общего размера директории
            // Подсчет общего размера всех файлов в директории
            for (int i = 0; i< fileData.length();i++){
                dirSize += fileData[i].size();
            }

            std::map<QString,qint64> typeGrouped;// Контейнер для группировки файлов по их типам и размерам
            // Группировка файлов по их типам (суффиксам) и подсчет их общего размера
            for (int i = 0; i< fileData.length();i++ ){
                typeGrouped[fileData[i].suffix()] += fileData[i].size();
            }

            // Формирование данных для диаграммы с расчетом процентов размера каждого типа файлов
            for (auto &item : typeGrouped) {
                chartData.push_back(ChartData(item.first,calculatePercentage(item.second,dirSize)));
            }
        } else {
            //TODO : обработать случай когда пользователь выбирает не директорию
        }
        return chartData;
    }
};

#endif // CALCULETEBYTYPE_H
