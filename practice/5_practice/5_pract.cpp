#include <iostream>

class dynamicMas {

private:
	int m_count = 1;
	int* m_mas = new int[m_count];
	int* tempMas = new int[1];

public:
	dynamicMas(int firstElement) {
		m_count = 1;
		m_mas[0] = firstElement;
		std::cout << "Создан массив с единственным элементом " << firstElement << std::endl;
	}
	~dynamicMas() {
		std::cout << "Массив удалён" << std::endl;
	}

	void newElementInTheEnd(int element) {
		int* tempMas = new int[m_count + 1];

		for (int i = 0; i < m_count; i++) {
			tempMas[i] = m_mas[i];
		}
		tempMas[m_count] = element;
		
		//delete[] m_mas;
		int* m_mas = tempMas;

		m_count++;
		std::cout << "Теперь массив имеет в конце элемент " << element << ", а его длина равна " << m_count << std::endl;
	}

	int getCount() {
		return m_count;
	}
	int getElement(int index){
		return m_mas[index];
	}
	void getAllElements() {
		for (int i = 0; i << m_count; i++) {
			std::cout << m_mas[i] << ", ";
		}
		std::cout << std::endl;
	}

	void setElement(int element, int index) {
		m_mas[index] = element;
		std::cout << "Элемент с индексом " << index << " теперь равен " << element << std::endl;
	}

	void delElement(int index) {
		
		int* tempMas = new int[m_count - 1];

		for (int i = 0; i < index; i++) tempMas[i] = m_mas[i];
		for (int i = index + 1; i < m_count; i++) tempMas[index] = m_mas[index + 1];
		
		delete[] m_mas;
		int* m_mas = tempMas;

		m_count--;

		std::cout << "Элемент с индексом " << index << " удалён";
	}

	void insertElement(int element, int index) {

		int* tempMas = new int[m_count + 1];

		for (int i = 0; i < index; i++) tempMas[i] = m_mas[i];
		tempMas[index] = element;
		for (int i = index + 1; m_count + 1; i++) tempMas[i] = m_mas[i - 1];

		delete[] m_mas;
		int* m_mas = tempMas;

		m_count++;

		std::cout << "На место " << index << "-го элемента вставлен " << element << std::endl;
	}
};

int main() {
	setlocale(LC_ALL, "RUS");
	dynamicMas test(1);
	test.newElementInTheEnd(2);
	test.newElementInTheEnd(3);
	test.getAllElements();
}	