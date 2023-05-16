#ifndef SCENE_H_
#define SCENE_H_

#include <SFML/Graphics.hpp>
#include <vector>
#include <cstdarg>
#include <iostream>

#include "Button.h"

namespace sf
{
    /**
     *  Class that represents scene that can be drawn on window
     */
    class Scene
    {
    private:
        std::vector<sf::Drawable *> elements;

    public:
        /**
         * Default constructor that creates scene
         */
        Scene() {}

        /**
         * Method that adds element to scene
         * @param element pointer to element that should be added to scene
         */
        void addElement(sf::Drawable *element);

        /**
         * Method that removes element from scene
         * @param element pointer to element that should be removed from scene
         */
        void removeElement(sf::Drawable *element);

        /**
         * Method that clears scene
         */
        void clear();

        /**
         * Method that sets enabled flag on each button on the scene
         * @param value boolean flag that represents, whether buttons on scene should be active or not
         */
        void enableButtons(bool value);

        /**
         * Method that returns elements from scene
         * @return vector of pointers to elements on scene
         */
        std::vector<sf::Drawable *> getElements() const { return elements; }
    };
}

#endif