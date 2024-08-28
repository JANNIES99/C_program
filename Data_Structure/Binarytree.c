#include <stdio.h>
typedef struct nod
{
    struct nod *left;
    struct nod *right;
    int data;
} node;

node *root = NULL;
int display(node *current, int level)
{
    int i;
    int r;
    if (current != NULL)
    {
        display(current->right, level + 1);
        printf("\n");
        for (i = 0; i < level; i++)
        {
            printf("   ");
        }
        printf("%d", current->data);
        display(current->left, level + 1);
    }
}

void inorder(node *current)
{
    if (current != NULL)
    {
        inorder(current->left);
        printf("%d ", current->data);
        inorder(current->right);
    }
}

void preorder(node *current)
{
    if (current != NULL)
    {
        printf("%d ", current->data);
        preorder(current->left);
        preorder(current->right);
    }
}

void postorder(node *current)
{
    if (current != NULL)
    {
        postorder(current->left);
        postorder(current->right);
        printf("%d ", current->data);
    }
}

void insertion()
{
    node *New;
    int item, ch;
    New = (node *)malloc(sizeof(node));
    printf("Enter a number:");
    scanf("%d", &item);
    New->data = item;
    New->right = NULL;
    New->left = NULL;
    if (root == NULL)
    {
        root = New;
    }
    else
    {
        node *current;
        node *parent;
        current = root;
        while (current != NULL)
        {
            parent = current;
            if (current->data > item)
            {
                current = current->left;
            }
            else if (current->data < item)
            {
                current = current->right;
            }
            else
            {
                printf("Duplicate Node\n");
                break;
            }
        }
        if (current == NULL)
        {
            if (parent->data < item)
            {
                parent->right = New;
            }
            else
            {
                parent->left = New;
            }
        }
    }
}

void Delete(node *current)
{
    if (current != NULL)
    {
        Delete(current->right);
        Delete(current->left);
        current->left = NULL;
        current->right = NULL;
            free(current);
    }
}

void deletion()
{
    int ch, fl = 0;
    if (root == NULL)
    {
        printf("Tree is empty");
    }
    else
    {
        printf("Enter the number whose subtree to be deleted:");
        scanf("%d", &ch);
        node *current;
        node *parent;
        current = root;
        while (current != NULL)
        {
            if (ch > (current->data))
            {
                current = current->right;
            }
            else if (ch < (current->data))
            {
                current = current->left;
            }
            else
            {
                Delete(current);
                fl = 1;
                break;
            }
            parent = current;
        }
        if (fl == 1)
        {
            if(parent)
            printf("key is found and sub-tree is deleted");
        }
        else
        {
            printf("key not found");
        }
    }
}

int main()
{
    int ch;
    while (1)
    {
        printf("\nMenu\n1.Insertion\n2.Deletion\n3.Traverse\n4.Display\n5.Exit\n");
        printf("Enter a choice:");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            insertion();
            break;
        case 2:
            deletion();
            break;
        case 3:
            printf("Preorder:");
            preorder(root);
            printf("\n");
            printf("Inorder:");
            inorder(root);
            printf("\n");
            printf("Postorder:");
            postorder(root);
            printf("\n");
            break;
        case 4:
            display(root, 0);
            break;
        case 5:
            exit(0);
        default:
            printf("Wrong option");
        }
    }
}
