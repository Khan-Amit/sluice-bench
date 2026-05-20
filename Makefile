CC = gcc
CFLAGS = -Wall -O2
TARGET = sluice_bench

all: $(TARGET)

$(TARGET): sluice_bench.c
	$(CC) $(CFLAGS) -o $(TARGET) sluice_bench.c

clean:
	rm -f $(TARGET)

.PHONY: all clean
