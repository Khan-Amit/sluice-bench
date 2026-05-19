/* sluice_bench.c – Benchmark version for remote testing */
/* Compile: gcc sluice_bench.c -o sluice_bench */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Your is_ripe() filter – modify rules for benchmark data */
int is_ripe(const char *line) {
    /* Example: reject lines shorter than 10 chars */
    if (strlen(line) < 10) return 0;
    
    /* Add your own pattern rules here */
    /* For ClickBench, you might filter by numeric value ranges */
    
    return 1; /* accept by default */
}

int main(int argc, char *argv[]) {
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
    fprintf(stderr, "Rejection rate: %.2f%%\n", (1 - (double)accepted/total)*100);
    
    free(line);
    return 0;
}
