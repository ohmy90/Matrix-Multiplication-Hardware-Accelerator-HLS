# Matrix-Multiplication-Hardware-Accelerator-HLS

<p align="justify"> A matrix hardware accelerator done by following Xilinx's project-based learning approach. There a few differences: notably a different FPGA board is used (AX7035B which has considerably less resources compared to the PYNQ-Z2), the project on my PC instead of Jupyter Notebook and a C++ software implementation is included to discuss the differences in code execution, compiler, libraries, etc. (to explore the software perspective). 

Because the AX7035B is a "pure" FPGA (no PS side), measuring its execution time for matrix multiplication is found by: Execution time= # of cycles * target clock period (hls.clk).

https://xilinx.github.io/xup_high_level_synthesis_design_flow/matmult.html

The design makes use of block matrix multiplication. Basically the original matrix is partitioned into two submatrices, pairing them for local caching. We can then multiply the appropriate submatrices to obtain a portion of the output matrix result and reduced area usage with reduced data read operations. </p>

## Part 1 results:  
Both are ran on AMD Ryzen 7 5800XT 8-Core Processor.  

### C++ software implementation for matrix multiplication
Time taken for matrix multiplication: 0.0225571 seconds  

Time taken for matrix multiplication (after implementing O3 argument and march=native): 0.0009891 seconds = 0.9891 ms

### Python software implementation for matrix multiplication
Time taken for one 128*128 matrix multiplication: 0.002044166421890259 seconds = 2.044 ms
<br/>


## Why is the C++ implementation 10x slower than the Python implementation without arguments? And the importance of good software design.
<br/>

<p align="justify"> Both codes are written to be executed on a single thread and sequentially (integers are used so single-threaded for Numpy). Furthermore, the implementations have a time complexity of O(N^3) since the matrices multiply by the standard method using three nested loops. The programs could have been optimized in a number of ways: multicore and multithread execution and local memory locations for faster read/write operations. Nevertheless, adding the flags lead to an improvement of over 20x in the C++ implementation. 

O3 tells the compiler to maximize the execution speed of the program by adopting agressive compilation methods, and march=native forces the compiler to compile exactly for the current CPU (i.e. force it to use its instructions) . As such, one can see the importance of compiler/sofware optimization in hardware-software co-design.  </p>


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
The hardware accelerator has a speedup of roughly 25.7% (i.e. 1.257 faster than the CPU in the Python implementation). Considering that the design is compared to an 8-core 16-thread CPU operating at 4.6Ghz (at best), the design is a success.
