#include "Scene.h"

void sf::Scene::addElement(sf::Drawable *element)
{
    elements.push_back(element);
}

void sf::Scene::removeElement(sf::Drawable *element)
{
    for (auto it = elements.begin(); it != elements.end();)
    {
        if (*it == element)
        {
            if (sf::Button *button = dynamic_cast<sf::Button *>(*it))
            {
                button->setEnabled(false);
            }

            it = elements.erase(it);
        }
        else
        {
            ++it;
        }
    }
}

void sf::Scene::enableButtons(bool value)
{
    {
        for (auto it = elements.begin(); it != elements.end(); ++it)
        {
            if (sf::Button *button = dynamic_cast<sf::Button *>(*it))
            {
                button->setEnabled(value);
            }
        }
    }
}

void sf::Scene::clear()
{
    elements.clear();
}
