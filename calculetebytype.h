#ifndef CALCULETEBYTYPE_H
#define CALCULETEBYTYPE_H

#include<calculete.h>
#include <map>
#include<QFileInfo>
#include<QDirIterator>

class CalculeteByType : public Calculete
{
public:
    CalculeteByType()= default;
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
            std::map<QString,qint64> typeGrouped;
            for (int i = 0; i< fileData.length();i++ ){
                typeGrouped[fileData[i].suffix()] += fileData[i].size();
            }
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
