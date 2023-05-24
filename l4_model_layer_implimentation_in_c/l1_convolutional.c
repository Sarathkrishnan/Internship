#include <stdio.h>
#include <stdlib.h>

#define ROWS 28
#define COLS 28
#define CHANNELS 1
#define NUM_FILTERS 6
#define KERNEL_SIZE 5
#define STRIDE 1

float relu(float x) {
    return (x > 0) ? x : 0;
}

void conv2D(float input[ROWS][COLS][CHANNELS], float filters[NUM_FILTERS][KERNEL_SIZE][KERNEL_SIZE], float output[NUM_FILTERS][(ROWS - KERNEL_SIZE + 1) / STRIDE][(COLS - KERNEL_SIZE + 1) / STRIDE]) {
    int i, j, k, l, m, n;
    int row_start, col_start;

    for (i = 0; i < NUM_FILTERS; i++) {
        for (j = 0; j < (ROWS - KERNEL_SIZE + 1) / STRIDE; j++) {
            for (k = 0; k < (COLS - KERNEL_SIZE + 1) / STRIDE; k++) {
                output[i][j][k] = 0.0;

                row_start = j * STRIDE;
                col_start = k * STRIDE;

                for (l = 0; l < KERNEL_SIZE; l++) {
                    for (m = 0; m < KERNEL_SIZE; m++) {
                        for (n = 0; n < CHANNELS; n++) {
                            output[i][j][k] += input[row_start + l][col_start + m][n] * filters[i][l][m];
                        }
                    }
                }

                output[i][j][k] = relu(output[i][j][k]);
            }
        }
    }
}

int main() {
    // Define input, filters, and output arrays
    float input[ROWS][COLS][CHANNELS];
    float filters[NUM_FILTERS][KERNEL_SIZE][KERNEL_SIZE];
    float output[NUM_FILTERS][(ROWS - KERNEL_SIZE + 1) / STRIDE][(COLS - KERNEL_SIZE + 1) / STRIDE];

    // Initialize input and filter arrays with values
    // ...

    // Perform convolution
    conv2D(input, filters, output);

    // Display the output
    int i, j, k;
    for (i = 0; i < NUM_FILTERS; i++) {
        for (j = 0; j < (ROWS - KERNEL_SIZE + 1) / STRIDE; j++) {
            for (k = 0; k < (COLS - KERNEL_SIZE + 1) / STRIDE; k++) {
                printf("%.2f ", output[i][j][k]);
            }
            printf("\n");
        }
        printf("\n");
    }

    return 0;
}
