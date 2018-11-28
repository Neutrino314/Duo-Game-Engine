CC = g++
LINKERFLAGS = -lSDL2 -lpthread -lSDL2_image
INCLUDE_DIRS = -Isource/

output: DUO.a main.cpp
	$(CC) $(INCLUDE_DIRS) -std=c++14 -c main.cpp -o main.o
	$(CC) $(INCLUDE_DIRS) -std=c++14 -o output main.cpp DUO.a $(LINKERFLAGS)
	rm main.o DUO.a

DUO.a: source/*.cpp source/*.h
	$(CC) $(INCLUDE_DIRS) -std=c++14 -c source/runtime/DUO-application.cpp -o DUO-application.o
	$(CC) $(INCLUDE_DIRS) -std=c++14 -c source/graphics/DUO-Graphics.cpp -o DUO-Graphics.o
	$(CC) $(INCLUDE_DIRS) -std=c++14 -c source/maths/DUO-Maths.cpp -o DUO-Maths.o
	$(CC) $(INCLUDE_DIRS) -std=c++14 -c source/gameObject/DUO-Scene.cpp -o DUO-Scene.o
	$(CC) $(INCLUDE_DIRS) -std=c++14 -c source/gameObject/DUO-GameObject.cpp -o DUO-GameObject.o
	$(CC) $(INCLUDE_DIRS) -std=c++14 -c source/gameObject/DUO-GameObjectComponent.cpp -o DUO-GameObjectComponent.o
	$(CC) $(INCLUDE_DIRS) -std=c++14 -c source/runtime/DUO-Keyboard.cpp -o DUO-Keyboard.o
	$(CC) $(INCLUDE_DIRS) -std=c++14 -c source/userComponents.cpp -o userComponents.o
	ar rsv DUO.a *.o
	rm *.o

clean:
	rm output *.o *.a
