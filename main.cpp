#include "function.cpp"



int main()
{
    std::vector<double> vector(size,1);
    std::vector<std::vector<double>> matrix(size,std::vector<double>(size,1));
    fillVector(vector);
     printVector(vector);
    fillMatrix(matrix);
    printMatrix(matrix);
 
}