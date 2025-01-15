#include<stdio.h>
#include<stdlib.h>
int top=-1,n;

void push(int a[],int e)
{
    if(top==n-1)
    {
        printf("stack is ful \n");
    }
    else
    {
        top++;
        a[top]=e;
        printf("*************************\n");
        printf("\n Element %d is pushed \n",e);
        printf("*************************\n");
    }
}

void pop(int a[])
{
    if(top == -1)
    {
        printf("************************\n");
        printf("stack is underflow \n");
        printf("************************\n");
    }
    else
    {
        printf("*************************\n");
        printf("\n Element %d is popped \n",a[top--]);
        printf("*************************\n");
    }
}

void peak(int a[])
{
    if(top == -1)
    {
        printf("*************************\n");
        printf("stack is underflow\n");
        printf("*************************\n");
    }
    else
    {
        printf("*************************\n");
        printf("\n The top most element %d is popped \n",a[top]);
        printf("*************************\n");
    }
}

void display(int a[])
{
    if (top == -1)
    {
        printf("stack is empty\n");
    }
    else
    {
        printf("elements of stack are \n");
        printf("******************\n");
        for(int i=top;i>-1;i--)
        {
            printf("%d\n",a[i]);
        }
    }
}

void main()
{
    printf("Enter the size of the array \n");
    scanf("%d",&n);
    int a[n],e;
    int ch;

    while(1)
    {
        printf("\n\n1-> insert element \t2->delete element\n3->peak\t\t4->Display\n5->exit\n");
        printf("Enter choice:\n ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: printf("Enter the element to be pushed\n");
            scanf("%d",&e);
            push(a,e);
            break;
            case 2: pop(a);
            break;
            case 3: peak(a);
            break;
            case 4: display(a);
            break;
            default: printf("enter the choice");
            case 5:
            exit(0);
        }
    }
}
