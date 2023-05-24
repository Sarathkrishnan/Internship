#include <stdio.h>

void averagePooling2D(float* input, int input_rows, int input_cols, int pool_size, float* output) {
    int output_rows = input_rows / pool_size;
    int output_cols = input_cols / pool_size;

    for (int i = 0; i < output_rows; i++) {
        for (int j = 0; j < output_cols; j++) {
            float sum = 0.0;
            for (int k = 0; k < pool_size; k++) {
                for (int l = 0; l < pool_size; l++) {
                    int input_row = i * pool_size + k;
                    int input_col = j * pool_size + l;
                    sum += input[input_row * input_cols + input_col];
                }
            }
            output[i * output_cols + j] = sum / ((float)pool_size * (float)pool_size);
        }
    }
}

int main() {
    // Example usage
    float input[9] = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0};
    int input_rows = 3;
    int input_cols = 3;
    int pool_size = 2;
    float output[4];

    averagePooling2D(input, input_rows, input_cols, pool_size, output);

    printf("Output:\n");
    for (int i = 0; i < 4; i++) {
        printf("%f ", output[i]);
    }
    printf("\n");

    return 0;
}
