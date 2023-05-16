#ifndef SCENE_H_
#define SCENE_H_

#include <SFML/Graphics.hpp>
#include <vector>
#include <cstdarg>
#include <iostream>

#include "Button.h"

namespace sf
{
    class Scene
    {
    private:
        std::vector<sf::Drawable *> elements;

    public:
        Scene() {}

        void addElement(sf::Drawable *element);
        void removeElement(sf::Drawable *element);
        void clear();
        void enableButtons(bool value);

        std::vector<sf::Drawable *> getElements() const { return elements; }
    };
}

#endif