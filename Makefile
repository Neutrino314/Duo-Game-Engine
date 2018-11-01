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
	$(CC) -std=c++14 -c source/DUO-Utils.cpp -o DUO-Utils.o
	ar rsv DUO.a *.o
	rm *.o

clean:
	rm output *.o *.a
