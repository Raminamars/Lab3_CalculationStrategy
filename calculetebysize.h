#ifndef CALCULETEBYSIZE_H
#define CALCULETEBYSIZE_H

#include <calculete.h>
#include <QDirIterator>// Включение библиотеки Qt для итерации по директориям

// Определение класса CalculeteBySize, наследуемого от базового класса Calculete
class CalculeteBySize : public Calculete
{
public:
    // Конструктор по умолчанию
    CalculeteBySize()= default;

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
            // Формирование данных для диаграммы с расчетом процентов размера каждого файла
            for (int i = 0; i< fileData.length();i++ ){
                chartData.push_back(ChartData(fileData[i].fileName(), calculatePercentage(fileData[i].size(),dirSize)));
            }
        } else {
           //TODO : обработать случай когда пользователь выбирает не директорию
        }
        return chartData;// Возвращение результатов расчетов
    }
};

#endif // CALCULETEBYSIZE_H
