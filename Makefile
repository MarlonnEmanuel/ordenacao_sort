CC = gcc
CFLAGS = -Wall -O2
TARGET = sort

all: $(TARGET)

$(TARGET): main.c
	$(CC) $(CFLAGS) -o $(TARGET) main.c

clean:
	rm -f $(TARGET)

run: $(TARGET)
	@echo "Uso: make run FILE=<nome do arquivo>"
	@exit 1

run-file: $(TARGET)
	./$(TARGET) $(FILE)
