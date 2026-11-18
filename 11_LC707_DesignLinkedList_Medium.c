#include <stdlib.h>

struct Node
{
    int val;
    struct Node *next;
};

typedef struct
{
    struct Node *head;
    int size;
} MyLinkedList;

MyLinkedList* myLinkedListCreate()
{
    MyLinkedList *list = (MyLinkedList*)malloc(sizeof(MyLinkedList));

    list->head = NULL;
    list->size = 0;

    return list;
}

int myLinkedListGet(MyLinkedList* obj, int index)
{
    if(index < 0 || index >= obj->size)
        return -1;

    struct Node *temp = obj->head;

    int i;

    for(i = 0; i < index; i++)
    {
        temp = temp->next;
    }

    return temp->val;
}

void myLinkedListAddAtHead(MyLinkedList* obj, int val)
{
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->val = val;
    newNode->next = obj->head;

    obj->head = newNode;
    obj->size++;
}

void myLinkedListAddAtTail(MyLinkedList* obj, int val)
{
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->val = val;
    newNode->next = NULL;

    if(obj->head == NULL)
    {
        obj->head = newNode;
    }
    else
    {
        struct Node *temp = obj->head;

        while(temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newNode;
    }

    obj->size++;
}

void myLinkedListAddAtIndex(MyLinkedList* obj, int index, int val)
{
    if(index < 0 || index > obj->size)
        return;

    if(index == 0)
    {
        myLinkedListAddAtHead(obj, val);
        return;
    }

    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    struct Node *temp = obj->head;

    int i;

    for(i = 0; i < index - 1; i++)
    {
        temp = temp->next;
    }

    newNode->val = val;
    newNode->next = temp->next;

    temp->next = newNode;

    obj->size++;
}

void myLinkedListDeleteAtIndex(MyLinkedList* obj, int index)
{
    if(index < 0 || index >= obj->size)
        return;

    struct Node *temp = obj->head;

    if(index == 0)
    {
        obj->head = temp->next;
        free(temp);
    }
    else
    {
        int i;

        for(i = 0; i < index - 1; i++)
        {
            temp = temp->next;
        }

        struct Node *del = temp->next;

        temp->next = del->next;

        free(del);
    }

    obj->size--;
}

void myLinkedListFree(MyLinkedList* obj)
{
    struct Node *temp;

    while(obj->head != NULL)
    {
        temp = obj->head;
        obj->head = obj->head->next;

        free(temp);
    }

    free(obj);
}
