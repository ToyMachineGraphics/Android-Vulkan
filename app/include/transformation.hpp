#ifndef TRANSFORMATION_H
#define TRANSFORMATION_H

// Row major
template <typename T>
void GetRotationMatrixFromVector(T R[], int length, T rotationVector[], int rotationVectorLength)
{
    float q0;
    float q1 = rotationVector[0];
    float q2 = rotationVector[1];
    float q3 = rotationVector[2];
    if (rotationVectorLength >= 4) {
        q0 = rotationVector[3];
    } else {
        q0 = 1 - q1 * q1 - q2 * q2 - q3 * q3;
        q0 = (q0 > 0) ? sqrt(q0) : 0;
    }
    float sq_q1 = 2 * q1 * q1;
    float sq_q2 = 2 * q2 * q2;
    float sq_q3 = 2 * q3 * q3;
    float q1_q2 = 2 * q1 * q2;
    float q3_q0 = 2 * q3 * q0;
    float q1_q3 = 2 * q1 * q3;
    float q2_q0 = 2 * q2 * q0;
    float q2_q3 = 2 * q2 * q3;
    float q1_q0 = 2 * q1 * q0;
    if (length == 9) {
        R[0] = 1 - sq_q2 - sq_q3;
        R[1] = q1_q2 - q3_q0;
        R[2] = q1_q3 + q2_q0;
        R[3] = q1_q2 + q3_q0;
        R[4] = 1 - sq_q1 - sq_q3;
        R[5] = q2_q3 - q1_q0;
        R[6] = q1_q3 - q2_q0;
        R[7] = q2_q3 + q1_q0;
        R[8] = 1 - sq_q1 - sq_q2;
    } else if (length == 16) {
        R[0] = 1 - sq_q2 - sq_q3;
        R[1] = q1_q2 - q3_q0;
        R[2] = q1_q3 + q2_q0;
        R[3] = (T)0;
        R[4] = q1_q2 + q3_q0;
        R[5] = 1 - sq_q1 - sq_q3;
        R[6] = q2_q3 - q1_q0;
        R[7] = (T)0;
        R[8] = q1_q3 - q2_q0;
        R[9] = q2_q3 + q1_q0;
        R[10] = 1 - sq_q1 - sq_q2;
        R[11] = (T)0;
        R[12] = R[13] = R[14] = (T)0;
        R[15] = (T)1;
    }
}

#endif // TRANSFORMATION_H