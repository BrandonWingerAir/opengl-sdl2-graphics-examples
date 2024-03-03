#ifndef OBJECT_H
#define OBJECT_H

typedef struct {
    int value;
    void (*pfnMemberFunc)(void);
} programObject_t;

void init_programObject(programObject_t*);

#endif