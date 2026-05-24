#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    char data[100];     
    struct node* next;
} Node;

typedef struct linkedStack {
    Node* head;
    int size;
} linkedStack;

extern linkedStack* createLinkedStack();
extern void destroyLinkedStack(linkedStack* s);
extern int emptyLinkedStack(linkedStack* s);
extern int fullLinkedStack(linkedStack* s);
extern int pushLinkedStack(linkedStack* s, const char* item);
extern int popLinkedStack(linkedStack* s, char* item);
extern int peekLinkedStack(linkedStack* s, char* item);
extern void printLinkedStack(linkedStack* s);


