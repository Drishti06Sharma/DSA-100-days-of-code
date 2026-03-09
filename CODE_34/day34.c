#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* top = NULL;

/* Push operation */
void push(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = top;
    top = newNode;
}

/* Pop operation */
int pop() {
    if (top == NULL) {
        printf("Stack Underflow\n");
        return 0;
    }
    struct Node* temp = top;
    int value = temp->data;
    top = top->next;
    free(temp);
    return value;
}

int main() {
    char expr[100];
    
    fgets(expr, sizeof(expr), stdin);

    char* token = strtok(expr, " ");

    while (token != NULL) {

        if (isdigit(token[0]) || 
           (token[0] == '-' && isdigit(token[1]))) {
            push(atoi(token));
        }
        else {
            int op2 = pop();
            int op1 = pop();
            int result;

            switch(token[0]) {
                case '+': result = op1 + op2; break;
                case '-': result = op1 - op2; break;
                case '*': result = op1 * op2; break;
                case '/': result = op1 / op2; break;
            }

            push(result);
        }

        token = strtok(NULL, " ");
    }

    printf("%d", pop());

    return 0;
}