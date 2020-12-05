
CC = gcc
CFLAGS = -g -Wall

all: mains maind #operate both of the programs
mymaths: myBank.a #operate the static library
mymathd: myBank.so#operate the dynamic library

#The main program - linking with static library
mains: main.o myBank.a
	$(CC) $(CFLAGS) -o mains main.o myBank.a

#The main program - linking with dynamic library
maind: main.o myBank.so
	$(CC) $(CFLAGS) -Wl,-rpath=. -L. main.o myBank.so -o maind

#Static library				
myBank.a: myBank.o
	ar -rcs myBank.a myBank.o		

#Dynamic library
myBank.so: myBank.o
	$(CC) -shared -o myBank.so myBank.o		

#compilation of main.c
main.o: main.c myBank.h
	$(CC) $(CFLAGS) -c main.c

#compilation of basicMath.c 
myBank.o: myBank.c myBank.h
	$(CC) $(CFLAGS) -c -fPIC myBank.c

#those are not real files
.PHONY: all clean mymaths mymathd 

clean:
	rm -f *.o *.a *.so mains maind