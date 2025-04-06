#include <stdio.h>
#include <malloc.h>

struct node
{
    int data;
    struct node *next;
};

struct node *p = NULL, *temp = NULL, *head[10];

void insert()
{
    int i, key;
    printf("Enter the key value to insert");
    scanf("%d", &key);
    i = key % 11;

    p = (struct node *)malloc(sizeof(struct node));
    p->data = key;
    p->data = NULL;

    if (head[i] == NULL)
    {
        head[i] = p;
    }
    else
    {
        temp = head[i];
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
    }
}

void search()
{
    int i, key;
    printf("\nEnter the key value to search");
    scanf("%d", &key);

    i = key % 11;
    if (head[i] == NULL)
        printf("\nElement not found");
    else
    {
        for (temp = head[i]; temp != NULL; temp = temp->next)
        {
            if (temp->data == key)
            {
                printf("\nElement is found");
                break;
            }
        }
        if (temp == NULL)
        {
            printf("\nElement not found");
        }
    }
}

void display()
{
    int i, j;
    for (i = 0; i < 10; i++)
    {
        printf("%d", i);
        if (head[i] == NULL)
        {
            printf("\tNULL");
        }
        else
        {
            temp = head[i];
            do
            {
                printf("%d", temp->data);
                temp = temp->next;
            } while (temp != NULL);
        }
    }
}

void main()
{
    void display();
    void insert();
    void search();

    int ch, q = 0;

    do
    {
        printf("\n1]Insert\n2]Display\n3]Search\n4]Exit");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            insert();
            break;
        case 2:
            display();
            break;
        case 3:
            search();
            break;
        case 4:
            (q = 1);
            break;
        }
    } while (q == 0);
}