#ifndef BETTER_WINDOW_H_
#define BETTER_WINDOW_H_

#include <SFML/Graphics.hpp>
#include "Scene.h"

namespace sf
{
    class SceneManager
    {
    private:
        sf::Scene *scene = nullptr;

    public:
        SceneManager() {}

        void setScene(sf::Scene *new_scene);
        void draw(sf::RenderWindow &window);
    };
};

#endif