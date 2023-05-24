#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

// Define the header structure
typedef struct {
    char magic[6];
    uint8_t majorVersion;
    uint8_t minorVersion;
    uint16_t headerLen;
    uint16_t descrLen;
    uint32_t dataLen;
} NpyHeader;

int main() {
    // Open the .npy file
    FILE *file = fopen("C:\\Users\\Trest\\Desktop\\SarathKrishnan\\codes\\Netrasemi-ML-Internship\\l4_model_layer_implimentation_in_c\\read_npy\\weights\\1_conv2d.npy", "rb");


    if (file == NULL) {
        printf("Failed to open file.\n");
        return 1;
    }

    // Read the header
    NpyHeader header;
    fread(&header, sizeof(NpyHeader), 1, file);

    // Verify the magic string
    if (strncmp(header.magic, "\x93NUMPY", 6) != 0) {
        printf("Invalid .npy file.\n");
        fclose(file);
        return 1;
    }

    // Allocate memory for the data
    uint8_t *data = malloc(header.dataLen);
    if (data == NULL) {
        printf("Memory allocation failed.\n");
        fclose(file);
        return 1;
    }

    // Read the data
    fread(data, header.dataLen, 1, file);

    // Access the data type and shape
    char *descr = (char *)(data + header.headerLen);
    int ndim = (int)*(uint8_t *)(descr + 8);
    int *shape = (int *)(descr + 9);

    // Print data details
    printf("Data type: %s\n", descr);
    printf("Number of dimensions: %d\n", ndim);
    printf("Shape: ");
    for (int i = 0; i < ndim; i++) {
        printf("%d ", shape[i]);
    }
    printf("\n");

    // Access the data as needed
    // ...

    // Cleanup
    free(data);
    fclose(file);

    return 0;
}
