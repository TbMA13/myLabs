#include <SFML/Graphics.hpp>
#include <chrono>
#include <thread>
#include <iostream>

enum class Colors {
    RED = 2,
    GREEN = 5
};

int main()
{
    std::cout << Colors::RED;
//    Colors red = Colors::RED;
//    std::cout << red;
    float t = 0;
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color(0xFFFFFFFF));

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        shape.setPosition(10*t, 10 * t);
        t += 0.1;

        std::this_thread::sleep_for(std::chrono::milliseconds (10));
        window.clear();
        window.draw(shape);
        window.display();
    }

    return 0;
}