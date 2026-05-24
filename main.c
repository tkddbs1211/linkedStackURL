#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedStack.h"

int main() {
    linkedStack* myStack = createLinkedStack();
    if (myStack == NULL) return -1;

    int menu = 0;
    char urlInput[100];
    char tempURL[100];

    while (1) {
        printf("input");
        scanf("%d", &menu);

        if (menu == 1) {
            printf("URL input:\n");
            scanf("%s", urlInput);

            pushLinkedStack(myStack, urlInput);

            if (peekLinkedStack(myStack, tempURL)) {
                printf("current URL: %s\n", tempURL);
            }
        }
        else if (menu == 2) {
            if (popLinkedStack(myStack, tempURL)) {
                printf("quit: %s\n", tempURL);

                if (emptyLinkedStack(myStack)) {
                    printf("browser closed.\n");
                    destroyLinkedStack(myStack);
                    break;
                }
                else {
                    char currentURL[100];
                    peekLinkedStack(myStack, currentURL);
                    printf("       current URL: %s\n", currentURL);
                }
            }
        }
        else if (menu == 3) {
            if (peekLinkedStack(myStack, tempURL)) {
                printf("current URL: %s\n", tempURL);
            }
        }
    }
    return 0;
}