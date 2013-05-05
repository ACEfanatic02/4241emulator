#include <stdio.h>

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

int main(void) {
    
    byte memory[16] = {
        0x3,0x3,0x3,0x4,
        0x4,0x1,0xB,0x9,
        0x8,0x0,0x0,0x0,
        0x0,0x0,0x0,0x0
    };

    processor * results;
    results = run(memory);

    if (results == NULL) {
        printf("An error occurred running the program.\n");
    } else {
        print_results(results);
    }

    return 0;
}