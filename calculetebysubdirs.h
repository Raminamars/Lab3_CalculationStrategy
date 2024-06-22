#ifndef CALCULETEBYSUBDIRS_H
#define CALCULETEBYSUBDIRS_H

#include<calculete.h>
#include <map>
#include<QFileInfo>
#include<QDirIterator>
#include<iostream>

class CalculeteBySubDirs : public Calculete
{
public:
    CalculeteBySubDirs()= default;
    QVector<ChartData> calculeteByPath(QString path){
        QVector<ChartData> chartData;
        QFileInfo file(path);
        if (file.isDir()){
            QDirIterator it(path, QDir::Dirs | QDir::NoDotAndDotDot);
            std::map<QString,qint64> dirGrouped;
            while (it.hasNext()){
                QVector<QFileInfo> fileData;
                QString dirPath = it.next();
                QDirIterator itSubDir(dirPath,QDirIterator::Subdirectories);
                while (itSubDir.hasNext()){
                    QFileInfo itFile(itSubDir.next());
                    if (itFile.size()!=0){
                        fileData.push_back(itFile);
                    }
                }
                qint64 dirSize = 0;
                for (int i = 0; i< fileData.length();i++){
                    dirSize += fileData[i].size();
                }
                dirGrouped[dirPath] += dirSize;
            }
            qint64 totalSize = 0;
             for (auto &item : dirGrouped){
                totalSize += item.second;
            }
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
