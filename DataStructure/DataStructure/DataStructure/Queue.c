// Queue implementation in C

#include <stdio.h>
#define SIZE 5

void enQueue(int);
void deQueue();
void display();

int items[SIZE], front = -1, rear = -1;

int main() {
    //deQueue is not possible on empty queue
    deQueue(); display();

    //enQueue 5 elements
    enQueue(1); display();
    enQueue(2); display();
    enQueue(3); display();
    enQueue(4); display();
    enQueue(5); display();

    // 6th element can't be added to because the queue is full
    enQueue(6); display();

    display();

    //deQueue removes element entered first i.e. 1
    deQueue();
    deQueue();
    deQueue();
    deQueue();
    deQueue();
    deQueue();
    deQueue();
    //Now we have just 4 elements
    display();

    return 0;
}

void enQueue(int value) {
    if (rear == SIZE - 1)
        printf("\nQueue is Full!!");
    else {
        if (front == -1)
            front = 0;
        rear++;
        items[rear] = value;
        printf("\nInserted -> %d , rear = %d ", value, rear);
    }
}

void deQueue() {
    if (front == -1)
        printf("\nQueue is Empty!! , front : %d , rear : %d" , front , rear );
    else {
        printf("\nDeleted : %d : front = %d ", items[front], front);
        front++;
        if (front > rear)
            front = rear = -1;
    }
}

// Function to print the queue
void display() {
    if (rear == -1)
        printf("\nQueue is Empty!! , front : %d , rear : %d", front, rear);
    else {
        int i;
        printf("\nQueue elements are:\n");
        for (i = front; i <= rear; i++)
            printf("%d  ", items[i]);
    }
    printf("\n");
}