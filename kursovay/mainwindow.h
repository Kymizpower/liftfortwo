#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QSpinBox>
#include <QMainWindow>
#include <QLabel>
#include <QPushButton>
#include"lift.h"
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QTableWidget * entrance_1, *entrance_2;

    lift *lift1;  // Указатель на первый лифт
    lift *lift2;  // Указатель на второй лифт
    QSpinBox *spawn_floor_1, *target_floor_1, *spawn_floor_2, *target_floor_2;
    QLabel *spawn_floor_text_1, *target_floor_text_1, *spawn_floor_text_2, *target_floor_text_2;
    QPushButton *spawn_1, *spawn_2, *spawn_randomly_1, *spawn_randomly_2, *start;
private slots:
    void spawnPerson(int entranceNum);
    //void resetSpawnColumn(int entranceNum);
};
#endif // MAINWINDOW_H
