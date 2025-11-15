#include <stdio.h>
#include <stdlib.h>

// Node definition
struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

// Function to create a linked list by inserting at the end
void create() 
{
    int n, val;
    struct Node *newNode, *temp;

    printf("Enter number of elements to insert: ");
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        newNode = (struct Node*)malloc(sizeof(struct Node));
        if (!newNode) {
            printf("Memory allocation failed.\n");
            return;
        }

        printf("Enter value for node %d: ", i + 1);
        scanf("%d", &val);
        newNode->data = val;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
        } else {
            temp = head;
            while (temp->next != NULL)
                temp = temp->next;
            temp->next = newNode;
        }
    }
}

// Delete the first node
void deleteFirst() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* temp = head;
    head = head->next;
    printf("Deleted first node with value: %d\n", temp->data);
    free(temp);
}

// Delete node with specified value
void deleteByValue() {
    int val;
    printf("Enter value to delete: ");
    scanf("%d", &val);

    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node *temp = head, *prev = NULL;

    // If head needs to be deleted
    if (head->data == val) {
        head = head->next;
        printf("Deleted node with value: %d\n", temp->data);
        free(temp);
        return;
    }

    // Traverse the list
    while (temp != NULL && temp->data != val) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Value %d not found in list.\n", val);
    } else {
        prev->next = temp->next;
        printf("Deleted node with value: %d\n", temp->data);
        free(temp);
    }
}

// Delete the last node
void deleteLast() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node *temp = head, *prev = NULL;

    // Only one node
    if (head->next == NULL) {
        printf("Deleted last node with value: %d\n", head->data);
        free(head);
        head = NULL;
        return;
    }

    // Traverse to the second last node
    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }

    printf("Deleted last node with value: %d\n", temp->data);
    prev->next = NULL;
    free(temp);
}

// Display the list
void display() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* temp = head;
    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Main function with menu
int main() {
    int choice;

    while (1) {
        printf("\n--- Singly Linked List Operations ---\n");
        printf("1. Create Linked List\n");
        printf("2. Delete First Node\n");
        printf("3. Delete Node by Value\n");
        printf("4. Delete Last Node\n");
        printf("5. Display Linked List\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: create(); break;
            case 2: deleteFirst(); break;
            case 3: deleteByValue(); break;
            case 4: deleteLast(); break;
            case 5: display(); break;
            case 6: exit(0);
            default: printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}

