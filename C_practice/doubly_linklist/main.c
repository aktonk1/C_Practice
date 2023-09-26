#include <stdio.h>
#include <stdlib.h>

// Define the structure for a doubly linked list node
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the beginning of the linked list
struct Node* insertAtBeginning(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    if (head == NULL) {
        return newNode;
    }
    newNode->next = head;
    head->prev = newNode;
    return newNode;
}

// Function to insert a node at the end of the linked list
struct Node* insertAtEnd(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    if (head == NULL) {
        return newNode;
    }

    struct Node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }

    current->next = newNode;
    newNode->prev = current;
    return head;
}

// Function to insert a node at a given position in the linked list
struct Node* insertAtMid(struct Node* head, int data, int position) {
    if (position < 1) {
        printf("Invalid position for insertion.\n");
        return head;
    }

    struct Node* newNode = createNode(data);

    if (position == 1) {
        newNode->next = head;
        head->prev = newNode;
        return newNode;
    }

    struct Node* current = head;
    int count = 1;

    while (count < position - 1 && current != NULL) {
        current = current->next;
        count++;
    }

    if (current == NULL) {
        printf("Position out of range for insertion.\n");
        return head;
    }

    newNode->next = current->next;
    if (current->next != NULL) {
        current->next->prev = newNode;
    }
    current->next = newNode;
    newNode->prev = current;

    return head;
}

// Function to delete a node with a given value from the linked list
struct Node* deleteNode(struct Node* head, int key) {
    struct Node* current = head;

    while (current != NULL && current->data != key) {
        current = current->next;
    }

    if (current == NULL) {
        printf("Key not found in the list.\n");
        return head;
    }

    if (current->prev != NULL) {
        current->prev->next = current->next;
    }
    if (current->next != NULL) {
        current->next->prev = current->prev;
    }

    if (current == head) {
        head = current->next;
    }

    free(current);
    return head;
}

// Function to display the linked list from the beginning
void displayList(struct Node* head) {
    struct Node* current = head;
    printf("Doubly Linked List: ");
    while (current != NULL) {
        printf("%d <-> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;
    int choice, data, position, key;

    while (1) {
        printf("\n1. Insert at the beginning\n2. Insert at the end\n3. Insert at a position\n4. Delete a node\n5. Display\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert at the beginning: ");
                scanf("%d", &data);
                head = insertAtBeginning(head, data);
                break;
            case 2:
                printf("Enter data to insert at the end: ");
                scanf("%d", &data);
                head = insertAtEnd(head, data);
                break;
            case 3:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                printf("Enter position for insertion: ");
                scanf("%d", &position);
                head = insertAtMid(head, data, position);
                break;
            case 4:
                printf("Enter data to delete: ");
                scanf("%d", &key);
                head = deleteNode(head, key);
                break;
            case 5:
                displayList(head);
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
