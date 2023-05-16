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
        sf::Scene *scene = nullptr;

    public:
        /**
         * Default constructor that creates new scene manager
         */
        SceneManager() {}

        /**
         * Method that ets current scene that should be drawn on the window.
         * @param scene The scene that should be drawn on the window
         */
        void setScene(sf::Scene *newScene);

        /**
         * Method that draws current scene on the window
         * @param window reference to sf::RenderWindow
         */
        void draw(sf::RenderWindow &window);
    };
};

#endif