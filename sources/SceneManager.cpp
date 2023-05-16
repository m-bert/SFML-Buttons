#include "SceneManager.h"

void sf::SceneManager::setScene(sf::Scene *newScene)
{
    if (scene != nullptr)
    {
        scene->enableButtons(false);
    }

    scene = newScene;
    scene->enableButtons(true);
}

void sf::SceneManager::draw(sf::RenderWindow &window)
{
    for (auto element : scene->getElements())
    {
        window.draw(*element);
    }
}