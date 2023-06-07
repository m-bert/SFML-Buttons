# Overview
This repo contains project for C++ course at AGH UST. The goal of this project is to create an extension for SFML, that adds buttons and scenes. This will make creating SFML app easier, since developers won't have to focus on creating their own onclick mechanism.

# Repo content

This repository contains:

- scripts - directory that contains all necessary scripts:
    - bundle - script that compiles source codes, then copies it along with installation scripts and font file into one .tar.gz archive (should be run from top-level directory).
    - install - script that copies files from archive into standard include directories.
    - remove - script that removes library files from system  
- sources - directory that contains source codes of the library
- example.cpp - example app
- Makefile - used to compile sources
- sfml-better-components.tar.gz - archive that contains compiled library files
- sfml-button-font.ttf - font file (because SFML doesn't have any default font)

# Installation

This library is currently available on Linux. You can use it on Windows, however you will have to compile it from source.

To use this library you can either copy all sources to your project and add them to make/cmake, or use installation script.

## Linux 

Unpack *sfml-better-components.tar.gz* archive, then do `cd installation` and run `sudo ./install.sh`. This will copy files into include directories. After that you will be able to use it like any other library:
`#include <sfml-better-components/Button.h>`
`#include <sfml-better-components/SceneManager.h>`
`#include <sfml-better-components/Scene.h>`

Note that this is compiled as static library, so while compiling your priject with g++ you should add `-lsfml-better-components`

## Windows

Currently there are no installation scripts for Windows. To use this library You have to include all source files in your project. Than go to `Button.h` and change line
`#define FONT_PATH "/usr/local/share/fonts/sfml-button-font.ttf"` to the path where you put font file.

# Library Content
This library adds 3 components that will be described below, along with their API.

## Button.h

This is key component in the library. Button is a component that reacts to mouse clicks.

If button is used without scenes mechanism, you have to manually enable it, calling `button.setEnable(true);`. If you use scene mechanism, you can omit this step. `button.tryActivate()` should be placed in main loop. 

``` c++
#include <sfml-better-components/Button.h>

/*
...
*/

sf::Button button(&window);
button.setEnabled(true); // You can omit this line if you use scenes mechanism
button.setOnClickListener([&]()
                            { std::cout << "Hello World!" << std::endl; });

while (window.isOpen())
{
    sf::Event event;
    while (window.pollEvent(event))
    {
        /*
        ...
        */

        if (event.type == sf::Event::MouseButtonPressed)
        {
            button.tryActivate();
        }
    }
}

```

### API

- `Button(sf::RenderWindow *_window)` - Default constructor. Returns a button with size 120x40 positioned at (0,0). Fill color is set to rgb(33,33,33), default font size is set to 24 and default text is set to "Click me!".
    - `_window` - pointer to the window object

- `Button(sf::RenderWindow *_window, sf::Vector2f initialSize, sf::Vector2f initialPosition, std::string initialText)` - Constructor with parameters. Font size is set to 24 and fill color is set to rgb(33,33,33).
    - `_window` - pointer to the window object
    - `initialSize` - initial size of button
    - `initialPosition` - initial position of button
    - `initialText` - initial text of button

- `void setOnClickListener(std::function<void()> callback` - Method that sets callback for button. Callback will be executed after clicking button, if `enabled` flag is set to true.

- `bool tryActivate()` - Method that checks if button should activate. If enabled flag is set to true and user clicked on button, this function will execute callback.
    - Returns:
        - `true` if callback was executed.
        - `false` otherwise


- `void addActiveButton(sf::Mouse::Button mouseButton)` - Method that allows to add mouse button that button component should respond to
     - `mouseButton` - mouse button that should activate component

- `void removeActiveButton(sf::Mouse::Button mouseButton)` - Method that allows to remove mouse button that button component should respond to
    - `mouseButton` mouse button to remove that activates component

- `sf::Text &getText()` - Method that returns buttons text

- `sf::RectangleShape &getShape()` - Method that returns buttons shape

- `void setEnabled(bool enabled)` - Method that enables/disables button
    - `enabled` - boolean flag that represents whether button should be enabled or not

- `void setPosition(sf::Vector2f position)` - Method that changes button's position on screen. It should be used instead of changing only shape's position, because it also changes text position.
    -  `position` - new position for button

- `void setSize(sf::Vector2f size)` - Method that changes button's size. It should be used instead of changing only shape's size, because it also changes text position.\
    - `size` - new size for button

- `const static bool isMouseButtonPressed(sf::Event event, sf::Mouse::Button button)` - Method that checks whether mouse button was pressed.
    - `event` - current event obtained by `window.pollEvent()` method
    - `button` - SFML code for button (of type `sf::Mouse::Button`)

## Scene

Scene is a container that stores `sf::Drawable` objects.

```c++
#include <sfml-better-components/Scene.h>

/*
...
*/

sf::Scene scene;
scene.addElement(&circle);
```

### API

- `void addElement(sf::Drawable *element)` - Method that adds element to scene.
    - `element` - pointer to element that should be added to scene

- `void removeElement(sf::Drawable *element)` -  Method that removes element from scene.
    - `element` - pointer to element that should be removed from scene

- `void clear()` - Method that clears scene

- `void enableButtons(bool value)` - Method that sets enabled flag on each button on the scene.
    - `value` - boolean flag that represents, whether buttons on scene should be active or not

- `std::vector<sf::Drawable *> getElements() const` - Method that returns elements from scene.

## SceneManager
```c++
#include <sfml-better-components/SceneManager.h>

/*
...
*/

sf::RenderWindow window(sf::VideoMode(800, 800), "SFML Better Buttons Example!");
sf::CircleShape circle(100.0f);

sf::SceneManager sceneManager(&window);

sf::Scene scene;
scene.addElement(&circle);

sceneManager.setScene(&scene);

while (window.isOpen())
{
    window.clear();
    sceneManager.draw();
    window.display();
}
```

SceneManager defines which scene should be currently displayed on window.

### API

- `SceneManager(sf::RenderWindow *window)` - Default constructor that creates new scene manager

- `void setScene(sf::Scene *newScene)` - Method that sets current scene that should be drawn on the window. It disables all buttons on previous scene and enables buttons on scene passed in argument.
    - `newScene` - pointer to the scene that should be drawn on the window

- `void draw()` - Method that draws current scene on the window.

# Example Usage

## Button

Below you can find small example of using button. For more complicated usage see example app (`example.cpp`).

``` c++
#include <SFML/Graphics.hpp>
#include <iostream>

#include <sfml-better-components/Button.h>

int main()
{

    sf::RenderWindow window(sf::VideoMode(800, 800), "SFML Better Buttons Example!");

    sf::Button button(&window);
    button.setEnabled(true);
    button.setOnClickListener([&]()
                              { std::cout << "Hello World!" << std::endl; });

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }

            if (event.type == sf::Event::MouseButtonPressed)
            {
                button.tryActivate();
            }
        }

        window.clear();
        window.draw(button);
        window.display();
    }

    return 0;
}
```

## Scenes and SceneManager

Below you can find simple example of scenes mechanism. For more complicated usage see example app (`example.cpp`).

```c++
#include <SFML/Graphics.hpp>
#include <iostream>

#include <sfml-better-components/Scene.h>
#include <sfml-better-components/SceneManager.h>

int main()
{

    sf::RenderWindow window(sf::VideoMode(800, 800), "SFML Better Buttons Example!");

    sf::CircleShape circle(100.0f);

    sf::SceneManager sceneManager(&window);

    sf::Scene scene;

    scene.addElement(&circle);

    sceneManager.setScene(&scene);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }

        window.clear();
        sceneManager.draw();
        window.display();
    }

    return 0;
}
```
