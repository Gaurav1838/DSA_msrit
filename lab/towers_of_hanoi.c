#include<stdio.h>
void tower(int n, char a, char c, char b)
{
    if(n==1)
    {
        printf("\n Move disk, from rod %c to rod %c",a,c);
        return;
    }
    else
    {
        tower(n-1,a,b,c);
        printf("\n move disk %d from %c",n,a,c);
        tower(n-1,b,c,a);
    }
}

int main()
{
    int n;
    printf("enter number of disks: ");
    scanf("%d",&n);
    tower(n,'a','c','b');
    return 0;
}