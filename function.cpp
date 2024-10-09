#include "function.h"
#include <iostream>

void printVector(const std::vector<double>& vector)
{
    for(int iterator = 0; iterator < size; iterator++)
    {
        std::cout << vector[iterator] << ' ';
    }
    std::cout << '\n';
    
}
void printMatrix(const std::vector<std::vector<double>>& matrix )
{  std::cout << "\n \n";
   for(int iterator = 0; iterator < size; iterator++)
     {
        for (int iterator2 = 0; iterator2 < size; iterator2++)
        {
            std::cout << matrix[iterator][iterator2] << ' ';
        }
        std::cout << "\n";
     }
 std::cout << "\n \n";
}
void fillMatrix(std::vector<std::vector<double>>& matrix)
{
     for (int iterator = 0; iterator < size; iterator++)
     {
        for (int iterator2 = 0; iterator2 < size; iterator2++)
        {   std::cout << "Da elementul " << iterator + 1 << " de pe coloana " << iterator2 + 1 << '\n';
            std::cin >> matrix[iterator][iterator2];
        }
        
     }
     
}
void fillVector(std::vector<double>& vector)
{
    for(int iterator = 0; iterator < size; iterator++)
    {
        std::cout << "Da elementul " << iterator << '\n';
        std::cin >> vector[iterator];
    }
    std::cout << '\n';

}

std::vector<double> gaussianElimination(std::vector<std::vector<double>> matrix,std::vector<double> vector)
{
    for (int iterator = 0; iterator < size; iterator++)
    {
        double pivot = matrix[iterator][iterator];
        if (pivot == 0.0)
        {
            std::cout << "Matricea e singulara sau aproape singulara \n";
            return vector;
        }
        for (int iterator2 = iterator; iterator2 < size; iterator2++)
        {
            matrix[iterator][iterator2] /= pivot;
        }
        vector[iterator] /= pivot;

        for (int iterator2 = iterator + 1; iterator2 < size; iterator2++)
        {
            double factor = matrix[iterator2][iterator];
            for (int iterator3 = iterator; iterator3 < size; iterator3++)
            {
                matrix[iterator2][iterator3] -= factor * matrix[iterator][iterator3];
            }
            vector[iterator2] -= factor * vector[iterator];
        }
        
        
    }
     for (int i = size - 1; i >= 0; --i)
    {
        for (int j = i + 1; j < size; ++j)
        {
            vector[i] -= matrix[i][j] * vector[j];
        }
    }
    return vector;
}