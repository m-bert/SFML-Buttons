#!/bin/bash

cp ./sfml-button-font.ttf /usr/local/share/fonts/

mkdir sfml-better-components 
cp ./sources/Button.h ./sfml-better-components/
cp ./sources/Scene.h ./sfml-better-components/
cp ./sources/SceneManager.h ./sfml-better-components/ 
cp -r ./sfml-better-components /usr/local/include
rm -rf ./sfml-better-components

cp libsfml-better-components.a /usr/local/lib/