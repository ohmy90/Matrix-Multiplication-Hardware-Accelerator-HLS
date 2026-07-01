# Matrix-Multiplication-Hardware-Accelerator-HLS

A matrix hardware accelerator done by following Xilinx's project-based learning approach. There a few differences: notably a different FPGA board is used (AX7035B which is "weaker" than the PYNQ-Z2 used by Xilinx), the project on my PC instead of Jupyter Notebook and a C++ software implementation is included to discuss the differences in code execution, libraries, etc. (to explore the software perspective). 

In addition, because the AX7035B is a "pure" FPGA (no PS side), measuring its execution time for matrix multiplication is found by: Execution time= # of cycles * target clock period (hls.clk).

https://xilinx.github.io/xup_high_level_synthesis_design_flow/matmult.html

The design makes use of block matrix multiplication. Basically the original matrix is partitioned into two submatrices, pairing them for local caching. We can then multiply the appropriate submatrices to obtain a portion of the output matrix result and reduced area usage with reduced data read operations.

## Part 1 results:  
Both are ran on AMD Ryzen 7 5800XT 8-Core Processor.  

### C++ software implementation for matrix multiplication
<br/>
Time taken for matrix multiplication: 0.0225571 seconds  

### Python software implementation for matrix multiplication
<br/>
Time taken for one 128*128 matrix multiplication: 0.002044166421890259 seconds = 2.044 ms
<br/>


## Why is the C++ implementation 10x slower than the Python implementation?  
<br/>

The C++ code is written to be executed on a single thread and sequentially. Furthermore, the implementation has a time complexity of O(N^3) since the matrices multiply by the standard method using three nested loops. The Python code uses a different algorithm to multiply the matrices with the Stanford method. The time complexity is effectevily reduced to O(N^2.3728639). The Python code also makes full usage of the CPU's resources (threads/cores) to fast-track the calculations.

<br/>

## Part 2 results:  

### Design from XILINX:


<br/>
<img width="1210" height="330" alt="image" src="https://github.com/user-attachments/assets/51f15a85-da9e-46f5-b8c0-b6962ff2f699" />

### Design after modifications:
Placeholder

## Part 3 results:  

### Design from XILINX:
203113 cycles * 8.00 nS (target timing estimate) = 1.625 ms
<br/>
100% DSP usage post implementation as well
### Design after modifications:
Placeholder

## Discussion
The hardware accelerator has a speedup of roughly 25.7% (i.e. 1.257 faster than the CPU). Considering that the design is compared to an 8-core 16-thread CPU operating at 4.6Ghz (at best), the design is a success.
