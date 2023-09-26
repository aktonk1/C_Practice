#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Define the structure for the stack
struct Stack {
    int data[MAX_SIZE];
    int top;
};

// Function to initialize an empty stack
void initializeStack(struct Stack *stack) {
    stack->top = -1;
}

// Function to check if the stack is empty
int isEmpty(struct Stack *stack) {
    return stack->top == -1;
}

// Function to check if the stack is full
int isFull(struct Stack *stack) {
    return stack->top == MAX_SIZE - 1;
}

// Function to push an element onto the stack
void push(struct Stack *stack, int value) {
    if (isFull(stack)) {
        printf("Stack is full. Cannot push %d.\n", value);
    } else {
        stack->data[++stack->top] = value;
        printf("%d pushed onto the stack.\n", value);
    }
}

// Function to pop an element from the stack
int pop(struct Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty. Cannot pop.\n");
        return -1; // Return a sentinel value indicating an error
    } else {
        int value = stack->data[stack->top--];
        return value;
    }
}

// Function to display the elements in the stack
void displayStack(struct Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty.\n");
    } else {
        printf("Stack contents: ");
        for (int i = 0; i <= stack->top; i++) {
            printf("%d ", stack->data[i]);
        }
        printf("\n");
    }
}

int main() {
    struct Stack stack;
    initializeStack(&stack);

    int choice, value, poppedValue;

    while (1) {
        printf("\n1. Push\n2. Pop\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(&stack, value);
                break;
            case 2:
                poppedValue = pop(&stack);
                if (poppedValue != -1) {
                    printf("%d popped from the stack.\n", poppedValue);
                }
                break;
            case 3:
                displayStack(&stack);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
