#ifndef BUTTON_H_
#define BUTTON_H_

#define FONT_PATH "/usr/local/share/fonts/sfml-button-font.ttf"

#include <SFML/Graphics.hpp>
#include <unordered_set>

namespace sf
{
    /**
     * Class representing button. That class inherits from sf::Drawable and is implemented with usage of sf::RectangleShape and sf::Text.
     */
    class Button : public sf::Drawable
    {
    private:
        sf::RenderWindow *window;

        sf::RectangleShape shape;
        sf::Vector2f position;
        sf::Vector2f size;
        sf::Color color;

        sf::Font font;
        int fontSize;
        sf::Text text;
        sf::Vector2f textPosition;

        bool enabled;
        std::unordered_set<sf::Mouse::Button> activeButtons;

        std::function<void()>
            callback = NULL;

        /**
         * Method that changes position of text to center it inside the button
         */
        void fixTextPosition();

    public:
        /**
         * Default constructor. Returns a button with size 120x40 positioned at (0,0).
         * Fill color is set to rgb(33,33,33), default font size is set to 24 and default text is set to "Click me!".
         * @param _window pointer to the window object
         */
        Button(sf::RenderWindow *_window);

        /**
         * Constructor with parameters. Font size is set to 24 and fill color is set to rgb(33,33,33).
         * @param _window pointer to the window object
         * @param initialSize initial size of button
         * @param initialPosition initial position of button
         * @param initialText initial text of button
         */
        Button(sf::RenderWindow *_window, sf::Vector2f initialSize, sf::Vector2f initialPosition, std::string initialText);

        /**
         * Overriden method from sf::Drawable. It allows button to be drawn on screen
         */
        virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

        /**
         * Method that sets callback for button. Callback will be executed after clicking button, if enabled flag is set to true.
         * @param callback function that will be executed after clicking button. This function must be void type and it takes no arguments.
         */
        void setOnClickListener(std::function<void()> callback);

        /**
         * Method that checks if button should activate. If enabled flag is set to true and user clicked on button, this function will execute callback.
         */
        bool tryActivate();

        /**
         * Method that allows to add mouse button that button component should respond to
         * @param mouseButton mouse button that should activate component
         */
        void addActiveButton(sf::Mouse::Button mouseButton);

        /**
         * Method that allows to remove mouse button that button component should respond to
         * @param mouseButton mouse button to remove that activates component
         */
        void removeActiveButton(sf::Mouse::Button mouseButton);

        /**
         * Method that returns buttons text
         * @return text (sf::Text)
         */
        sf::Text &getText() { return text; }

        /**
         * Method that returns buttons shape
         * @return shape (sf::RectangleShape)
         */
        sf::RectangleShape &getShape() { return shape; }

        /**
         * Method that enables/disables button
         * @param enabled boolean flag that represents whether button should be enabled or not
         */
        void setEnabled(bool enabled) { this->enabled = enabled; }

        /**
         * Method that changes button's position on screen.
         * It should be used instead of changing only shape's position.
         * @param position new position for button
         */
        void setPosition(sf::Vector2f position);

        /**
         * Method that changes button's size.
         * It should be used instead of changing only shape's size.
         * @param size new size for button
         */
        void setSize(sf::Vector2f size);

        const static int Default_Font_Size = 24;

        /**
         * Method that checks whether mouse button was pressed.
         * @param event current event obtained by window.pollEvent method
         * @param button SFML code for button (of type sf::Mouse::Button)
         */
        const static bool isMouseButtonPressed(sf::Event event, sf::Mouse::Button button)
        {
            return event.type == sf::Event::MouseButtonPressed && sf::Mouse::isButtonPressed(button);
        }
    };
}

#endif