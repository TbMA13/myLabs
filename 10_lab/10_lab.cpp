#include <iostream>
#include <vector>

class Component {
private:
	unsigned int m_article;
	int m_length;
	int m_width;
	int m_depth;

public:
	Component (unsigned int article, int length, int width, int depth) {
		std::cout << "Конструктор детали работает" << std::endl;
		m_article = article;
		m_length = length;
		m_width = width;
		m_depth = depth;
	}
	~Component (){
		std::cout << "Деструктор детали работает" << std::endl;
	}
	unsigned int getArticle() {
		return m_article;
	}
};

class Car {
private:
	std::vector<Component*> m_components;
	unsigned short m_componentsCount = 0;
	std::string m_model;
public:
	Car(std::string model) {
		m_model = model;
		std::cout << "Конструктор машины работает" << std::endl;
	}
	void addComponent(Component*currentComponent) {
		m_components.push_back(currentComponent);
		m_componentsCount += 1;
	}
	void getComponents() {
		for (unsigned short i = 0; i < m_componentsCount; i++) {
			std::cout << m_components[i]->getArticle() << std::endl;
		}
	}
	~Car() {
		std::cout << "Деструктор машины работает" << std::endl;
	}
};

int main() {
	setlocale(LC_ALL, "RUS");
	Car car1("Еуыдф");
	Component component1(1, 10, 15, 20);
	Component component2(2, 9, 43, 23);
	car1.addComponent(&component1);
	car1.addComponent(&component2);
	car1.getComponents();
}