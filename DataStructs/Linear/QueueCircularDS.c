#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100

typedef struct queue {
    int arr[MAX_SIZE];
    int front, rear;
} Queue;

Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = -1;
    q->rear = -1;
    return q;
}

int isFull(Queue* q) {
    return q->front == (q->rear + 1)%MAX_SIZE;
}

int isEmpty(Queue* q) {
    return q->front == -1;
}

void enQueue(Queue* q, int data) {
    if  (isFull(q))
        return;
    
    if  (isEmpty(q)) {              
        // If queue is empty, set front and rear to 0
        q->front = 0;
        q->rear = 0;
    } else {                        
        // Else increment rear, if rear reaches MAX_SIZE, 
        // set it to 0 because it is a circular array
        q->rear = (q->rear + 1)%MAX_SIZE;
    }
    q->arr[q->rear] = data;
}

int deQueue(Queue* q) {
    if  (isEmpty(q)) 
        return -1;
    
    int data = q->arr[q->front];
    if (q->front == q->rear) {
        // If only 1 element is in queue, reset the queue 
        // by setting front and rear to -1
        q->front = -1;
        q->rear = -1;
    } else {                                
        // Else increment front, if front reaches MAX_SIZE, 
        // set it to 0 because it is a circular array
        q->front = (q->front + 1)%MAX_SIZE;
    }
    return data;
}

int getFront(Queue* q) {
    if  (isEmpty(q))
        return -1;
    return q->arr[q->front];
}

int getRear(Queue* q) {
    if  (isEmpty(q))
        return -1;
    return q->arr[q->rear];
}

void display(Queue* q) {
    if  (isEmpty(q)) {
        printf("Queue is empty\n");
        return;
    }
    for (int i = q->front; i != q->rear; i = (i + 1)%MAX_SIZE)
        // If front is greater than rear, i=(i+1)%MAX_SIZE will
        // reset the rear to 0 and continue printing
        printf("%d ", q->arr[i]);
    printf("%d\n", q->arr[q->rear]);
}

int main() {
    Queue* q = createQueue();
    enQueue(q, 1);
    enQueue(q, 2);
    enQueue(q, 3);
    enQueue(q, 4);
    enQueue(q, 5);
    display(q);
    printf("Front: %d\n", getFront(q));
    printf("Rear: %d\n", getRear(q));
    printf("Dequeued: %d\n", deQueue(q));
    display(q);
    printf("Front: %d\n", getFront(q));
    printf("Rear: %d\n", getRear(q));
    enQueue(q, 6);
    enQueue(q, 7);
    display(q);

    return 0;
}