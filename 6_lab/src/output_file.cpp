#include <iostream>
#include <output_file.hpp>


namespace output {
	// вывод полученной матрицы
	void outputFile(int &n, int &m, int matrix[100][100]) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				std::cout << matrix[i][j] << ' ';
			}
			std::cout << std::endl;
		}
	}
}
