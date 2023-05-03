#include <stdio.h>

#define MAX 5

int queue[MAX];
int front = -1, rear = -1;

void enqueue(int item) {
    if ((front == 0 && rear == MAX - 1) || (front == rear + 1)) {
        printf("Queue is full!\n");
        return;
    }
    if (front == -1) {
        front = 0;
        rear = 0;
    }
    else {
        if (rear == MAX - 1)
            rear = 0;
        else
            rear++;
    }
    queue[rear] = item;
}

int dequeue() {
    if (front == -1) {
        printf("Queue is empty!\n");
        return -1;
    }
    int item = queue[front];
    if (front == rear) {
        front = -1;
        rear = -1;
    }
    else {
        if (front == MAX - 1)
            front = 0;
        else
            front++;
    }
    return item;
}

void display() {
    if (front == -1) {
        printf("Queue is empty!\n");
        return;
    }
    printf("Circular Queue:\n");
    if (rear >= front) {
        for (int i = front; i <= rear; i++)
            printf("%d ", queue[i]);
    }
    else {
        for (int i = front; i < MAX; i++)
            printf("%d ", queue[i]);
        for (int i = 0; i <= rear; i++)
            printf("%d ", queue[i]);
    }
    printf("\n");
}

int main() {
    int choice, item;
    do {
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf_s("%d", &choice);
        switch (choice) {
        case 1:
            printf("Enter the number to enqueue: ");
            scanf_s("%d", &item);
            enqueue(item);
            break;
        case 2:
            item = dequeue();
            if (item != -1)
                printf("Dequeued item: %d\n", item);
            break;
        case 3:
            display();
            break;
        case 4:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice!\n");
            break;
        }
    } while (choice != 4);
    return 0;
}
