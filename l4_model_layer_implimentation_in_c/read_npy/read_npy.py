import numpy as np
from os import listdir

file_path =r'C:\Users\Trest\Desktop\SarathKrishnan\codes\Netrasemi-ML-Internship\l4_model_layer_implimentation_in_c\read_npy\weights\7_dense_1.npy'
x = np.load(file_path)
print(x.shape)
print(type(x))
print(x)
