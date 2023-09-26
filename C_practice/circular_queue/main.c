#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Define the structure for the circular queue
struct CircularQueue {
    int data[MAX_SIZE];
    int front, rear;
    int size;
};

// Function to initialize an empty circular queue
void initializeQueue(struct CircularQueue *queue) {
    queue->front = queue->rear = -1;
    queue->size = 0;
}

// Function to check if the circular queue is empty
int isEmpty(struct CircularQueue *queue) {
    return queue->size == 0;
}

// Function to check if the circular queue is full
int isFull(struct CircularQueue *queue) {
    return queue->size == MAX_SIZE;
}

// Function to insert an element at the beginning of the circular queue
void insertAtBeginning(struct CircularQueue *queue, int value) {
    if (isFull(queue)) {
        printf("Queue is full. Cannot insert %d.\n", value);
        return;
    }

    if (isEmpty(queue)) {
        queue->front = queue->rear = 0;
    } else {
        queue->front = (queue->front - 1 + MAX_SIZE) % MAX_SIZE;
    }

    queue->data[queue->front] = value;
    queue->size++;
    printf("%d inserted at the beginning of the queue.\n", value);
}

// Function to insert an element at the end of the circular queue
void insertAtEnd(struct CircularQueue *queue, int value) {
    if (isFull(queue)) {
        printf("Queue is full. Cannot insert %d.\n", value);
        return;
    }

    if (isEmpty(queue)) {
        queue->front = queue->rear = 0;
    } else {
        queue->rear = (queue->rear + 1) % MAX_SIZE;
    }

    queue->data[queue->rear] = value;
    queue->size++;
    printf("%d inserted at the end of the queue.\n", value);
}

// Function to delete an element from the circular queue
int deleteElement(struct CircularQueue *queue, int value) {
    if (isEmpty(queue)) {
        printf("Queue is empty. Cannot delete.\n");
        return -1; // Return a sentinel value indicating an error
    }

    int index = queue->front;
    int deleted = 0;

    for (int i = 0; i < queue->size; i++) {
        if (queue->data[index] == value) {
            // Found the value to delete
            deleted = 1;
            break;
        }
        index = (index + 1) % MAX_SIZE;
    }

    if (deleted) {
        // Shift elements to fill the gap
        for (int i = 0; i < queue->size - 1; i++) {
            index = (index + MAX_SIZE - 1) % MAX_SIZE; // Move backward
            queue->data[(index + 1) % MAX_SIZE] = queue->data[index];
        }

        // Update rear and size
        queue->rear = (queue->rear + MAX_SIZE - 1) % MAX_SIZE;
        queue->size--;

        printf("%d deleted from the queue.\n", value);
        return value;
    } else {
        printf("%d not found in the queue.\n", value);
        return -1; // Return a sentinel value indicating the element was not found
    }
}

// Function to display the circular queue
void displayQueue(struct CircularQueue *queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty.\n");
        return;
    }

    int index = queue->front;
    printf("Circular Queue: ");
    for (int i = 0; i < queue->size; i++) {
        printf("%d ", queue->data[index]);
        index = (index + 1) % MAX_SIZE;
    }
    printf("\n");
}

int main() {
    struct CircularQueue queue;
    initializeQueue(&queue);

    int choice, value;

    while (1) {
        printf("\n1. Insert at the beginning\n2. Insert at the end\n3. Delete an element\n4. Display\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert at the beginning: ");
                scanf("%d", &value);
                insertAtBeginning(&queue, value);
                break;
            case 2:
                printf("Enter value to insert at the end: ");
                scanf("%d", &value);
                insertAtEnd(&queue, value);
                break;
            case 3:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                deleteElement(&queue, value);
                break;
            case 4:
                displayQueue(&queue);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
