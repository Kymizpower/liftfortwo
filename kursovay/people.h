#ifndef PEOPLE_H
#define PEOPLE_H

#include <QString>
#include <QIcon>

class people
{
public:
    //people(int spawnFloor, int targetFloor);
    people(int spawnFloor, int targetFloor, const QString& iconPath);

    int getSpawnFloor() const;
    int getTargetFloor() const;
    QIcon getIcon() const;  // Метод для получения изображения человека

    void setPersonImage(int spawnFloor);  // Метод для назначения изображения


    int getColumn() const;  // Метод для получения номера столбца

private:
    int spawnFloor;
    int targetFloor;
    QIcon icon;  // Картинка для объекта человека
};

#endif // PEOPLE_H
