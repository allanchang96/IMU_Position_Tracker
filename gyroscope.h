#ifndef GYROSCOPE_H
#define GYROSCOPE_H

#include "quaternion.h"

// Updates orientation based on gyroscope measurement in radians per second
void Gyroscope_updateOrientation(Quaternion W);

void Gyroscope_resetOrientation();
Quaternion Gyroscope_getOrientation();

void Gyroscope_setPeriod(float periodDuration);

#endif // GYROSCOPE.H