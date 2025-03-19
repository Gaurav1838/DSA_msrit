// Online C compiler to run C program online
#include <stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};
struct node *top=0;

void push(int x){
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data=x;
    newnode->next=top;
    top = newnode;
}

void display(){
    struct node *temp;
    temp=top;
    if(top==0){
        printf("stack is empty\n");
    }
    else{
        while(temp!=0){
            printf("%d\n",temp->data);
            temp=temp->next;
        }
    }
}

void peek(){
    if(top==0){
        printf("stack is empty\n");
    }
    else{
        printf("top element is %d\n",top->data);
    }
}

void pop(){
    struct node *temp;
    temp=top;
     if(top==0){
        printf("stack is empty\n");
    }
    else{
        printf("the popped element is %d\n",top->data);
        top=top->next;
        free(temp);
    }
}

void main(){
    int ch, n;
    while (1)
    {
    
    printf("1 Push\n2 Pop\n3 Peep\n4 Display\n5 Exit\n");
    printf("\nEnter your choice: ");
    scanf("%d",&ch);

    switch (ch)
    {
    case 1:
        printf("\nEnter data to insert: ");
        scanf("%d",&n);
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
        break;
    }
}
}
