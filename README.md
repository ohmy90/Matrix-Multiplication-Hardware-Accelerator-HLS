# Matrix-Multiplication-Hardware-Accelerator-HLS

A matrix hardware accelerator done by following Xilinx's project-based learning approach. There a few differences: notably a different FPGA board is used (AX7035B which is "weaker" than the reccomended PYNQ-Z2), Jupyter Notebook is avoided to run the project on my PC and a C++ software implementation is included to discuss the differences in compiler, code execution, libraries, etc.

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

<br/>
## Part 2 results:  
================================================================
== Performance Estimates
================================================================
+ Timing: 
    * Summary: 
    +--------+----------+----------+------------+
    |  Clock |  Target  | Estimated| Uncertainty|
    +--------+----------+----------+------------+
    |ap_clk  |  10.00 ns|  7.300 ns|     2.70 ns|
    +--------+----------+----------+------------+

+ Latency: 
    * Summary: 
    +---------+---------+----------+----------+--------+--------+---------+
    |  Latency (cycles) |  Latency (absolute) |     Interval    | Pipeline|
    |   min   |   max   |    min   |    max   |   min  |   max  |   Type  |
    +---------+---------+----------+----------+--------+--------+---------+
    |   182001|   182001|  1.820 ms|  1.820 ms|  182002|  182002|       no|
    +---------+---------+----------+----------+--------+--------+---------+

      
================================================================
== Utilization Estimates
================================================================
* Summary: 
+-----------------+---------+----+-------+-------+-----+
|       Name      | BRAM_18K| DSP|   FF  |  LUT  | URAM|
+-----------------+---------+----+-------+-------+-----+
|DSP              |        -|   -|      -|      -|    -|
|Expression       |        -|   -|      0|     52|    -|
|FIFO             |        -|   -|      -|      -|    -|
|Instance         |        2|  64|   2097|   6529|    -|
|Memory           |        1|   -|   2048|    512|    0|
|Multiplexer      |        -|   -|      0|   5871|    -|
|Register         |        -|   -|    297|      -|    -|
+-----------------+---------+----+-------+-------+-----+
|Total            |        3|  64|   4442|  12964|    0|
+-----------------+---------+----+-------+-------+-----+
|Available        |      100|  90|  41600|  20800|    0|
+-----------------+---------+----+-------+-------+-----+
|Utilization (%)  |        3|  71|     10|     62|    0|
+-----------------+---------+----+-------+-------+-----+
