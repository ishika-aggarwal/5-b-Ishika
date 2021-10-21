#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

struct node {
    int key;
    struct node* left;
    struct node* right;
};

struct node* newnode(int data)
{
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    
    temp->key = data;
    
    temp->left = NULL;
    temp->right = NULL;
    return(temp);
}
void printCurrentLevel(struct node* root, int level);
int height(struct node* node);
struct node* newnode(int data);

void printCurrentLevel(struct node* root, int level)
{
    if (root == NULL)
        return;
    if (level == 1)
        printf("%d ", root->key);
    else if (level > 1) {
        printCurrentLevel(root->left, level - 1);
        printCurrentLevel(root->right, level - 1);
    }
}
int height(struct node* node)
{
    if (node == NULL)
        return 0;
    else {
       
        int lheight = height(node->left);
        int rheight = height(node->right);
 
        
        if (lheight > rheight)
            return (lheight + 1);
        else
            return (rheight + 1);
    }
}


void printLevelOrder(struct node* root)
{
    int h = height(root);
    int i;
    for (i = 1; i <= h; i++)
        printCurrentLevel(root, i);
}
struct node* insert(struct node* node, int key)
{
    if(node == NULL)
        return newnode(key);
        
    if(key % 4 == 0)
        node->left = insert(node->left, key);
    else
        node->right = insert(node->right, key);
    
    return node;
}

int main() {
int t;
scanf("%d ", &t);
    while(t--)
    {
        int n;
        scanf("%d ", &n);
        int A[50];
        for(int i=0; i<n; i++) {
            scanf("%d ", &A[i]);
        }
    struct node* root = NULL;
    for(int i=0; i<n; i++) {
        root = insert(root, A[i]);
    }
    printLevelOrder(root);
    printf("\n");
   }
    
    return 0;
}
