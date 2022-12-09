#include <iostream>
#include <vector>
#include <windows.h>

class Component {
private:
    unsigned int m_article;
    int m_length;
    int m_width;
    int m_depth;

public:
    Component (unsigned int article, int length, int width, int depth) {
        std::cout << "Constructor works" << std::endl;
        m_article = article;
        m_length = length;
        m_width = width;
        m_depth = depth;
    }
    ~Component (){
        std::cout << "Destructor works" << std::endl;
    }
    unsigned int getArticle() {
        return m_article;
    }
};

void getComponents(std::vector<Component*> &components){
    std::cout << "\nЭлементы:" << std::endl;
    std::cout << components.size() << std::endl;
    for (int i = 0; i < components.size(); i++){
        std::cout << i << std::endl;
        std::cout << components[i]->getArticle() << std::endl;
    }
    std::cout << std::endl;
}

int main() {
    setlocale(LC_ALL, "Rus");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    // создание структуры данных, состоящей из укзаталей на объекты класса Component
    std::vector<Component*> components;
    //

//    std::cout << "Размер вектора: " << components.size() << std::endl;
//    std::cout << "Максимальный размер вектора " << components.capacity() << std::endl;

    //

    Component component1(1, 10, 10, 10);
    Component component2(2, 10, 10, 10);
    Component component3(3, 10, 10, 10);

    // добавление элементов в конец
    components.push_back((Component*)&component1);
    components.push_back((Component*)&component2);
    components.push_back((Component*)&component3);
    //

    //    // использование empty - проверка на наличие элементов
    //    if (!components.empty()){
    //        std::cout << "В векторе как минмум есть " << components[1]->getArticle() << std::endl;
    //    }
    //    //

    components.push_back((Component*)&component1);
    getComponents(components);
    // удаляет последний элемент
    std::vector<Component*>::iterator it;
    it = components.end();
    components.erase(it - 1);
    //
    getComponents(components);

    // вставка элемента в конец (можно в любом месте)
    components.insert(components.end(), (Component*)&component1);
    //
    getComponents(components);

    // инициализирует нужно количество элементов, если размер больше исходного, то элементы пустые
    // если размер меньше, то элементы с конца удаляются
    components.resize(4);
    std::cout << components[0] << std::endl;
    //
    std::cout << "Размер вектора: " << components.size() << std::endl;
    std::cout << "Максимальный размер вектора " << components.capacity() << std::endl;

    // выделяет память, но не инициализирует ее
    components.reserve(7);
    std::cout << "Размер вектора: " << components.size() << std::endl;
    std::cout << "Максимальный размер вектора " << components.capacity() << std::endl;

    // emplace_back() создает объект по переданным ему аргументам без лишнего копирования,
    // в отличие от push_back()
    components.emplace_back(new Component(2, 10, 10, 10));
    //

    //return 0;
    getComponents(components);

//    return 0;

    it = components.end();
    components.erase(it - 1);
    getComponents(components);

    components.push_back((Component*)&component2);
    components.push_back((Component*)&component3);
    getComponents(components);

    // изменение значений ячеек
    for (short i = 3; i < 6; i++){
        components[i] = components[abs(i - 5)];
    }
    // либо же можно так:
    //for (short i = 3; i < 6; i++){
    //    components.at(i) = components[abs(i - 5)];
    //   }
    //
    getComponents(components);
    // удаляет элементы
    components.clear();
    std::cout << "Размер вектора: " << components.size() << std::endl;
    std::cout << "Максимальный размер вектора " << components.capacity() << std::endl;

    // чистит зарезервированную раннее память
    components.shrink_to_fit();
    std::cout << "Размер вектора: " << components.size() << std::endl;
    std::cout << "Максимальный размер вектора " << components.capacity() << std::endl;

    getComponents(components);
}
