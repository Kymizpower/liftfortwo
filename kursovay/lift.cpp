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
