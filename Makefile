all:
	@g++ -c example.cpp
	@make -s cmp
	@g++ example.o Scene.o Button.o SceneManager.o -lsfml-graphics -lsfml-window -lsfml-system -o sfml-better-components-example
	@make -s clean
	@./sfml-better-components-example


cmp:
	@g++ -c ./sources/Scene.cpp
	@g++ -c ./sources/SceneManager.cpp
	@g++ -c ./sources/Button.cpp


	@ar rcs libsfml-better-components.a Scene.o SceneManager.o Button.o

clean:
	@rm -rf ./*.a ./*.o
