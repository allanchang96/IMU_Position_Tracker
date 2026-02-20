#ifndef ACCELEROMETER_H
#define ACCELEROMETER_H

#include "quaternion.h"

// Updates position and velocity based on accelerometer measurement in metres per second ^ 2
void Accelerometer_updatePosition(Quaternion acc);

void Accelerometer_resetVelocity();

// Also resets the velocity
void Accelerometer_resetPosition();

Quaternion Accelerometer_getPosition();

#endif // ACCELEROMETER.H