#include "lift.h"
#include <QTableWidget>
#include <QLabel>
#include <QTableWidgetItem>

lift::lift(QTableWidget *table)
    : tableWidget(table), currentRow(table->rowCount() - 1)
{
    // Создаем QLabel для изображения и добавляем в таблицу
    liftLabel = new QLabel(tableWidget);
    liftLabel->setPixmap(QPixmap(":/door/door3.png"));  // Устанавливаем картинку из ресурсов
    liftLabel->setScaledContents(true);
    liftLabel->setAlignment(Qt::AlignCenter);
    setToBottom();
}

void lift::moveUp()
{
    if (currentRow > 0) {
        tableWidget->setCellWidget(currentRow, 0, nullptr);  // Убираем картинку из текущей ячейки
        currentRow--;
        tableWidget->setCellWidget(currentRow, 0, liftLabel);  // Устанавливаем картинку в новую ячейку
    }
}

void lift::moveDown()
{
    if (currentRow < tableWidget->rowCount() - 1) {
        tableWidget->setCellWidget(currentRow, 0, nullptr);  // Убираем картинку из текущей ячейки
        currentRow++;
        tableWidget->setCellWidget(currentRow, 0, liftLabel);  // Устанавливаем картинку в новую ячейку
    }
}

void lift::setToBottom()
{
    tableWidget->setCellWidget(currentRow, 0, liftLabel); // Устанавливаем лифт в нижнюю позицию
}

// void lift::moving(){
//     int targetFloor;
//     while (true){

//         targetFloor = this->chooseTargetFloor();
//         do{
//             if (currentFloor == 8 && this->status == UP) this->status = DOWN;
//             if (currentFloor == 0 && this->status == DOWN) this->status = UP;
//             this->takePassangers();
//             if (this->getCurPas() != 0) destFloor = mDestFloor();
//             QThread::msleep(500);
//             if (this->status == UP && this->currentFloor != 8) this->currentFloor++;
//             else if (this->status == DOWN && this->currentFloor != 0) this->currentFloor--;
//             emit (floorChanged(this->currentFloor, this->status));
//             QThread::msleep(500);
//             this->releasePassangers();
//         } while (this->currentFloor != destFloor);
//     }
//     this->status = IDLE;
//     emit passangerReleased(this->currentFloor, this->status);
//     emit finished();
// }

int lift::chooseTargetFloor(){
    int distance_1 = -1, distance_2 = -2, targetFloor_1 = -1, targetFloor_2 = -2;



}
