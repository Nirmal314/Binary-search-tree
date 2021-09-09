#include <stdio.h>
#include <stdlib.h>

typedef struct TREE
{
    int data, key;
    struct TREE *left;
    struct TREE *right;
} node;

void line()
{
    for (int i = 0; i < 75; i++)
    {
        printf("-");
    }
    printf("\n");
}
node *create()
{
    node *tmp;
    line();
    printf("Enter the data : ");
    tmp = (node *)malloc(sizeof(node));
    scanf("%d", &tmp->data);
    tmp->left = tmp->right = NULL;
    return tmp;
}
void insert(node *root, node *tmp)
{
    if (tmp->data < root->data)
    {
        if (root->left != NULL)
        {
            insert(root->left, tmp);
        }
        else
        {
            root->left = tmp;
        }
    }
    if (tmp->data > root->data)
    {
        if (root->right != NULL)
        {
            insert(root->right, tmp);
        }
        else
        {
            root->right = tmp;
        }
    }
}

void postorder(node *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}
void preorder(node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
void inorder(node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void main()
{
    printf("\n");
    char ch, ch1;
    int s;
    node *root = NULL, *tmp;
    do
    {
        tmp = create();
        if (root == NULL)
        {
            root = tmp;
        }
        else
        {
            insert(root, tmp);
        }
        printf("\nPreorder : ");
        preorder(root);
        printf("\nPostorder : ");
        postorder(root);
        printf("\nInorder : ");
        inorder(root);
        printf("\n\n");
        printf("Want to enter more data? : ");
        getchar();
        scanf("%c", &ch);
    } while (ch == 'Y' || ch == 'y');
    line();
    printf("\n");
    printf("There you go...\nFinal result : \n");
    printf("\nPreorder : ");
    preorder(root);
    printf("\nPostorder : ");
    postorder(root);
    printf("\nInorder : ");
    inorder(root);
    printf("\n\n");
}
