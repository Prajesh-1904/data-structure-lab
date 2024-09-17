#include <stdio.h>
#include <stdlib.h>
struct Node 
{
    int score;
    struct Node* left;
    struct Node* right;
};
struct Node* createNode(int score) 
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->score = score;
    newNode->left = newNode->right = NULL;
    return newNode;
}
struct Node* insert(struct Node* root, int score) 
{
    if (root == NULL) 
    {
        return createNode(score);
    }
    if (score < root->score) 
    {
        root->left = insert(root->left, score);
    } 
    else if (score > root->score) 
    {
        root->right = insert(root->right, score);
    }
    return root;
}
void inOrder(struct Node* root) 
{
    if (root != NULL) 
    {
        inOrder(root->left);
        printf("%d ", root->score);
        inOrder(root->right);
    }
}
void findTopScores(struct Node* root, int *count) 
{
    if (root != NULL && *count > 0) 
    {
        findTopScores(root->right, count);
        if (*count > 0) 
        {
            printf("%d ", root->score);
            (*count)--;
        }
        findTopScores(root->left, count);
    }
}
struct Node* deleteNode(struct Node* root, int key) 
{
    if (root == NULL) 
        return root;    
    if (key < root->score)
        root->left = deleteNode(root->left, key);
    else if (key > root->score)
        root->right = deleteNode(root->right, key);
    else 
    {
        if (root->left == NULL) 
        {
            struct Node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) 
        {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }
        struct Node* temp = root->right;
        while (temp && temp->left != NULL) 
        {
            temp = temp->left;
        }
        root->score = temp->score;
        root->right = deleteNode(root->right, temp->score);
    }
    return root;
}
int main() 
{
    struct Node* root = NULL;
    clrscr();
    root = insert(root, 85);
    root = insert(root, 98);
    root = insert(root, 75);
    root = insert(root, 60);
    root = insert(root, 45);
    int topCount = 100;
    printf("Top scores: ");
    findTopScores(root, &topCount);
    printf("\n");
    root = insert(root, 90);
    root = deleteNode(root, 45);    
    printf("Updated scores: ");
    inOrder(root);
    printf("\n");
    getch();
    return 0;
}