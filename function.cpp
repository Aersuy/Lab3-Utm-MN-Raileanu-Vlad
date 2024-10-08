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