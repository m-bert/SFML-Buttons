all:
	@g++ -c main.cpp
	@make -s cmp
	@g++ main.o Scene.o Button.o SceneManager.o -lsfml-graphics -lsfml-window -lsfml-system -o sfml-app
	@make -s clean
	@./sfml-app


cmp:
	@g++ -c ./sources/Scene.cpp
	@g++ -c ./sources/SceneManager.cpp
	@g++ -c ./sources/Button.cpp


	@ar rcs libsfml-better-components.a Scene.o SceneManager.o Button.o


example:
	@g++ -c example.cpp
	@g++ example.o -lsfml-graphics -lsfml-window -lsfml-system -lsfml-better-components -o sfml-example
	@./sfml-example

clean:
	@rm -rf ./*.a ./*.o
