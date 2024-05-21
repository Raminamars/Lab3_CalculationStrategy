#ifndef FILEDATA_H
#define FILEDATA_H

#include <QFileInfo>
#include <QDir>
#include<iostream>

class FileData
{
public:
    FileData(QString newPath){
        QFileInfo file(newPath);
        if (file.isDir()){
            std::cout<<"size: ";
            QDir dir(newPath);
            name = dir.dirName();
            type = "dir";
            dir.setFilter(QDir::Files | QDir::Hidden | QDir::NoSymLinks); //устанавливаем фильтр выводимых файлов
            dir.setSorting(QDir::Size | QDir::Reversed); //устанавливаем сортировку "от меньшего к большему"
            QFileInfoList list = dir.entryInfoList(); //получаем список файлов директории
            for (int i = 0; i < list.size(); ++i) {
                size += list.at(i).size();
            }
        } else {
            size = file.size();
            name = file.fileName();
            type = file.completeSuffix();
        }
        path=newPath;
    }
    qint64 getSize(){
        return size;
    }
protected:
    QString path = "";
    qint64 size = 0;
    QString name = "";
    QString type = "";
};

#endif // FILEDATA_H
