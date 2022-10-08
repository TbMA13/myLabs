#include <iostream>
#include <process_file.hpp>

namespace process {

	//функция сортировки по возрастанию строки
	void sort(int &n, int &m, int matrix[100][100], int index) {
		for (int j = 0; j < m - 1; j++) {
			for (int k = 0; k < m - 1; k++) {
				if (matrix[index][k] > matrix[index][k + 1]) {
					int tempNumber = matrix[index][k + 1];
					matrix[index][k + 1] = matrix[index][k];
					matrix[index][k] = tempNumber;
				}
			}
		}

	}

	void processFile(int &n, int &m, int matrix[100][100]) {
		int maxElement = INT_MIN;
		int minElement = INT_MAX;
		// поиск минимального и максимального элеметов
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (matrix[i][j] < minElement) {
					minElement = matrix[i][j];
				}
				if (matrix[i][j] > maxElement) {
					maxElement = matrix[i][j];
				}
			}
		}
		// поиск 8-ки в числах: если есть, то сортировка данной строки по возрастанию через sort(....)
		if (minElement + maxElement == 0) {
			for (int i = 0; i < n; i++) {
				bool flag = false;
				for (int j = 0; j < m; j++) {
					int temp = matrix[i][j];
					while (temp > 9) {
						if (temp % 10 == 8) {
							process::sort(n, m, matrix, i);
							flag = true;
							break;
						}
						temp /= 10;
						
						}
					if (temp == 8) {
						process::sort(n, m, matrix, i);
						flag = true;
						break;
					}
					if (flag) {
						break;
					}
				}
			}
		}

	}

}
