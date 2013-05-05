#include <stdio.h>

#include "4241.h"

int main(int argc, char const *argv[]) {
    
    byte memory[16] = {
        0x0,0x0,0x0,0x0,
        0x0,0x0,0x0,0x0,
        0x0,0x0,0x0,0x0,
        0x0,0x0,0x0,0x0
    };

    processor * results;
    results = run(memory);

    if (results == NULL) {
        printf("An error occurred running the program.\n");
    }

    return 0;
}