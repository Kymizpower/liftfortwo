#ifndef LIFT_H
#define LIFT_H

#include <QLabel>
#include <QThread>
#include <QVector>
#include <queue>
//#include "people.h"

class QTableWidget;

class lift
{
public:
    char status;
    lift(QTableWidget *table);
    void moveUp();
    void moveDown();
    void setToBottom();
    void moving();
    //QQueue<int>targetFloors;
    //people inLift[4];

private:
    QTableWidget *tableWidget;
    QLabel *liftLabel;  // QLabel для отображения картинки
    int currentRow;
    int chooseTargetFloor();
};

#endif // LIFT_H
