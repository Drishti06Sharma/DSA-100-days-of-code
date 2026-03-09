#include <stdio.h>
#define MAX 100

int queue[MAX];
int front = -1, rear = -1;

/* Enqueue */
void enqueue(int value) {
    if ((rear + 1) % MAX == front) {
        printf("Queue Overflow\n");
        return;
    }

    if (front == -1)
        front = 0;

    rear = (rear + 1) % MAX;
    queue[rear] = value;
}

/* Dequeue */
int dequeue() {
    if (front == -1) {
        printf("Queue Underflow\n");
        return -1;
    }

    int value = queue[front];

    if (front == rear)
        front = rear = -1;
    else
        front = (front + 1) % MAX;

    return value;
}

/* Display */
void display() {
    int i = front;

    while (1) {
        printf("%d ", queue[i]);
        if (i == rear)
            break;
        i = (i + 1) % MAX;
    }
}

int main() {
    int n, m, value;
    int removed[MAX];

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        enqueue(value);
    }

    scanf("%d", &m);

    for (int i = 0; i < m; i++) {
        removed[i] = dequeue();
    }

    /* Reinsert removed elements to show circular behavior */
    for (int i = 0; i < m; i++) {
        enqueue(removed[i]);
    }

    display();

    return 0;
}