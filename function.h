#include <vector>

constexpr int size{4};
constexpr double error{10e-5};
void printVector(const std::vector<double>&);
void printMatrix(const std::vector<std::vector<double>>& );
void fillMatrix(std::vector<std::vector<double>>&);
void fillVector(std::vector<double>&);
void copyVector(std::vector<double>&, std::vector<double>&);
bool checkError(std::vector<double>&, std::vector<double>&);



std::vector<double> gaussianElimination(std::vector<std::vector<double>>, std::vector<double>);

std::vector<std::vector<double>> choleskyDecomposition(std::vector<std::vector<double>>&);
std::vector<std::vector<double>> transposition(std::vector<std::vector<double>>&);
std::vector<double> solveY(std::vector<std::vector<double>>&, std::vector<double>&);
std::vector<double> solveX(std::vector<std::vector<double>>&, std::vector<double>&);

std::vector<double> jacobiMethod(std::vector<std::vector<double>>&,std::vector<double>&);
std::vector<double> gaussSiedel(std::vector<std::vector<double>>&, std::vector<double>&);