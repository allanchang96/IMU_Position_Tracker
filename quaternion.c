#include "quaternion.h"

Quaternion Quaternion_addition(Quaternion q1, Quaternion q2)
{
    Quaternion q;
    q.w = q1.w + q2.w;
    q.x = q1.x + q2.x;
    q.y = q1.y + q2.y;
    q.z = q1.z + q2.z;
    return q;
}

Quaternion Quaternion_multiply(Quaternion q1, Quaternion q2)
{
    Quaternion q;
    q.w = q1.w * q2.w - q1.x * q2.x - q1.y * q2.y - q1.z * q2.z;
    q.x = q1.w * q2.x + q1.x * q2.w + q1.y * q2.z - q1.z * q2.y;
    q.y = q1.w * q2.y - q1.x * q2.z + q1.y * q2.w + q1.z * q2.x;
    q.z = q1.w * q2.z + q1.x * q2.y - q1.y * q2.x + q1.z * q2.w;
    return q;
};

Quaternion Quaternion_scalarMultiply(Quaternion q1, float c)
{
    Quaternion q;
    q.w = q1.w * c;
    q.x = q1.x * c;
    q.y = q1.y * c;
    q.z = q1.z * c;
    return q;
}

Quaternion Quaternion_normalize(Quaternion q)
{
    float Q = q.w * q.w + q.x * q.x + q.y * q.y + q.z * q.z;
    return (Quaternion){q.w / Q, q.x / Q, q.y / Q, q.z / Q};
}

Quaternion Quaternion_conjugate(Quaternion q)
{
    return (Quaternion){q.w, -q.x, -q.y, -q.z};
}