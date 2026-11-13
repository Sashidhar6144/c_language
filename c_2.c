#include <stdio.h>
#include <stdlib.h>

// Structure for a node in a doubly linked list
typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} Node;

// Function prototypes
Node* createNode(int data);
void insertAtBeginning(Node** head, int data);
void insertAtEnd(Node** head, int data);
void insertAfter(Node* prev_node, int data);
void deleteNode(Node** head, Node* del_node);
void deleteByValue(Node** head, int value);
void displayForward(Node* head);
void displayBackward(Node* head);
Node* search(Node* head, int value);
void freeList(Node** head);

// Helper function to allocate memory for a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Insert a node at the beginning of the list
void insertAtBeginning(Node** head, int data) {
    Node* newNode = createNode(data);
    newNode->next = *head;

    if (*head != NULL) {
        (*head)->prev = newNode;
    }

    *head = newNode;
    printf("Inserted %d at the beginning.\n", data);
}

// Insert a node at the end of the list
void insertAtEnd(Node** head, int data) {
    Node* newNode = createNode(data);
    
    if (*head == NULL) {
        *head = newNode;
        printf("Inserted %d as the first node.\n", data);
        return;
    }

    Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->prev = temp;
    printf("Inserted %d at the end.\n", data);
}

// Insert a node after a specific given node
void insertAfter(Node* prev_node, int data) {
    if (prev_node == NULL) {
        printf("The given previous node cannot be NULL.\n");
        return;
    }

    Node* newNode = createNode(data);
    newNode->next = prev_node->next;
    prev_node->next = newNode;
    newNode->prev = prev_node;

    if (newNode->next != NULL) {
        newNode->next->prev = newNode;
    }

    printf("Inserted %d after %d.\n", data, prev_node->data);
}

// Delete a specific node pointer
void deleteNode(Node** head, Node* del_node) {
    if (*head == NULL || del_node == NULL) {
        return;
    }

    // If node to be deleted is head node
    if (*head == del_node) {
        *head = del_node->next;
    }

    // Change next only if node to be deleted is NOT the last node
    if (del_node->next != NULL) {
        del_node->next->prev = del_node->prev;
    }

    // Change prev only if node to be deleted is NOT the first node
    if (del_node->prev != NULL) {
        del_node->prev->next = del_node->next;
    }

    free(del_node);
}

// Search and delete first node matching value
void deleteByValue(Node** head, int value) {
    Node* target = search(*head, value);
    if (target != NULL) {
        deleteNode(head, target);
        printf("Deleted node with value %d.\n", value);
    } else {
        printf("Value %d not found in the list.\n", value);
    }
}

// Traverse and print list forward
void displayForward(Node* head) {
    Node* temp = head;
    printf("List (Forward):  ");
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Traverse and print list backward
void displayBackward(Node* head) {
    if (head == NULL) {
        printf("List (Backward): NULL\n");
        return;
    }

    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    printf("List (Backward): ");
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->prev;
    }
    printf("NULL\n");
}

// Search for a target value in the list
Node* search(Node* head, int value) {
    Node* current = head;
    while (current != NULL) {
        if (current->data == value) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

// Free allocated memory for all nodes
void freeList(Node** head) {
    Node* current = *head;
    Node* nextNode = NULL;

    while (current != NULL) {
        nextNode = current->next;
        free(current);
        current = nextNode;
    }

    *head = NULL;
    printf("Memory for the list has been freed.\n");
}

// Main execution function
int main() {
    Node* head = NULL;

    // Building list
    insertAtEnd(&head, 10);
    insertAtEnd(&head, 20);
    insertAtBeginning(&head, 5);
    insertAtEnd(&head, 30);
    
    // Display operations
    printf("\n--- Current List State ---\n");
    displayForward(head);
    displayBackward(head);

    // Specific node operations
    printf("\n--- Modification Operations ---\n");
    Node* target = search(head, 20);
    if (target != NULL) {
        insertAfter(target, 25);
    }

    displayForward(head);

    // Deletion
    deleteByValue(&head, 5);
    deleteByValue(&head, 30);

    printf("\n--- Final List State ---\n");
    displayForward(head);
    displayBackward(head);

    // Cleanup
    printf("\n--- Cleanup ---\n");
    freeList(&head);

    return 0;
}