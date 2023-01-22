//perform binary tree traversal in c.

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *root = NULL;

void insert(int data)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    if (root == NULL)
    {
        root = temp;
    }
    else
    {
        struct node *current = root;
        struct node *parent = NULL;
        while (1)
        {
            parent = current;
            if (data < parent->data)
            {
                current = current->left;
                if (current == NULL)
                {
                    parent->left = temp;
                    return;
                }
            }
            else
            {
                current = current->right;
                if (current == NULL)
                {
                    parent->right = temp;
                    return;
                }
            }
        }
    }
}

void preorder(struct node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(struct node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right );
    }
}

void postorder(struct node *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

int main()
{
    int n, i, data;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("Enter the data: ");
        scanf("%d", &data);
        insert(data);
    }
    printf("Preorder traversal: ");
    preorder(root);
    printf(" \n");
    printf("Inorder traversal: ");
    inorder(root);
    printf(" \n");
    printf("Postorder traversal: ");
    postorder(root);
    printf(" \n");
    return 0;
}

// Output:

// Enter the number of nodes: 5
// Enter the data: 5s
// Enter the data: 3
// Enter the data: 7
// Enter the data: 2
// Enter the data: 4
// Preorder traversal: 5 3 2 4 7
// Inorder traversal: 2 3 4 5 7
// Postorder traversal: 2 4 3 7 5
