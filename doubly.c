#include<stdio.h>
#include<malloc.h>
#include"doubly.h"

void main()
{
    struct node *create();
    struct node *deletee();
    int search();
    void display();

    struct node *head=NULL;
    head=(struct node*)malloc(sizeof(struct node));
    head->right=NULL;
    int c,key,q=0,ch;

    do
    {
        printf("\n1.Create\n2.insert\n3.search\n4.Display\n5.Exit");
        scanf("%d",&ch);

        switch (ch)
        {
        case 1:head=create(head);
            break;
        case 2:head=insert(head);
            break;
       case 3:
            printf("Enter the value to search");
            scanf("%d",&key);
            key=search(head,key);
            printf("The value is at:%d",key);
            break;
        case 4:display(head);
            break;
        case 5:q=1;
            break;
        }
    } while (q==0);
    
}