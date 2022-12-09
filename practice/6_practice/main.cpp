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
    std::cout << "\n��������:" << std::endl;
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

    // �������� ��������� ������, ��������� �� ��������� �� ������� ������ Component
    std::vector<Component*> components;
    //

//    std::cout << "������ �������: " << components.size() << std::endl;
//    std::cout << "������������ ������ ������� " << components.capacity() << std::endl;

    //

    Component component1(1, 10, 10, 10);
    Component component2(2, 10, 10, 10);
    Component component3(3, 10, 10, 10);

    // ���������� ��������� � �����
    components.push_back((Component*)&component1);
    components.push_back((Component*)&component2);
    components.push_back((Component*)&component3);
    //

    //    // ������������� empty - �������� �� ������� ���������
    //    if (!components.empty()){
    //        std::cout << "� ������� ��� ������ ���� " << components[1]->getArticle() << std::endl;
    //    }
    //    //

    components.push_back((Component*)&component1);
    getComponents(components);
    // ������� ��������� �������
    std::vector<Component*>::iterator it;
    it = components.end();
    components.erase(it - 1);
    //
    getComponents(components);

    // ������� �������� � ����� (����� � ����� �����)
    components.insert(components.end(), (Component*)&component1);
    //
    getComponents(components);

    // �������������� ����� ���������� ���������, ���� ������ ������ ���������, �� �������� ������
    // ���� ������ ������, �� �������� � ����� ���������
    components.resize(4);
    std::cout << components[0] << std::endl;
    //
    std::cout << "������ �������: " << components.size() << std::endl;
    std::cout << "������������ ������ ������� " << components.capacity() << std::endl;

    // �������� ������, �� �� �������������� ��
    components.reserve(7);
    std::cout << "������ �������: " << components.size() << std::endl;
    std::cout << "������������ ������ ������� " << components.capacity() << std::endl;

    // emplace_back() ������� ������ �� ���������� ��� ���������� ��� ������� �����������,
    // � ������� �� push_back()
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

    // ��������� �������� �����
    for (short i = 3; i < 6; i++){
        components[i] = components[abs(i - 5)];
    }
    // ���� �� ����� ���:
    //for (short i = 3; i < 6; i++){
    //    components.at(i) = components[abs(i - 5)];
    //   }
    //
    getComponents(components);
    // ������� ��������
    components.clear();
    std::cout << "������ �������: " << components.size() << std::endl;
    std::cout << "������������ ������ ������� " << components.capacity() << std::endl;

    // ������ ����������������� ������ ������
    components.shrink_to_fit();
    std::cout << "������ �������: " << components.size() << std::endl;
    std::cout << "������������ ������ ������� " << components.capacity() << std::endl;

    getComponents(components);
}
