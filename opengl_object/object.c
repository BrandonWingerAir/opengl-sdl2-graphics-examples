#include "object.h"
#include <stdio.h>

void printText() {
    printf("Success: Program object function initiated.\n");
}

void init_programObject(programObject_t* o) {
    o->value = 0;
    o->pfnMemberFunc = printText;
}