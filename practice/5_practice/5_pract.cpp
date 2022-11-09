#include <iostream>

class dynamicMas {

private:
	int m_count = 1;
	int* m_mas = new int[m_count];

public:
	dynamicMas(int firstElement) {
		m_count = 1;
		m_mas[0] = firstElement;
		std::cout << "Создан массив с единственным элементом " << firstElement << std::endl;
	}
	~dynamicMas() {
		delete[] m_mas;
		std::cout << "Массив удалён" << std::endl;
	}

	void newElementInTheEnd(int element) {
		int* tempMas = new int[m_count + 1];

		for (int i = 0; i < m_count; i++) {
			tempMas[i] = m_mas[i];
		}
		tempMas[m_count] = element;
		
		delete[] m_mas;
		m_mas = tempMas;

		m_count++;
		std::cout << "Теперь массив имеет в конце элемент " << element << ", а его длина равна " << m_count << std::endl;
	}

	int getCount() {
		return m_count;
	}
	int getElement(int index){
		if (index >= m_count) {
			std::cout << "Введён некорректный индекс" << std::endl;
			return false;
		}
		return m_mas[index];
	}
	void getAllElements() {
		for (int i = 0; i < m_count; i++) {
			std::cout << m_mas[i] << " ";
		}
		std::cout << std::endl;
	}

	void setElement(int element, int index) {
		m_mas[index] = element;
		std::cout << "Элемент с индексом " << index << " теперь равен " << element << std::endl;
	}

	void delElement(int index) {
		int* tempMas = new int[m_count - 1];
		short j = 0;

		for (int i = 0; i < index; i++, j++) {
			tempMas[j] = m_mas[i];
		}
		for (int i = index + 1; i < m_count; i++, j++) {
			tempMas[j] = m_mas[i];
		}
		delete[] m_mas;
		m_mas = tempMas;

		m_count--;

		std::cout << "Элемент с индексом " << index << " удалён" << std::endl;
	}

	void insertElement(int element, int index) {
		int* tempMas = new int[m_count + 1];
		short j = 0;

		for (int i = 0; i < index; i++, j++) {
			tempMas[j] = m_mas[i];
		}
		tempMas[index] = element;
		j++;
		for (int i = index + 1; i < m_count + 1; i++, j++) {
			tempMas[j] = m_mas[i - 1];
		}

		delete[] m_mas;
		m_mas = tempMas;

		m_count++;

		std::cout << "На место " << index << "-го элемента вставлен " << element << std::endl;
	}
};

int main() {
	setlocale(LC_ALL, "RUS");

	dynamicMas test(1);
	std::cout << std::endl;

	test.newElementInTheEnd(2);
	test.getAllElements();
	std::cout << std::endl;

	test.newElementInTheEnd(3);
	test.getAllElements();
	std::cout << std::endl;

	test.setElement(12, 0);
	test.getAllElements();
	std::cout << std::endl;

	test.delElement(0);
	test.getAllElements();
	std::cout << std::endl;

	test.insertElement(7, 1);
	test.getAllElements();
	std::cout << std::endl;

	std::cout << "Всего элементов:" << test.getCount() << std::endl;
	std::cout << std::endl;

	std::cout << test.getElement(0) << std::endl;
	std::cout << test.getElement(1) << std::endl;
	std::cout << test.getElement(2) << std::endl;
	std::cout << test.getElement(3) << std::endl;
	std::cout << std::endl;
}	