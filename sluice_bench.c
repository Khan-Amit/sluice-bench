/* sluice_bench.c – Benchmark filter for remote testing */
/* Compile with: make  or  gcc sluice_bench.c -o sluice_bench */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Example filter rule – reject lines shorter than 10 characters */
int is_ripe(const char *line) {
    if (strlen(line) < 10) return 0;
    /* Add your own pattern rules here */
    return 1;
}

int main(void) {
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    unsigned long total = 0, accepted = 0;

    while ((read = getline(&line, &len, stdin)) != -1) {
        total++;
        if (is_ripe(line)) {
            fwrite(line, 1, read, stdout);
            accepted++;
        }
    }

    fprintf(stderr, "Total lines: %lu\n", total);
    fprintf(stderr, "Accepted: %lu\n", accepted);
    fprintf(stderr, "Rejection rate: %.2f%%\n",
            (1 - (double)accepted / total) * 100);

    free(line);
    return 0;
}
