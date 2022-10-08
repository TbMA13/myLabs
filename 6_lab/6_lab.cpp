#include <iostream>
#include <fstream>

#include <read_file.hpp>
#include <process_file.hpp>
#include <output_file.hpp>


int main() {
	setlocale(LC_ALL, "RUS");
	int n = 3;
	int m = 3;
	int matrix[100][100];


	read::readFile(n, m, matrix);
	
	std::cout << "Исходная матрица:" << std::endl;
	std::cout << std::endl;
	output::outputFile(n, m, matrix);
	std::cout << std::endl;
	std::cout << std::endl;
	
	process::processFile(n, m, matrix);

	std::cout << "Полученная матрица:" << std::endl;
	std::cout << std::endl;
	output::outputFile(n, m, matrix);
}