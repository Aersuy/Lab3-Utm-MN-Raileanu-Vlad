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
     std::vector<double> solution = gaussSiedel(matrix,b);
   printVector(solution);
}