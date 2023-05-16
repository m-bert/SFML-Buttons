#include "SceneManager.h"

void sf::SceneManager::setScene(sf::Scene *new_scene)
{
    if (scene != nullptr)
    {
        scene->enableButtons(false);
    }

    scene = new_scene;
    scene->enableButtons(true);
}

void sf::SceneManager::draw(sf::RenderWindow &window)
{
    for (auto element : scene->getElements())
    {
        window.draw(*element);
    }
}