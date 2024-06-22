#ifndef FILEDATA_H
#define FILEDATA_H

#include <QFileInfo>
#include <QDir>
#include<iostream>

class FileData
{
public:
    FileData(QString newLabel, qint64 newSize){
        label = newLabel;
        size = newSize;
    }
    qint64 getSize(){
        return size;
    }
    QString getLabel(){
        return label;
    }
protected:
    qint64 size = 0;
    QString label = "";
};

#endif // FILEDATA_H
