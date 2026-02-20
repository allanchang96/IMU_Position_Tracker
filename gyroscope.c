#include "gyroscope.h"
#include "quaternion.h"

#include <math.h>

// Period per gyroscope poll
static float Ts = 0;

// Orientation from fixed frame to moving frame
static Quaternion orientation = {1, 0, 0, 0};

void Gyroscope_updateOrientation(Quaternion rotatingW)
{
    // https://www.st.com/resource/en/design_tip/dt0060-exploiting-the-gyroscope-to-update-tilt-measurement-and-ecompass-stmicroelectronics.pdf
    float W = sqrt(rotatingW.x * 2 + rotatingW.y * 2 + rotatingW.z * 2);
    float C = cos(W * Ts / 2);
    float S = sin(W * Ts / 2);
    Quaternion E = {C, S * rotatingW.x / W, S * rotatingW.y / W, S * rotatingW.z / W};
    orientation = Quaternion_normalize(Quaternion_multiply(orientation, E));
}

void Gyroscope_resetOrientation()
{
    orientation = (Quaternion){1, 0, 0, 0};
}

Quaternion Gyroscope_getOrientation()
{
    return orientation;
}