#include <stdio.h>
#include <math.h>

typedef struct {
    double theta;
    double a;
    double d;
    double alpha;
} DHParams;

// Function to multiply two 4x4 matrices
void multiplyMatrices(double res[4][4], double mat1[4][4], double mat2[4][4]) {
    int i, j, k;
    double temp[4][4];

    // Matrix multiplication
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            temp[i][j] = 0;
            for (k = 0; k < 4; k++) {
                temp[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }

    // Copy result to the res matrix
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            res[i][j] = temp[i][j];
        }
    }
}

// Function to create a DH transformation matrix
void createDHMatrix(double mat[4][4], DHParams dh_params) {
    double ct = cos(dh_params.theta * M_PI / 180.0);
    double st = sin(dh_params.theta * M_PI / 180.0);
    double ca = cos(dh_params.alpha);
    double sa = sin(dh_params.alpha);

    // Fill in the elements of the transformation matrix
    mat[0][0] = ct;
    mat[0][1] = -st * ca;
    mat[0][2] = st * sa;
    mat[0][3] = dh_params.a * ct;

    mat[1][0] = st;
    mat[1][1] = ct * ca;
    mat[1][2] = -ct * sa;
    mat[1][3] = dh_params.a * st;

    mat[2][0] = 0;
    mat[2][1] = sa;
    mat[2][2] = ca;
    mat[2][3] = dh_params.d;

    mat[3][0] = 0;
    mat[3][1] = 0;
    mat[3][2] = 0;
    mat[3][3] = 1;
}

int main() {
    DHParams dh_params[] = {
        { 10, 0.0, 0.21, M_PI_2 },
        { -50, -0.8, 0.193, 0.0 },
        { -60, -0.598, -0.16, 0.0 },
        { 90, 0.0, 0.25, M_PI_2 },
        { 50, 0.0, 0.25, -M_PI_2 },
        { 0, 0.0, 0.25, 0.0 }
    };

    double result_matrix[4][4];
    double temp_matrix[4][4];

    // Initialize result_matrix with the first DH transformation
    createDHMatrix(result_matrix, dh_params[0]);

    // Perform matrix multiplication with the remaining DH transformations
    for (int i = 1; i < 6; i++) {
        createDHMatrix(temp_matrix, dh_params[i]);
        multiplyMatrices(result_matrix, result_matrix, temp_matrix);
    }

    // Extract the position (x, y, z) from the resulting transformation matrix
    double position[3];
    position[0] = result_matrix[0][3];
    position[1] = result_matrix[1][3];
    position[2] = result_matrix[2][3];

    // Print the position (x, y, z)
    printf("Position (x, y, z): %f, %f, %f\n", position[0], position[1], position[2]);

    return 0;
}