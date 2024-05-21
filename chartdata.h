#ifndef CHARTDATA_H
#define CHARTDATA_H

#include <QString>

class ChartData
{
public:
    ChartData(QString newLabel, float newProcentSize){
        label = newLabel;
        procentSize = newProcentSize;
    }
    float getProcentSize(){
        return procentSize;
    }
    QString getLabel(){
        return label;
    }
protected:
    float procentSize = 0;
    QString label = "";
};

#endif // CHARTDATA_H
