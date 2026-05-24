#include "linkedStack.h"

linkedStack* createLinkedStack() {
    linkedStack* re = (linkedStack*)malloc(sizeof(linkedStack));
    if (re == NULL) return NULL;
    re->head = NULL;
    re->size = 0;
    return re;
}

void destroyLinkedStack(linkedStack* s) {
    if (s == NULL) return;
    Node* current = s->head;
    Node* nextNode = NULL;
    while (current != NULL) {
        nextNode = current->next;
        free(current);
        current = nextNode;
    }
    free(s);
}

int emptyLinkedStack(linkedStack* s) {
    return s->size == 0;
}

int fullLinkedStack(linkedStack* s) {
    return 0;
}

int pushLinkedStack(linkedStack* s, const char* item) {
    Node* temp = (Node*)malloc(sizeof(Node));

    strcpy(temp->data, item); // 구조체 안의 문자열 배열에 데이터 복사
    temp->next = s->head;
    s->head = temp;
    s->size++;
    return 1;
}

int popLinkedStack(linkedStack* s, char* item) {
    if (emptyLinkedStack(s)) return 0;

    Node* temp = s->head;
    strcpy(item, temp->data); 

    s->head = temp->next;
    free(temp);
    s->size--;
    return 1;
}

int peekLinkedStack(linkedStack* s, char* item) {
    if (emptyLinkedStack(s)) return 0;

    strcpy(item, s->head->data); 
    return 1;
}

void printLinkedStack(linkedStack* s) {
    Node* temp = s->head;
    while (temp != NULL) {
        printf("%s\n", temp->data);
        temp = temp->next;
    }
}