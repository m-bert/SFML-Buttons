#!/bin/bash

mkdir ./installation

cp ./sfml-button-font.ttf ./installation

cp -r ./sources ./installation

make -s cmp
cp ./libsfml-better-components.a ./installation

cp ./scripts/install.sh ./installation
cp ./scripts/remove.sh ./installation

tar cvzf ./sfml-better-components.tar.gz ./installation/*
rm -rf ./installation

make clean