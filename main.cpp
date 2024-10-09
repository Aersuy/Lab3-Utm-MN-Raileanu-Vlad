#include "function.cpp"



int main()
{
    std::vector<std::vector<double>> matrix = {
        {11.3, -0.2, 1.3, -0.4},
        {-0.2, 17.6, 2.1, 0.7},
        {1.3, 2.1, 20.3, 1.2},
        {-0.4, 0.7, 1.2, 19.4}
    };
     std::vector<double> b = {20.3, -14.6, 8.9, 11.3};
    std::vector<double> solution1,solution2,solution3,solution4;

    solution1 = gaussianElimination(matrix,b);
    printVector(solution1);

    std::vector<std::vector<double>> L = choleskyDecomposition(matrix);
    std::vector<std::vector<double>> LT = transposition(L);

    std::vector<double> y = solveY(L,b);
    solution2 = solveX(LT,y);
    printVector(solution2);

    solution3 = jacobiMethod(matrix,b);
    printVector(solution3);

  
     solution4 = gaussSiedel(matrix,b);
     printVector(solution4);

}