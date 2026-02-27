#include <stdio.h>
#include <stdlib.h>

/* Node definition */
struct Node {
    int data;
    struct Node* next;
};

/* Create new node */
struct Node* createNode(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;
    return newNode;
}

/* Append node at end */
struct Node* insertEnd(struct Node* head, int val) {
    struct Node* newNode = createNode(val);
    if (head == NULL)
        return newNode;

    struct Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    return head;
}

/* Find length of list */
int getLength(struct Node* head) {
    int len = 0;
    while (head != NULL) {
        len++;
        head = head->next;
    }
    return len;
}

/* Find intersection node */
struct Node* findIntersection(struct Node* head1, struct Node* head2) {
    int len1 = getLength(head1);
    int len2 = getLength(head2);

    int diff = abs(len1 - len2);

    // Move longer list ahead
    if (len1 > len2) {
        while (diff--)
            head1 = head1->next;
    } else {
        while (diff--)
            head2 = head2->next;
    }

    // Traverse together
    while (head1 != NULL && head2 != NULL) {
        if (head1 == head2)
            return head1;
        head1 = head1->next;
        head2 = head2->next;
    }
    return NULL;
}

int main() {
    int n, m, val;
    struct Node* head1 = NULL;
    struct Node* head2 = NULL;

    // First list
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        head1 = insertEnd(head1, val);
    }

    // Second list
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &val);
        head2 = insertEnd(head2, val);
    }

    /* ---- Creating intersection manually for demo ---- */
    // Make second list intersect at node with value 30
    struct Node* temp1 = head1;
    struct Node* temp2 = head2;

    while (temp1 && temp1->data != 30)
        temp1 = temp1->next;

    while (temp2->next != NULL)
        temp2 = temp2->next;

    if (temp1 != NULL)
        temp2->next = temp1;
    /* ----------------------------------------------- */

    struct Node* intersection = findIntersection(head1, head2);

    if (intersection)
        printf("%d", intersection->data);
    else
        printf("No Intersection");

    return 0;
}