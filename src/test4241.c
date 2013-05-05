#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "4241.h"

void print_results(processor * p) {
    printf("Final state:\n");
    printf("r0: %X\tr1: %X\n", p->r0, p->r1);

    printf("Memory:\n");
    int i;
    for (i = 0; i < 16; ++i) {
        printf("%X ", p->mem[i]);
        if ((i + 1) % 4 == 0) {
            printf("\n");
        }
    }
}

byte * read_program() {
    byte * mem = malloc(sizeof(byte) * 16);
    if (mem == NULL) {
        return NULL;
    }
    memset(mem, 0, 16);

    int i;
    char c;
    char * hex = malloc(sizeof(char)*4);
    for (i = 0; i < 16; ++i) {
        c = getchar();
        if (c == EOF) {
            break;
        } else if (c == '\n' || c == ' ') {
            i--;
            continue;
        } else {
            // this is hacky as *fuck*, but atoi doesn't work with base 16.
            snprintf(hex, 4, "0x%c", c);
            mem[i] = (byte)strtol(hex, NULL, 16);
        }
    }

    free(hex);
    return mem;
}

int main(void) {
    
    // byte memory[16] = {
    //     0x3,0x3,0x3,0x4,
    //     0x4,0x1,0xB,0x9,
    //     0x8,0x0,0x0,0x0,
    //     0x0,0x0,0x0,0x0
    // };

    byte * memory = read_program();

    processor * results;
    results = run(memory);

    if (results == NULL) {
        printf("An error occurred running the program.\n");
    } else {
        print_results(results);
    }

    free(memory);
    free(results);

    return 0;
}