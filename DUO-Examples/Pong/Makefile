CC = g++
LINKERFLAGS = -lSDL2 -lpthread

output: DUO.a main.cpp
	$(CC) -std=c++14 -c main.cpp -o main.o
	$(CC) -std=c++14 -o output main.cpp DUO.a $(LINKERFLAGS)
	rm main.o DUO.a

DUO.a: source/*.cpp source/*.h
	$(CC) -std=c++14 -c source/DUO-Runtime.cpp -o DUO-Runtime.o
	$(CC) -std=c++14 -c source/DUO-Graphics.cpp -o DUO-Graphics.o
	$(CC) -std=c++14 -c source/DUO-Maths.cpp -o DUO-Maths.o
	$(CC) -std=c++14 -c source/DUO-Scene.cpp -o DUO-Scene.o
	$(CC) -std=c++14 -c source/DUO-GameObject.cpp -o DUO-GameObject.o
	$(CC) -std=c++14 -c source/DUO-GameObjectComponent.cpp -o DUO-GameObjectComponent.o
	$(CC) -std=c++14 -c source/DUO-Keyboard.cpp -o DUO-Keyboard.o
	$(CC) -std=c++14 -c source/userComponents.cpp -o userComponents.o
	ar rsv DUO.a *.o
	rm *.o

clean:
	rm output *.o *.a
