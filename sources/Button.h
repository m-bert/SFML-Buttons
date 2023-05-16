#ifndef BUTTON_H_
#define BUTTON_H_

#define FONT_PATH "/usr/local/share/fonts/sfml-button-font.ttf"

#include <SFML/Graphics.hpp>

namespace sf
{
    class Button : public sf::Drawable
    {
    private:
        sf::RectangleShape shape;
        sf::Vector2f position;
        sf::Vector2f size;
        sf::Color color;

        sf::Font font;
        int fontSize;
        sf::Text text;
        sf::Vector2f textPosition;

        bool enabled;

        std::function<void()> callback;

    public:
        Button();
        Button(sf::Vector2f initial_size, sf::Vector2f initial_position, std::string initial_text);

        virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
        void setOnClickListener(std::function<void()> callback);
        void tryActivate(sf::Vector2i mouse_position);

        sf::Text &getText() { return text; }
        sf::RectangleShape &getShape() { return shape; }

        void setEnabled(bool enabled) { this->enabled = enabled; }
        void setPosition(sf::Vector2f position);
        void setSize(sf::Vector2f size);

        void fixTextPosition();

        const static int Default_Font_Size = 24;
        const static bool isMouseButtonPressed(sf::Event event, sf::Mouse::Button button)
        {
            return event.type == sf::Event::MouseButtonPressed && sf::Mouse::isButtonPressed(button);
        }
    };
}

#endif