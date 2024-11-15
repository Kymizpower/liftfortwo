#ifndef LIFT_H
#define LIFT_H

#include <QLabel>

class QTableWidget;

class lift
{
public:
    lift(QTableWidget *table);
    void moveUp();
    void moveDown();
    void setToBottom();

private:
    QTableWidget *tableWidget;
    QLabel *liftLabel;  // QLabel для отображения картинки
    int currentRow;
};

#endif // LIFT_H
