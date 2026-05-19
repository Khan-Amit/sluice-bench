CC = gcc
CFLAGS = -Wall -O2

sluice_bench: sluice_bench.c
	$(CC) $(CFLAGS) -o sluice_bench sluice_bench.c

clean:
	rm -f sluice_bench
