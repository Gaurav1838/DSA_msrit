#include <stdio.h>
#include <stdlib.h>

// Define a structure for a node in the linked list
struct node {
    int data;
    struct node *next;
};

// Initialize the top of the stack as NULL
struct node *top = 0;

// Function to push an element onto the stack
void push(int x) {
    struct node *newnode = (struct node*)malloc(sizeof(struct node)); // Allocate memory for new node
    newnode->data = x; // Assign data to the new node
    newnode->next = top; // Point new node to previous top
    top = newnode; // Update top to new node
}

// Function to display the elements of the stack
void display() {
    struct node *temp = top; // Start from the top
    if (top == 0) {
        printf("Stack is empty\n");
    } else {
        while (temp != 0) { // Traverse through stack
            printf("%d\n", temp->data);
            temp = temp->next;
        }
    }
}

// Function to get the top element of the stack
void peek() {
    if (top == 0) {
        printf("Stack is empty\n");
    } else {
        printf("Top element is %d\n", top->data);
    }
}

// Function to pop an element from the stack
void pop() {
    struct node *temp;
    temp = top;
    if (top == 0) {
        printf("Stack is empty\n");
    } else {
        printf("The popped element is %d\n", top->data);
        top = top->next; // Move top to next node
        free(temp); // Free the memory of the popped node
    }
}

// Main function to run the stack operations
void main() {
    int ch, n;
    while (1) {
        printf("1 Push\n2 Pop\n3 Peek\n4 Display\n5 Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("\nEnter data to insert: ");
                scanf("%d", &n);
                push(n);
                break;
            case 2:
                pop();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice, please try again.\n");
                break;
        }
    }
}
