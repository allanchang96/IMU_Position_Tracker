#include "accelerometer.h"

#include "quaternion.h"
#include "gyroscope.h"

// Period per accelerometer poll
static float Ts = 0;

// Represented as pure quaternions to avoid having to create a separate struct
static Quaternion velocity = {0, 0, 0, 0};
static Quaternion position = {0, 0, 0, 0};

static const Quaternion GRAVITY = {0, 0, 0, -9.81};

void Accelerometer_updatePosition(Quaternion rA)
{
    // There is a faster way to compute qpq* which can be implemented if necessary (Fabian Giesen)
    Quaternion orientation = Gyroscope_getOrientation();

    // Convert accelerometer measurements to fixed frame
    Quaternion fA, fV, fD;
    fA = Quaternion_multiply(orientation, rA);
    fA = Quaternion_multiply(fA, Quaternion_conjugate(orientation));

    // Apply gravity correction
    fA = Quaternion_addition(fA, GRAVITY);

    // Compute numerical integration to obtain velocity
    fV = Quaternion_scalarMultiply(fA, Ts);

    velocity = Quaternion_addition(velocity, fV);

    // Compute numerical integration to obtain position
    fD = Quaternion_scalarMultiply(velocity, Ts);

    position = Quaternion_addition(position, fD);
    
    return;
}

void Accelerometer_resetVelocity()
{
    velocity = (Quaternion){0, 0, 0, 0};
}

void Accelerometer_resetPosition()
{
    Accelerometer_resetVelocity();
    position = (Quaternion){0, 0, 0, 0};
}

Quaternion Accelerometer_getPosition()
{
    return position;
}
