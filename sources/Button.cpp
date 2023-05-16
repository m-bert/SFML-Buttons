#include "Button.h"
#include <iostream>

sf::Button::Button()
{
    if (!font.loadFromFile(FONT_PATH))
    {
        throw std::runtime_error("Cannot load font");
    }

    size = sf::Vector2f(120, 40);
    position = sf::Vector2f(0, 0);
    color = sf::Color(33, 33, 33);
    fontSize = sf::Button::Default_Font_Size;

    text.setFont(font);
    text.setString("Click me!");
    text.setCharacterSize(Button::Default_Font_Size);

    fixTextPosition();

    shape = sf::RectangleShape(size);
    shape.setSize(size);
    shape.setFillColor(color);
    shape.setPosition(position);

    enabled = false;
}

sf::Button::Button(sf::Vector2f initial_size, sf::Vector2f initial_position, std::string initial_text)
{
    if (!font.loadFromFile(FONT_PATH))
    {
        throw std::runtime_error("Cannot load font");
    }

    size = initial_size;
    position = initial_position;
    color = sf::Color(33, 33, 33);
    fontSize = sf::Button::Default_Font_Size;

    text.setFont(font);
    text.setString(initial_text);
    text.setCharacterSize(fontSize);

    fixTextPosition();

    shape = sf::RectangleShape(size);
    shape.setSize(size);
    shape.setFillColor(color);
    shape.setPosition(position);

    enabled = false;
}

void sf::Button::draw(sf::RenderTarget &target, sf::RenderStates state) const
{
    target.draw(shape);
    target.draw(text);
}

void sf::Button::setOnClickListener(std::function<void()> callback)
{
    this->callback = callback;
}

void sf::Button::tryActivate(sf::Vector2i mouse_position)
{
    bool x_in_bounds = mouse_position.x >= position.x && mouse_position.x <= position.x + size.x;
    bool y_in_bounds = mouse_position.y >= position.y && mouse_position.y <= position.y + size.y;

    if (enabled && x_in_bounds && y_in_bounds)
    {
        callback();
    }
}

void sf::Button::setPosition(sf::Vector2f position)
{
    shape.setPosition(position);
    this->position = position;

    fixTextPosition();
}

void sf::Button::setSize(sf::Vector2f size)
{
    shape.setSize(size);
    this->size = size;

    fixTextPosition();
}

void sf::Button::fixTextPosition()
{
    float offset_y = (size.y - sf::Button::Default_Font_Size) / 2;
    float offset_x = (size.x - text.getLocalBounds().width) / 2;
    textPosition = sf::Vector2f(position.x + offset_x, position.y + offset_y);

    text.setPosition(textPosition);
}