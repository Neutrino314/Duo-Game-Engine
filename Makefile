CC = g++ 
LINKERFLAGS = -lSDL2 -lpthread

output: main.o DUO.a
	$(CC) -o output main.cpp DUO.a $(LINKERFLAGS)
	rm main.o DUO.a

DUO.a: source/DUO-Engine.h source/DUO-Runtime.cpp source/DUO-Runtime.h source/DUO-Graphics.h source/DUO-Graphics.cpp source/DUO-Maths.h source/DUO-Maths.cpp
	$(CC) -c source/DUO-Runtime.cpp -o DUO-Runtime.o
	$(CC) -c source/DUO-Graphics.cpp -o DUO-Graphics.o
	$(CC) -c source/DUO-Maths.cpp -o DUO-Maths.o
	ar rsv DUO.a DUO-Runtime.o DUO-Graphics.o DUO-Maths.o
	rm DUO-Runtime.o DUO-Graphics.o

clean:
	rm output *.o *.a