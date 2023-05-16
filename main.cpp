#include <SFML/Graphics.hpp>
#include <iostream>

#include "sources/Button.h"
#include "sources/Scene.h"
#include "sources/SceneManager.h"

int main()
{

    sf::RenderWindow window(sf::VideoMode(500, 500), "SFML works!");

    sf::SceneManager sceneManager;
    sf::CircleShape circle(150.0f);
    circle.setFillColor(sf::Color::Blue);

    sf::Scene scene2;
    scene2.addElement(&circle);

    sf::Button button;
    button.setOnClickListener([&]()
                              { std::cout << "Hello!" << std::endl; sceneManager.setScene(&scene2); });

    sf::Scene scene1;
    scene1.addElement(&button);

    sf::Button button2;
    button2.setPosition(sf::Vector2f(150, 150));
    button2.setSize(sf::Vector2f(200, 150));
    scene2.addElement(&button2);
    button2.setOnClickListener([&]()
                               { 
                                std::cout << "Hello2!" << std::endl; 
                                sceneManager.setScene(&scene1); });

    sceneManager.setScene(&scene1);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }

            if (sf::Button::isMouseButtonPressed(event, sf::Mouse::Right))
            {
                button.tryActivate(sf::Mouse::getPosition(window));
                button2.tryActivate(sf::Mouse::getPosition(window));
            }
        }

        window.clear();
        sceneManager.draw(window);
        window.display();
    }

    return 0;
}