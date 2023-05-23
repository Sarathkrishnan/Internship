#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define INPUT_SIZE 784   // Assuming the input size is 784

// Function to implement Dense layer with ReLU activation
void dense_relu(float* input, float* weights, float* biases, float* output, int input_size, int output_size) {
    int i, j;
    
    // Iterate over each output neuron
    for (i = 0; i < output_size; i++) {
        output[i] = 0.0;

        // Compute the dot product of input and weights for each neuron
        for (j = 0; j < input_size; j++) {
            output[i] += input[j] * weights[i * input_size + j];
        }

        // Add the bias term
        output[i] += biases[i];

        // Apply the ReLU activation function
        output[i] = fmaxf(0.0, output[i]);
    }
}

int main() {
    // Define input, weights, biases, and output arrays
    float input[INPUT_SIZE];
    float weights[INPUT_SIZE * 1024];
    float biases[1024];
    float output[1024];
    
    // Initialize input, weights, and biases with some values
    
    // Call the dense_relu function
    dense_relu(input, weights, biases, output, INPUT_SIZE, 1024);
    
    // Print the output
    int i;
    for (i = 0; i < 1024; i++) {
        printf("%f ", output[i]);
    }
    
    return 0;
}
