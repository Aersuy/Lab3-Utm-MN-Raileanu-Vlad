#include "function.h"
#include <iostream>
#include <math.h>
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

std::vector<std::vector<double>> choleskyDecomposition(std::vector<std::vector<double>>& matrix)
{ 
    std::vector<std::vector<double>> L(size,std::vector<double>(size,0));
     for (int iterator1 = 0; iterator1 < size; iterator1++)
     {
        for (int iterator2 = 0; iterator2 <= iterator1; iterator2++)
        {  double sum{0};
            if (iterator1 == iterator2)
            {
                for (int iterator3 = 0; iterator3 < iterator2; iterator3++)
                {
                   sum +=L[iterator2][iterator3]*L[iterator2][iterator3];
                }
                L[iterator2][iterator2] = sqrt(matrix[iterator2][iterator2] - sum);
                if (L[iterator2][iterator2] < 0)
                {
                    std::cerr << "Matricea nu e definita positiv \n";
                    return matrix;
                }
            } 
            else
            {
                for (int iterator3 = 0; iterator3 < iterator2; iterator3++)
                {
                  sum += L[iterator1][iterator3]* L[iterator2][iterator3];
                }
                
                L[iterator1][iterator2] = (matrix[iterator1][iterator2] - sum) / L[iterator2][iterator2];
            }
            
            
        }
        
     }
     return L;
}
std::vector<std::vector<double>> transposition(std::vector<std::vector<double>>& matrix)
{
    std::vector<std::vector<double>> transposedM (size,std::vector<double>(size,0));
    for (int iterator1 = 0; iterator1 < size; iterator1++)
    {
        for (int iterator2 = 0; iterator2 < size; iterator2++)
        {
            transposedM[iterator2][iterator1] = matrix[iterator1][iterator2];
        }
        
    }
    return transposedM;
}

std::vector<double> solveY(std::vector<std::vector<double>>& L, std::vector<double>& b)
{
    std::vector<double> solution(size,0);
    for (int iterator1 = 0; iterator1 < size; iterator1++)
    {double sum{0};
        for (int iterator2 = 0; iterator2 < iterator1; iterator2++)
        {
            sum += L[iterator1][iterator2] * solution[iterator2];
        }
        solution[iterator1] = (b[iterator1] - sum)/L[iterator1][iterator1];
    }
    return solution;
}
std::vector<double> solveX(std::vector<std::vector<double>>& L, std::vector<double>& b)
{
    std::vector<double> solution(size,0);
    for (int iterator1 = size - 1; iterator1 >= 0; iterator1--)
    {double sum{0};
        for (int iterator2 = iterator1 + 1; iterator2 < iterator1; iterator2++)
        {
            sum += L[iterator1][iterator2] * solution[iterator2];
        }
        solution[iterator1] = (b[iterator1] - sum)/L[iterator1][iterator1];
    }
    return solution;
}

void copyVector(std::vector<double>& copied, std::vector<double>& copy)
{
    for (int iterator = 0; iterator < size; iterator++)
    {
       copy[iterator] = copied[iterator];  
    }
    
}
bool checkError(std::vector<double>& firstVector, std::vector<double>& secondVector)
{
    for(int iterator = 0; iterator < size; iterator++)
    {
        if (fabs(firstVector[iterator]-secondVector[iterator]) > error)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    return false;
}

std::vector<double> jacobiMethod(std::vector<std::vector<double>>& matrix,std::vector<double>& b)
{
    std::vector<double> previous(size,0);
    std::vector<double> current(size,0);
    int iteratii {0};
    do
    { iteratii++;
      previous = current;
      std::cout << "Iteratia " << iteratii << '\n';
      std::cout << "Iteratia trecuta : \n";
      printVector(previous);
      for (int iterator = 0; iterator < size; iterator++)
      {
        double sum{0};
        for (int iterator2 = 0; iterator2 < size; iterator2++)
        {
            if (iterator != iterator2) // nu e diagonala principala
            {
                sum+= matrix[iterator][iterator2] * previous[iterator2];
            }
            
        }
        current[iterator] = (b[iterator] - sum)/matrix[iterator][iterator];
      }
        
    } while (checkError(current,previous));
    return current;
}