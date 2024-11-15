#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "lift.h"
#include "people.h"
#include <QVector>
#include <QRandomGenerator>
#include <QApplication>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QMainWindow>
#include <QHeaderView>  // Добавляем для использования QHeaderView


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->resize(800, 800);

    // первый подъезд
    entrance_1 = new QTableWidget(9, 4, this);
    entrance_1->setFixedSize(290, 550);
    entrance_1->move(25, 25);
    entrance_1->horizontalHeader()->setSectionResizeMode(3, QHeaderView::Stretch);
    entrance_1->setColumnWidth(0, 80);
    entrance_1->setColumnWidth(1, 65);
    entrance_1->setColumnWidth(2, 65);
    entrance_1->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    QStringList headers_1 = {"Elevator 1", "Human 1", "Human 2", "Human 3"};
    entrance_1->setHorizontalHeaderLabels(headers_1);

    spawn_floor_1 = new QSpinBox(this);
    spawn_floor_1->setGeometry(275, 600, 80, 30);

    target_floor_1 = new QSpinBox(this);
    target_floor_1->setGeometry(275, 650, 80, 30);

    spawn_floor_text_1 = new QLabel("Spawn floor",this);
    spawn_floor_text_1->setGeometry(200, 600, 80, 30);

    target_floor_text_1 = new QLabel("Target floor",this);
    target_floor_text_1->setGeometry(200, 650, 80, 30);

    spawn_1 = new QPushButton("Spawn", this);
    spawn_1->setGeometry(275, 700, 80, 30);

    spawn_randomly_1 = new QPushButton("Spawn randomly", this);
    spawn_randomly_1->setGeometry(25, 650, 100, 30);

    // второй подъезд
    entrance_2 = new QTableWidget(9, 4, this);
    entrance_2->setFixedSize(290, 550);
    entrance_2->move(413, 25);
    entrance_2->horizontalHeader()->setSectionResizeMode(3, QHeaderView::Stretch);
    entrance_2->setColumnWidth(0, 80);
    entrance_2->setColumnWidth(1, 65);
    entrance_2->setColumnWidth(2, 65);
    entrance_2->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    QStringList headers_2 = {"Elevator 2", "Human 1", "Human 2", "Human 3"};
    entrance_2->setHorizontalHeaderLabels(headers_2);

    spawn_floor_2 = new QSpinBox(this);
    spawn_floor_2->setGeometry(663, 600, 80, 30);

    target_floor_2 = new QSpinBox(this);
    target_floor_2->setGeometry(663, 650, 80, 30);

    spawn_floor_text_2 = new QLabel("Spawn floor",this);
    spawn_floor_text_2->setGeometry(588, 600, 80, 30);

    target_floor_text_2 = new QLabel("Target floor",this);
    target_floor_text_2->setGeometry(588, 650, 80, 30);

    spawn_2 = new QPushButton("Spawn", this);
    spawn_2->setGeometry(663, 700, 80, 30);

    spawn_randomly_2 = new QPushButton("Spawn randomly", this);
    spawn_randomly_2->setGeometry(413, 650, 100, 30);


    start = new QPushButton("Start", this);
    start->setGeometry(250, 737, 300, 50);


    // Устанавливаем таблицу как центральный виджет
    //setCentralWidget(entrance_1);
    lift1 = new lift(entrance_1);  // Лифт в первой таблице
    lift2 = new lift(entrance_2);  // Лифт во второй таблице






    connect(spawn_1, &QPushButton::clicked, this, [this](){ spawnPerson(1); });
    connect(spawn_2, &QPushButton::clicked, this, [this](){ spawnPerson(2); });
}






QVector<people*> peopleList1; // Массив людей для первого подъезда
QVector<people*> peopleList2; // Массив людей для второго подъезда
int currentColumn1 = 1; // Текущий столбец для первого подъезда (начинаем со 2-го столбца)
int currentColumn2 = 1; // Текущий столбец для второго подъезда (начинаем со 2-го столбца)


/*void MainWindow::spawnPerson(int entranceNum)
{
    int spawnFloor = (entranceNum == 1) ? spawn_floor_1->value() : spawn_floor_2->value();
    int targetFloor = (entranceNum == 1) ? target_floor_1->value() : target_floor_2->value();

    // Если значения spinbox изменились, сбрасываем столбец для спавна
    if ((entranceNum == 1 && currentColumn1 > 3) || (entranceNum == 2 && currentColumn2 > 3)) {
        // Сброс столбца при изменении значений
        if (entranceNum == 1) {
            currentColumn1 = 1;  // Начинаем с 2-го столбца для первого подъезда
        } else {
            currentColumn2 = 1;  // Начинаем с 2-го столбца для второго подъезда
        }
    }

    // Проверяем доступный столбец
    int& currentColumn = (entranceNum == 1) ? currentColumn1 : currentColumn2;
    if (currentColumn > 3) return;  // Ограничение на 3 столбца для спавна

    QTableWidget* entranceTable = (entranceNum == 1) ? entrance_1 : entrance_2;
    QVector<people*>& peopleList = (entranceNum == 1) ? peopleList1 : peopleList2;


    // Определяем иконку на основе пола и targetFloor
    QString gender = (targetFloor % 2 == 0) ? "Woman" : "Man";
    QString iconPath = QString(":/resource/icon/%1_%2").arg(gender).arg(targetFloor);


    // Создаем объект человека и добавляем его в список
    people* newPerson = new people(spawnFloor, targetFloor, iconPath);
    peopleList.append(newPerson);

    // Добавляем человека в таблицу на указанном этаже и столбце
    QTableWidgetItem* personItem = new QTableWidgetItem("Person");
    entranceTable->setItem(9 - spawnFloor, currentColumn, personItem); // Используем 8 - spawnFloor для обратного порядка этажей

    // Переходим к следующему столбцу для спавна
    currentColumn++;
}
*/




void MainWindow::spawnPerson(int entranceNum)
{
    int spawnFloor = (entranceNum == 1) ? spawn_floor_1->value() : spawn_floor_2->value();
    int targetFloor = (entranceNum == 1) ? target_floor_1->value() : target_floor_2->value();

    // Сброс колонки, если нужно
    int& currentColumn = (entranceNum == 1) ? currentColumn1 : currentColumn2;
    if (currentColumn > 3) currentColumn = 1;

    QTableWidget* entranceTable = (entranceNum == 1) ? entrance_1 : entrance_2;
    QVector<people*>& peopleList = (entranceNum == 1) ? peopleList1 : peopleList2;

    // Рандомный выбор пола
    QString gender = (QRandomGenerator::global()->bounded(2) == 0) ? "Man" : "Woman";
    QString iconPath = QString(":/people/resource/%1_%2.png").arg(gender).arg(targetFloor);

    // Создаем объект человека с картинкой
    people* newPerson = new people(spawnFloor, targetFloor, iconPath);
    peopleList.append(newPerson);

    // Устанавливаем картинку, растягивая ее на всю ячейку
    QTableWidgetItem* personItem = new QTableWidgetItem();
    personItem->setIcon(newPerson->getIcon());
    personItem->setTextAlignment(Qt::AlignCenter);  // Центрируем, если есть текст (опционально)
    entranceTable->setItem(9 - spawnFloor, currentColumn, personItem);
    entranceTable->setIconSize(QSize(entranceTable->columnWidth(currentColumn),
                                     entranceTable->rowHeight(9 - spawnFloor)));

    currentColumn++;
}



MainWindow::~MainWindow()
{
    delete ui;
    delete lift1;
    delete lift2;
}
