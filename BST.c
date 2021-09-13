#include <stdio.h>
#include <stdlib.h>
#include "line.h"

static int n = 0;
static int height = 0;

struct node
{
    int data;
    struct node *left, *right;
};
struct node *createNode(int key)
{
    struct node *tmp;
    tmp = (struct node *)malloc(sizeof(struct node));
    tmp->data = key;
    tmp->right = tmp->left = NULL;
    n++;
    return tmp;
}
struct node *insertNode(struct node *root, int key)
{
    if (root == NULL)
        return createNode(key);

    if (key < root->data)
    {
        root->left = insertNode(root->left, key);
    }

    else if (key > root->data)
    {
        root->right = insertNode(root->right, key);
    }

    return root;
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
void postorder(struct node *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}
void inorder(struct node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}
int minValue_print(struct node *root)
{
    while (root && root->left != NULL)
    {
        root = root->left;
    }
    return root->data;
}
int maxValue_print(struct node *root)
{
    while (root && root->right != NULL)
    {
        root = root->right;
    }
    return root->data;
}
struct node *minValue(struct node *root)
{
    while (root && root->left != NULL)
    {
        root = root->left;
    }
    return root;
}
struct node *deleteNode(struct node *root, int key)
{
    if (root == NULL)
        return root;

    if (key < root->data)
        root->left = deleteNode(root->left, key);

    else if (key > root->data)
        root->right = deleteNode(root->right, key);

    else
    {
        if (root->left == NULL)
        {
            struct node *tmp = root->right;
            free(root);
            return tmp;
        }

        else if (root->right == NULL)
        {
            struct node *tmp = root->left;
            free(root);
            return tmp;
        }

        struct node *tmp = minValue(root->right);
        root->data = tmp->data;
        root->right = deleteNode(root->right, tmp->data);
    }

    return root;
}
int searchNode(struct node *root, int key)
{
    if (root == NULL)
        return 0;

    if (root->data == key)
        return 1;

    else
    {
        if (key < root->data)
        {
            height++;
            searchNode(root->left, key);
        }

        else if (key > root->data)
        {
            height++;
            searchNode(root->right, key);
        }
    }
}
int BSTheight(struct node *root)
{
    int left, right = 0;
    if (root == NULL)
        return 0;
    else
    {
        left = BSTheight(root->left);
        right = BSTheight(root->right);

        if (left > right)
            return left + 1;
        else
            return right + 1;
    }
}
void main()
{
    int flag, data, s, del, search;
    char ch;
    struct node *root = NULL;
    line();
    while (1)
    {
        printf("\n1.Insert\n2.Delete\n3.Find minimum value\n4.Find maximum value\n5.Search\n6.Exit\n\n");
        printf("Which operation you want to perform? : ");
        scanf("%d", &s);
        switch (s)
        {
        case 1:
            do
            {
                line();
                printf("\nEnter data : ");
                scanf("%d", &data);
                line();
                root = insertNode(root, data);
                printf("\nPreOrder : ");
                preorder(root);
                printf("\nPostOrder : ");
                postorder(root);
                printf("\nInOrder : ");
                inorder(root);
                printf("\n\nNumber of nodes = %d", n);
                int height1 = BSTheight(root);
                printf("\nHeight of BST = %d", height1 - 1);
                printf("\n");
                line();
                printf("\nWant to insert more data? : ");
                getchar();
                scanf("%c", &ch);
            } while (ch == 'y' || ch == 'Y');
            break;

        case 2:
            do
            {
                line();
                printf("\nEnter the data you want to delete : ");
                scanf("%d", &del);
                line();
                int f = searchNode(root, del);
                if (f == 1)
                {
                    deleteNode(root, del);
                    n--;
                }
                else
                {
                    line();
                    printf("\nValue not found in this BST which you wanted to delete.\n");
                    line();
                    printf("\n");
                }
                printf("\nPreOrder : ");
                preorder(root);
                printf("\nPostOrder : ");
                postorder(root);
                printf("\nInOrder : ");
                inorder(root);
                printf("\n\nNumber of nodes = %d", n);
                int height1 = BSTheight(root);
                printf("\n\nHeight of BST = %d", height1 - 1);
                printf("\n");
                line();
                printf("\nWant to delete more data? : ");
                getchar();
                scanf("%c", &ch);
            } while (ch == 'y' || ch == 'Y');
            break;
        case 3:
            line();
            printf("\nMinimum value in this BST = %d\n", minValue_print(root));
            break;
        case 4:
            line();
            printf("\nMaximum value in this BST = %d\n", maxValue_print(root));
            break;
        case 5:
            do
            {
                line();
                printf("\nSearch for the data : ");
                scanf("%d", &search);
                flag = searchNode(root, search);
                if (flag == 1)
                {
                    line();
                    printf("\n");
                    printf("Value found at height %d", height);
                }
                else
                {
                    line();
                    printf("\n");
                    printf("Value not found");
                }
                printf("\n");
                line();
                printf("\nWant to search again? : ");
                getchar();
                scanf("%c", &ch);
            } while (ch == 'y' || ch == 'Y');
            break;
        case 6:
            line();
            printf("\nAlright there is your final result...\n\n");
            printf("\nPreOrder : ");
            preorder(root);
            printf("\nPostOrder : ");
            postorder(root);
            printf("\nInOrder : ");
            inorder(root);
            printf("\n\nNumber of nodes = %d", n);
            int height1 = BSTheight(root);
            printf("\n\nHeight of BST = %d", height1 - 1);
            printf("\n\n");
            printf("Thanks for using! Have a great day :)");
            printf("\n");
            line();
            exit(0);
            break;
        default:
            line();
            printf("\nInavlid entry!");
            printf("\n");
            break;
        }
        line();
    }
}
