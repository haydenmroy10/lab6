#include <iostream>
#include <fstream>

const int max = 100;

void readLine(int matrix[max][max], int& size, const std::string& filename)
{
    std::ifstream file(filename);
    if (file)
    {
        file >> size;
        for (int i = 0; i < size; i = i + 1)
        {
            for(int j = 0; j < size; j++)
            {
                file >> matrix[i][j];
            }
        }
        file.close();
        
    }
    else
    {
        std::cout << "File error";
        exit(1);
    }
}

void matrixAddition(const int matrix1[max][max], const int matrix2[max][max],int matrix3[max][max], int size)
{
    for (int i = 0; i < size; i=i+1)
    {
        for (int j = 0; j <size; i=i+1)
        {
            matrix3[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}

void matrixSubtraction(const int matrix1[max][max], const int matrix2[max][max],int matrix3[max][max], int size)
{
    for (int i = 0; i < size; i=i+1)
    {
        for (int j = 0; j <size; i=i+1)
        {
            matrix3[i][j] = matrix1[i][j] - matrix2[i][j];
        }
    }
}

void matrixMultiplication(const int matrix1[max][max], const int matrix2[max][max],int matrix3[max][max], int size)
{
    for (int i = 0; i < size; i=i+1)
    {
        for (int j = 0; j <size; i=i+1)
        {
            matrix3[i][j] = 0;
            for (int k = 0; k < size; k=k+1)
            {
                matrix3[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
}

void printMatrix(const int matrix[max][max], int size)
{
    for (int i = 0; i < size; i=i+1)
    {
        for (int j = 0; j < size; j=j+1)
        {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}
int main() {
    int size;
    int matrix1[max][max];
    int matrix2[max][max];
    int matrix3[max][max];
    
    readLine(matrix1, size, "matrix_input.txt");
    readLine(matrix2, size, "matrix_input.txt");
    
    std::cout << "Matrix A:" << std::endl;
    printMatrix(matrix1, size);
    
    std::cout << "Matrix B:" << std::endl;
    printMatrix(matrix2, size);
    
    if (size > 0)
    {
        matrixAddition(matrix1, matrix2, matrix3, size);
        std::cout << "Matrix Sum (A+B):" << std::endl;
        printMatrix(matrix3, size);
        
        matrixSubtraction(matrix1, matrix2, matrix3, size);
        std::cout << "Matrix Difference (A-B):" << std::endl;
        printMatrix(matrix3, size);
        
        matrixMultiplication(matrix1, matrix2, matrix3, size);
        std::cout << "Matrix Product (A * B):" << std::endl;
        printMatrix(matrix3, size);
        
    }
    
    return 0;
}