#include "people.h"

people::people(int spawnFloor, int targetFloor, const QString& iconPath)
    : spawnFloor(spawnFloor), targetFloor(targetFloor), icon(QIcon(iconPath)) {}

int people::getSpawnFloor() const { return spawnFloor; }

int people::getTargetFloor() const { return targetFloor; }

QIcon people::getIcon() const { return icon; }
