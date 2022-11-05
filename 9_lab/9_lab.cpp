#include <iostream>

class rectangle {
private:
	short m_length = 0;
	short m_width = 0;
	short m_area = 0;
public:
	rectangle(short length, short width) {
		m_length = length;
		m_width = width;
		std::cout << "Теперь существует прямоугольник с длиной " << m_length << " и шириной " << m_width << std::endl;
	}
	~rectangle() {
		std::cout << "Прямоугольника с длиной " << m_length << " и шириной " << m_width << " больше не существует" << std::endl;
	}


	//сеттеры
	void setLength(short length) {
		m_length = length;
		std::cout << "Теперь длина прямоугольника: " << m_length << std::endl;
	}
	void setWidth(short width) {
		m_width = width;
		std::cout << "Теперь ширина прямоугольника: " << m_width << std::endl;
	}


	//геттеры
	void getLength() {
		std::cout << "Длина прямоугольника: " << m_length << std::endl;
	}
	void getWidth() {
		std::cout << "Ширина прямоугольника: " << m_width << std::endl;
	}
	void getArea() {
		std::cout << "Площадь прямоугольника равна " << m_width * m_length << std::endl;
	}

};

int main() {
	setlocale(LC_ALL, "RUS");
	rectangle test1(9, 2);

	test1.getLength();
	test1.getWidth();

	test1.setLength(10);
	test1.getLength();
	test1.getWidth();
	test1.getArea();

}