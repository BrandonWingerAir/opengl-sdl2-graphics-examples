#include "object.h"
#include <stdio.h>

void printText() {
    printf("hello\n");
}

void init_programObject(programObject_t* o) {
    o->value = 0;
    o->pfnMemberFunc = printText;
}