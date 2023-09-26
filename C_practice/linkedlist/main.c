#include <stdio.h>
#include <stdlib.h>

// Define the structure for a single node in the linked list
struct Node {
    int data;
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
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the beginning of the linked list
struct Node* insertAtBeginning(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = head;
    return newNode;
}

// Function to delete a node with a given value from the linked list
struct Node* deleteNode(struct Node* head, int key) {
    struct Node* current = head;
    struct Node* prev = NULL;

    // Check if the key is in the first node
    if (current != NULL && current->data == key) {
        struct Node* temp = current;
        head = current->next;
        free(temp);
        return head;
    }

    // Search for the key to be deleted
    while (current != NULL && current->data != key) {
        prev = current;
        current = current->next;
    }

    // If the key is not found
    if (current == NULL) {
        printf("Key not found in the list.\n");
        return head;
    }

    // Unlink the node and free memory
    prev->next = current->next;
    free(current);
    return head;
}

// Function to add a node at the end of the linked list
struct Node* appendNode(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    if (head == NULL) {
        return newNode;
    }

    struct Node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }

    current->next = newNode;
    return head;
}

// Function to display the linked list
void displayList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;
    int choice, data, key;

    while (1) {
        printf("\n1. Insert at the beginning\n2. Delete a node\n3. Add to the end\n4. Display\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert at the beginning: ");
                scanf("%d", &data);
                head = insertAtBeginning(head, data);
                break;
            case 2:
                printf("Enter data to delete: ");
                scanf("%d", &key);
                head = deleteNode(head, key);
                break;
            case 3:
                printf("Enter data to add at the end: ");
                scanf("%d", &data);
                head = appendNode(head, data);
                break;
            case 4:
                displayList(head);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
