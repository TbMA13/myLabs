#include<iostream>

//void readFile() {
////	����� ������ ����� � ��������� �����
//}

void sort(int matrix[100][100], int n, int m) {
	for (int a = 0; a < n; a++) {
		for (int j = 0; j < m - 1; j++) {
			for (int k = 0; k < m - 1; k++) {
				if (matrix[a][k] > matrix[a][k + 1]) {
					int tempNumber = matrix[a][k + 1];
					matrix[a][k + 1] = matrix[a][k];
					matrix[a][k] = matrix[a][tempNumber];
				}
			}
		}
	}
	
}

void processingFile() {
	//������ �������� ���� �������� � ���� ��������� ���������� ������
	int n = 100; //������
	int m = 100; //�������
	int matrix[100][100] = { {0} };
	int maxElement;
	int minElement;
	//sort(matrix[100][100], n, m);
	if (minElement + maxElement == 0) {
		for (int i = 0; i < n; i++) {

		}
	}

}

//void whiteFile() {
//	//����� ����������� ���������� � �������
//}

int main() {

}