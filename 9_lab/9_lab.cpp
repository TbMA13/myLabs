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
		std::cout << "������ ���������� ������������� � ������ " << m_length << " � ������� " << m_width << std::endl;
	}
	~rectangle() {
		std::cout << "�������������� � ������ " << m_length << " � ������� " << m_width << " ������ �� ����������" << std::endl;
	}


	//�������
	void setLength(short length) {
		m_length = length;
		std::cout << "������ ����� ��������������: " << m_length << std::endl;
	}
	void setWidth(short width) {
		m_width = width;
		std::cout << "������ ������ ��������������: " << m_width << std::endl;
	}


	//�������
	void getLength() {
		std::cout << "����� ��������������: " << m_length << std::endl;
	}
	void getWidth() {
		std::cout << "������ ��������������: " << m_width << std::endl;
	}
	void getArea() {
		std::cout << "������� �������������� ����� " << m_width * m_length << std::endl;
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