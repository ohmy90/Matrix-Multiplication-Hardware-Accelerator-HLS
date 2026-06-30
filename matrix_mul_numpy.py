import random
import numpy as np

in1 = np.random.randint(255, size=(1, 16384))
in2 = np.random.randint(255, size=(1, 16384))
in1_py = np.resize(in1, (128, 128))
in2_py = np.resize(in2, (128, 128))

# Record the time for 10,000 multiplications
import time
start = time.time()
for i in range(0, 9999):
    out_py = np.dot(in1_py, in2_py)
end = time.time()

print("Time taken for one 128*128 matrix multiplication: {}s".format((end - start) / 10000))