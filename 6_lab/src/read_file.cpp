#include <iostream>
#include <read_file.hpp>
#include <fstream>


namespace read {
	//считывание размеров матрицы и самой матрицы
	void readFile(int &n, int &m, int matrix[100][100]) {
		std::ifstream fileRead;
		fileRead.open("text.txt");
		fileRead >> n;
		fileRead >> m;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				int temp;
				fileRead >> temp;
				matrix[i][j] = temp;
				
			}

		}
	}
}
