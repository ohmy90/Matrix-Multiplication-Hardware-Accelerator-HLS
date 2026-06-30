# Matrix-Multiplication-Hardware-Accelerator-HLS

A matrix hardware accelerator done by following Xilinx's project-based learning approach. There a few differences: notably a different FPGA board is used, Jupyter Notebook is avoided to run the project on my PC and a C++ software implementation is included to discuss the differences in compiler, code execution, libraries, etc.

https://xilinx.github.io/xup_high_level_synthesis_design_flow/matmult.html

## Part 1 results:  
Both are ran on AMD Ryzen 7 5800XT 8-Core Processor.  

### C++ software implementation for matrix multiplication
<br/>
Time taken for matrix multiplication: 0.0225571 seconds  

### Python software implementation for matrix multiplication
<br/>
Time taken for one 128*128 matrix multiplication: 0.002044166421890259 seconds  
<br/>


## Why is the C++ implementation 10x slower than the Python implementation?  
<br/>
Placeholder, to discuss at a later date (when I am not so tired).
