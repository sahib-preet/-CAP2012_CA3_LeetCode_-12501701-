#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int q1[100];
    int q2[100];
    int f1, r1;
    int f2, r2;
} MyStack;

MyStack* myStackCreate()
{
    MyStack* obj = malloc(sizeof(MyStack));

    obj->f1 = 0;
    obj->r1 = -1;
    obj->f2 = 0;
    obj->r2 = -1;

    return obj;
}

void myStackPush(MyStack* obj, int x)
{
    obj->q2[++obj->r2] = x;

    while(obj->f1 <= obj->r1)
    {
        obj->q2[++obj->r2] = obj->q1[obj->f1++];
    }

    obj->f1 = 0;
    obj->r1 = -1;

    while(obj->f2 <= obj->r2)
    {
        obj->q1[++obj->r1] = obj->q2[obj->f2++];
    }

    obj->f2 = 0;
    obj->r2 = -1;
}

int myStackPop(MyStack* obj)
{
    return obj->q1[obj->f1++];
}

int myStackTop(MyStack* obj)
{
    return obj->q1[obj->f1];
}

bool myStackEmpty(MyStack* obj)
{
    return obj->f1 > obj->r1;
}

void myStackFree(MyStack* obj)
{
    free(obj);
}
