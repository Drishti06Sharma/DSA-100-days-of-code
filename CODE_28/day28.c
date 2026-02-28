#include <stdio.h>
#include <stdlib.h>

// Define the node structure
struct Node {
    int data;
    struct Node* next;
};

int main() {
    int n, value;
    struct Node *head = NULL, *tail = NULL;

    // Read number of elements
    if (scanf("%d", &n) != 1 || n <= 0) return 0;

    for (int i = 0; i < n; i++) {
        scanf("%d", &value);

        // Dynamically allocate memory for new node
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = value;

        if (head == NULL) {
            head = newNode;
            tail = newNode;
            newNode->next = head; // Point to itself to stay circular
        } else {
            tail->next = newNode;
            tail = newNode;
            tail->next = head; // Close the loop
        }
    }

    // Traversal: Start from head and stop when we hit head again
    if (head != NULL) {
        struct Node* temp = head;
        do {
            printf("%d ", temp->data);
            temp = temp->next;
        } while (temp != head);
        printf("\n");
    }

    // Clean up memory (Important in C!)
    // Note: In a real app, you'd loop through and free() each node.
    
    return 0;
}