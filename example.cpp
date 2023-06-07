#include <SFML/Graphics.hpp>
#include <iostream>

#include "sources/Button.h"
#include "sources/Scene.h"
#include "sources/SceneManager.h"

int main()
{

    sf::RenderWindow window(sf::VideoMode(800, 800), "SFML Better Buttons Example!");

    sf::Font font;
    sf::Text text1, text2;

    sf::CircleShape circle1(100.0f), circle2(100.f);

    // Create Scene Manager instance
    sf::SceneManager sceneManager(&window);

    // Declare scenes that will be used in application
    sf::Scene scene1, scene2;

    // Create buttons
    sf::Button button1(&window, sf::Vector2f(100.f, 50.f), sf::Vector2f(350.f, 100.f), "Hello!");
    sf::Button button2(&window, sf::Vector2f(100.f, 50.f), sf::Vector2f(350.f, 100.f), "Go back!");

    if (!font.loadFromFile(FONT_PATH))
    {
        throw std::runtime_error("Cannot load font");
    }

    text1.setFont(font);
    text1.setString("Welcome on first scene!");
    text1.setCharacterSize(24);
    text1.setPosition(sf::Vector2f(260.f, 0.f));

    text2.setFont(font);
    text2.setString("Welcome on second scene!");
    text2.setCharacterSize(24);
    text2.setPosition(sf::Vector2f(260.f, 0.f));

    circle1.setFillColor(sf::Color::Green);
    circle1.setPosition(sf::Vector2f(300.f, 300.f));
    circle2.setFillColor(sf::Color::Blue);
    circle2.setPosition(sf::Vector2f(300.f, 300.f));

    // Add elements to scenes
    scene1.addElement(&text1);
    scene1.addElement(&circle1);
    scene1.addElement(&button1);

    scene2.addElement(&text2);
    scene2.addElement(&circle2);
    scene2.addElement(&button2);

    // Set current scene
    sceneManager.setScene(&scene1);

    // Set on click handlers for buttons
    button1.setOnClickListener([&]()
                               { sceneManager.setScene(&scene2); });
    button2.setOnClickListener([&]()
                               { sceneManager.setScene(&scene1); });

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }

            // Check if event was mouse event
            if (event.type == sf::Event::MouseButtonPressed)
            {
                // Lazy evaluation because buttons are at the same position, therefore switching scenes
                // result in enabling button 2 and immidately going back to scene 1
                const bool pressed = button1.tryActivate() || button2.tryActivate();

                if (pressed)
                {
                    continue;
                }
            }
        }

        window.clear();
        sceneManager.draw(); // Draw scene (instead of window.draw())
        window.display();
    }

    return 0;
}