struct node {

    int data;
    struct node *left,*right;
};

struct node *create(struct node *root)
{
    struct node *p=NULL,*temp=NULL;
    int i,n;
    printf("\nHow many values");
    scanf("%d",&n);
    printf("\nEnter actual values");
    for ( i = 0; i < n; i++)
    {
        p=(struct node *)malloc(sizeof(struct node));
        scanf("%d",&p->data);
        p->left=p->right=NULL;

        if (root==NULL)
        {
            root=p;
        }
        else
        {
            temp=root;
        }
        while (temp!=NULL)
        {
            if(p->data<temp->data)
            {
                if (temp->left==NULL)
                {
                    temp->left=p;
                    break;
                }
                else
                temp=temp->left;
            }
            else if (p->data > temp->data)
            {
                if (temp->right==NULL)
                {
                    temp->right=p;
                    break;
                }
                else
                temp=temp->right;                
            }   
        }
    }return root; 
} 
struct node *insert(struct node *root)
{
    struct node *p=NULL,*temp=NULL;
    int i,n;

    printf("\nEnter value");
        p=(struct node *)malloc(sizeof(struct node));
        scanf("%d",&p->data);
        p->left=p->right=NULL;

        if (root==NULL)
        {
            root=p;
        }
        else
        {
            temp=root;
        }
        while (temp!=NULL)
        {
            if(p->data<temp->data)
            {
                if (temp->left==NULL)
                {
                    temp->left=p;
                    break;
                }
                else
                temp=temp->left;
            }
            else if (p->data > temp->data)
            {
                if (temp->right==NULL)
                {
                    temp->right=p;
                    break;
                }
                else
                temp=temp->right;                
            }   
        }return root;
    } 
 

void inorder(struct node *root)
{
    struct node *ptr=NULL;
    ptr=root;
    if(ptr!=NULL)
    {
        inorder(ptr->left);
        printf("%d\t",ptr->data);
        inorder(ptr->right);
    }
}
void preorder(struct node *root)
{
    struct node *ptr=NULL;
    ptr=root;
    if(ptr!=NULL)
    {
        printf("%d\t",ptr->data);
        preorder(ptr->left);
        preorder(ptr->right);
    }
}
void postorder(struct node *root)
{
    struct node *ptr=NULL;
    ptr=root;
    if(ptr!=NULL)
    {
        postorder(ptr->left);
        postorder(ptr->right);
        printf("%d\t",ptr->data);
    }
}

int search(struct node* root,int n)
{
    struct node *ptr=NULL;
    ptr=root;

    if (ptr!=NULL)
    {
        if (n==ptr->data)
        {
             return 1;
        }
        else if(n<ptr->data)
        {
           search(ptr->left,n);
        }
        else if (n>ptr->data)
        {
            search(ptr->right,n);
        }
        else
        {
            return 0;
        }
        
    }
    
}
