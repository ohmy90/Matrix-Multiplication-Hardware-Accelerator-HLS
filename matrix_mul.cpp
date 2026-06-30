#include <iostream>
#include <vector>
#include <chrono>
#include <random>

const int MATRIX_SIZE = 128;

std::vector<std::vector<int>> matrix1(MATRIX_SIZE, std::vector<int>(MATRIX_SIZE));
std::vector<std::vector<int>> matrix2(MATRIX_SIZE, std::vector<int>(MATRIX_SIZE));
std::vector<std::vector<int>> result(MATRIX_SIZE, std::vector<int>(MATRIX_SIZE));


int main(){

    std::random_device rd;
    std::mt19937 gen(rd());

    std::uniform_int_distribution<> dis(0, 255);

    for (int i = 0; i < MATRIX_SIZE; ++i) {
        for (int j = 0; j < MATRIX_SIZE; ++j) {
            matrix1[i][j] = dis(gen);
            matrix2[i][j] = dis(gen);
        }
    }

    auto start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < MATRIX_SIZE; ++i) {
        for (int j = 0; j < MATRIX_SIZE; ++j) {
            int sum = 0;
            for (int k = 0; k < MATRIX_SIZE; ++k) {
                sum += matrix1[i][k] * matrix2[k][j];
            }
            result[i][j] = sum;
        }
    }
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;
    std::cout << "Time taken for matrix multiplication: " << elapsed.count() << " seconds" << std::endl;

    
//    for (int i = 0; i < MATRIX_SIZE; ++i) {
//        for (int j = 0; j < MATRIX_SIZE; ++j) {
//            std::cout << result[i][j] << " ";
//       }
//       std::cout << std::endl;
//  }



    return 0;
}
