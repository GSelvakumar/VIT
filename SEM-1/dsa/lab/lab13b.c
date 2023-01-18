#include <stdio.h>

#include <stdlib.h>

struct node {

int data;

struct node *left;

struct node *right;

};



struct node *createNode(int data) {

struct node *newNode = (struct node *)malloc(sizeof(struct node)); if (newNode != NULL) {

newNode->data = data;

newNode->left = NULL;

newNode->right = NULL;

}

return newNode;

}



void inOrder(struct node *root) {

if (root != NULL) {

inOrder(root->left);

printf("%d ", root->data);

inOrder(root->right);
 
}

}



void preOrder(struct node *root) {

if (root != NULL) {

printf("%d ", root->data);

preOrder(root->left);

preOrder(root->right);

}

}



void postOrder(struct node *root) {

if (root != NULL) {

postOrder(root->left);

postOrder(root->right);

printf("%d ", root->data);

}

}



int main() {

struct node *root = createNode(1);

root->left = createNode(2);

root->right = createNode(3);

root->left->left = createNode(4);

root->left->right = createNode(5);



printf("In-order traversal: ");

inOrder(root);

printf("\nPre-order traversal: ");

preOrder(root);

printf("\nPost-order traversal: ");
 

postOrder(root);

return 0;

}
