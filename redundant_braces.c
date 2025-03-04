// Check for redundant braces- Given a mathematical expression, determine if it contains redundant braces.

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX 100

// Stack to simulate stack behavior using array
char stack[MAX];
int top = -1;

// Function to push an element onto the stack
void push(char ch) {
    if (top < MAX - 1) {
        top = top + 1;  
        stack[top] = ch; 
    }
}

// Function to pop an element from the stack
char pop() {
    if (top != -1) {
         return stack[top--];
    }
    return -1;  // Return -1 if stack is empty
}

// Function to check if the expression contains redundant braces
bool hasRedundantBraces(const char *expr) {
    // Traverse the expression character by character
    for (int i = 0; i < strlen(expr); i++) {
        char ch = expr[i];
        
        // If we encounter an opening parenthesis, push it onto the stack
        if (ch == '(' || ch == '+' || ch == '-' || ch == '*' || ch == '/' || (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) {
            push(ch);
        }

        // If we encounter a closing parenthesis
        else if (ch == ')') {
            // Check if there are operators between the parentheses
            bool hasOperator = false;
            while (top != -1 && stack[top] != '(') {
                char topChar = pop();
                if (topChar == '+' || topChar == '-' || topChar == '*' || topChar == '/') {
                    hasOperator = true;
                }
            }

            // If no operator was found between the parentheses, it's redundant
            if (!hasOperator) {
                return true;
            }

            // Pop the '(' from the stack
            pop();
        }
    }

    // If no redundant braces were found, return false
    return false;
}

int main() {
    char expr[MAX];
    
    printf("Enter the mathematical expression: ");
    fgets(expr, MAX, stdin);

    // Remove the trailing newline character, if present
    expr[strcspn(expr, "\n")] = '\0';

    if (hasRedundantBraces(expr)) {
        printf("The expression contains redundant braces.\n");
    } else {
        printf("The expression does not contain redundant braces.\n");
    }

    return 0;
}
