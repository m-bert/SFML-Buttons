#ifndef BETTER_WINDOW_H_
#define BETTER_WINDOW_H_

#include <SFML/Graphics.hpp>
#include "Scene.h"

namespace sf
{
    /**
     * Class that represents scene manager. It allows us to set current scenes and drawing it to the window.
     */
    class SceneManager
    {
    private:
        sf::RenderWindow *window;
        sf::Scene *scene = nullptr;

    public:
        /**
         * Default constructor that creates new scene manager
         */
        SceneManager(sf::RenderWindow *window)
        {
            this->window = window;
        }

        /**
         * Method that sets current scene that should be drawn on the window.
         * @param newScene pointer to the scene that should be drawn on the window
         */
        void setScene(sf::Scene *newScene);

        /**
         * Method that draws current scene on the window
         */
        void draw();
    };
};

#endif