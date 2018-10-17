CC = g++ 
LINKERFLAGS = -lSDL2

output: main.o DUO.a
	$(CC) -o output main.cpp DUO.a $(LINKERFLAGS)
	rm main.o 

DUO.a: source/DUO-Engine.h source/DUO-Runtime.cpp source/DUO-Runtime.h
	$(CC) -c source/DUO-Runtime.cpp -o DUO-Runtime.o
	ar rsv DUO.a DUO-Runtime.o
	rm DUO-Runtime.o

clean:
	rm output *.o *.a