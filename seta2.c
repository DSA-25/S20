#include<stdio.h>
#include<malloc.h>
#include"seta1.h"


void main()
{
    struct node *root=NULL;

    struct node * create();
    void inorder();
    void postorder();
    int totalnodes();
    int totalleafnode();
    int nonleafnode();

    int n,ch,q=0;
    do
    {
        printf("\n1.Create\n2.count\n3.countleaf\n4.count Nonleaf\n5.Inorder\n6.Postorder\n7.Exit");
        printf("\nEnter your choice");
        scanf("%d",&ch);

        switch (ch)
        {
        case 1:root=create(root);
            break;
        case 2:printf("totalnodes in tree are:%d",totalnodes(root));
            break;
        case 3:printf("no of leafnodes in tree are:%d",totalleafnode(root));
            break;
        case 4:printf("no of nonleafnodes in tree are:%d",nonleafnode(root));
            break;
        case 5:inorder(root);
            break;
        case 6:postorder(root);
            break;
        case 7:q=1;
            break;
        }
    } while (q==0);
}



int totalnodes(struct node *root)
{
    struct node *ptr=NULL;
    static int c=0;
    ptr=root;
    if (ptr==NULL)
    {
        return 0;
    }
    else
    {
        totalnodes(ptr->left);
        c++;
        totalnodes(ptr->right);
    }return c;
}

int totalleafnode(struct node *root)
{
    static int l;
    if (root!=NULL)
    {
        totalleafnode(root->left);
    if (root->left==NULL&&root->right==NULL)
        l++;
        totalleafnode(root->right);
    }
    return l;
    
}

int nonleafnode(struct node *root)
{
    static int l=0;

    if (root==NULL||root->left==NULL&&root->right==NULL)
    {
        return 0;
    }
    else
    l++;
    nonleafnode(root->left);
    nonleafnode(root->right);
    return l;
}
