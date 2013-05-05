#include <stdlib.h>
#include <stdio.h>

#include "4241.h"

program_state_t instruction(processor * p, program_state_t state) {

    byte data;

    switch(p->mem[state.cur]) {
        case 0x0:
            state.halt = 1;
            break;
        case 0x1:
            p->r0 = (p->r0 + p->r1) % 16;
            break;
        case 0x2:
            p->r0 = (p->r0 - p->r1) % 16;
            break;
        case 0x3:
            p->r0++;
            p->r0 %= 16;
            break;
        case 0x4:
            p->r1++;
            p->r1 %= 16;
            break;
        case 0x5:
            p->r0--;
            p->r0 %= 16;
            break;
        case 0x6:
            p->r1--;
            p->r1 %= 16;
            break;
        case 0x7:
            printf("\a");
            data = p->r0;
            p->r0 = p->r1;
            p->r1 = data;
            break;
        case 0x8:
            printf("%d\n", p->mem[++(state.cur)]);
            break;
        case 0x9:
            p->r0 = p->mem[++(state.cur)];
            break;
        case 0xA:
            p->r1 = p->mem[++(state.cur)];
            break;
        case 0xB:
            data = p->mem[++(state.cur)];
            p->mem[data] = p->r0;
            break;
        case 0xC:
            data = p->mem[++(state.cur)];
            p->mem[data] = p->r1;
            break;
        case 0xD:
            state.cur = p->mem[state.cur + 1];
            return state;
        case 0xE:
            if (p->r0 == 0) {
                state.cur = p->mem[state.cur + 1];
            } else {
                state.cur++;
            }
        case 0xF:
            if (p->r0 != 0) {
                state.cur = p->mem[state.cur + 1];
            } else {
                state.cur++;
            }
        default:
            printf("Unknown instruction: %d\nHalting...", p->mem[state.cur]);
            state.halt = 1;
    }

    state.cur++;
    return state;
}

processor * run(byte memory[16]) {
    processor * p = malloc(sizeof(processor));
    if (p == NULL || memory == NULL) {
        return NULL;
    }

    p->r0 = 0;
    p->r1 = 0;

    int i;
    for (i = 0; i < 16; ++i) {
        p->mem[i] = memory[i];
    }
    
    program_state_t state;

    while (state.cur < 16 && !state.halt) {
        state = instruction(p, state);
    }

    return p;
}
