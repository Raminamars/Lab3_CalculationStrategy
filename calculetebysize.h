#ifndef CALCULETEBYSIZE_H
#define CALCULETEBYSIZE_H

#include <calculete.h>
#include <QDirIterator>
#include <filedata.h>

class CalculeteBySize : public Calculete
{
public:
    CalculeteBySize()= default;
    QVector<ChartData> calculeteByPath(QString path){
        QVector<ChartData> chartData;
        QVector<QFileInfo> fileData;
        QFileInfo file(path);
        if (file.isDir()){
            QDirIterator it(path, QDirIterator::Subdirectories);
            while (it.hasNext()){
                QFileInfo itFile(it.next());
                if (itFile.size()!=0){
                    fileData.push_back(itFile);
                }
            }
            qint64 dirSize = 0;
            for (int i = 0; i< fileData.length();i++){
                dirSize += fileData[i].size();
            }
            for (int i = 0; i< fileData.length();i++ ){
                chartData.push_back(ChartData(fileData[i].fileName(), calculatePercentage(fileData[i].size(),dirSize)));
            }
        } else {
           //TODO : обработать случай когда пользователь выбирает не директорию
        }
        return chartData;
    }
};

#endif // CALCULETEBYSIZE_H
