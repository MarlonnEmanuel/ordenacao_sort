CC = gcc
CFLAGS = -Wall -g
TARGET = main

all: $(TARGET)

$(TARGET): main.o sorts.o
	$(CC) $(CFLAGS) -o $(TARGET) main.o sorts.o

main.o: main.c
	$(CC) $(CFLAGS) -c main.c

sorts.o: sorts.c
	$(CC) $(CFLAGS) -c sorts.c

clean:
	rm -f *.o $(TARGET)
