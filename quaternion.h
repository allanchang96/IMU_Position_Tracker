#ifndef QUATERNION_H
#define QUATERNION_H

typedef struct Quaternion
{
    float w, x, y, z;
} Quaternion;

Quaternion Quaternion_addition(Quaternion q1, Quaternion q2);

Quaternion Quaternion_multiply(Quaternion q1, Quaternion q2);

Quaternion Quaternion_scalarMultiply(Quaternion q1, float c);

Quaternion Quaternion_normalize(Quaternion q);

Quaternion Quaternion_conjugate(Quaternion q);

#endif // QUATERNION.H