#include <stdio.h>
#include <stdlib.h>

/* Definition of linked list node */
struct Node {
    int data;
    struct Node* next;
};

/* Create a new node */
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

/* Rotate linked list right by k places */
struct Node* rotateRight(struct Node* head, int k) {
    if (head == NULL || head->next == NULL || k == 0)
        return head;

    struct Node* curr = head;
    int count = 1;

    // Count nodes and reach last node
    while (curr->next != NULL) {
        curr = curr->next;
        count++;
    }

    // Make circular list
    curr->next = head;

    k = k % count;
    int stepsToNewHead = count - k;

    struct Node* newTail = curr;
    while (stepsToNewHead--) {
        newTail = newTail->next;
    }

    struct Node* newHead = newTail->next;
    newTail->next = NULL;  // break circle

    return newHead;
}

/* Print linked list */
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
}

int main() {
    int n, k, value;
    struct Node* head = NULL;
    struct Node* tail = NULL;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        struct Node* newNode = createNode(value);

        if (head == NULL) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    scanf("%d", &k);

    head = rotateRight(head, k);
    printList(head);

    return 0;
}