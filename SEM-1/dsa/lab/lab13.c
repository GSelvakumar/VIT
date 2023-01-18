#include <stdio.h>
#include <stdlib.h>
#define M 4 // max number of children per B+ tree node = M-1



typedef struct BPTreeNode {

int is_leaf;
int key_count;
int keys[M-1];
struct BPTreeNode* children[M];

} BPTreeNode;

//Creating a new node
BPTreeNode* create_node(int is_leaf) {
BPTreeNode* new_node = (BPTreeNode*) malloc(sizeof(BPTreeNode));
new_node->is_leaf = is_leaf;
new_node->key_count = 0;
return new_node;
}

//traverse the nodes
void traverse(BPTreeNode* root) {
int i;
for (i = 0; i < root->key_count; i++) {
if (!root->is_leaf)
traverse(root->children[i]);
printf(" %d", root->keys[i]);
}

if (!root->is_leaf)
traverse(root->children[i]);
}

//search in tree
BPTreeNode* search(BPTreeNode* root, int key) {
int i = 0;
while (i < root->key_count && key > root->keys[i])
i++;
if (i < root->key_count && key == root->keys[i])
return root;



if (root->is_leaf)
  return NULL;
return search(root->children[i], key);
}



BPTreeNode* split_child(BPTreeNode* parent, int index) { 
  BPTreeNode* child = parent->children[index]; 
  BPTreeNode* new_node = create_node(child->is_leaf); 
  new_node->key_count = M / 2 - 1;


int j;

for (j = 0; j < M / 2 - 1; j++) {
 
new_node->keys[j] = child->keys[j + M / 2];

}



if (!child->is_leaf) {

for (j = 0; j < M / 2; j++) {

new_node->children[j] = child->children[j + M / 2];

}

}



child->key_count = M / 2 - 1;



for (j = parent->key_count; j >= index + 1; j--) {

parent->children[j + 1] = parent->children[j];

}



parent->children[index + 1] = new_node;



for (j = parent->key_count - 1; j >= index; j--) {

parent->keys[j + 1] = parent->keys[j];

}



parent->keys[index] = child->keys[M / 2 - 1];

parent->key_count += 1;



return parent;

}



//Insert in tree

BPTreeNode* insert_non_full(BPTreeNode* node, int key) { int i = node->key_count - 1;
 
if (node->is_leaf) {

while (i >= 0 && node->keys[i] > key) {

node->keys[i + 1] = node->keys[i];

i--;

}



node->keys[i + 1] = key;

node->key_count = node->key_count + 1;

} else {

while (i >= 0 && node->keys[i] > key)

i--;



if (node->children[i + 1]->key_count == M - 1) {

node = split_child(node, i + 1);

if (node->keys[i + 1] < key)

i++;

}

node->children[i + 1] = insert_non_full(node->children[i + 1], key);

}



return node;

}



BPTreeNode* insert(BPTreeNode* root, int key) {

if (root->key_count == M - 1) {

BPTreeNode* new_root = create_node(0);

new_root->children[0] = root;

new_root = split_child(new_root, 0);

new_root = insert_non_full(new_root, key);

return new_root;

} else {
 
return insert_non_full(root, key);

}

}



int main()

{

BPTreeNode* root = create_node(1);

root = insert(root, 5);

root = insert(root, 10);

root = insert(root, 15);

root = insert(root, 20);

root = insert(root, 25);

root = insert(root, 30);


printf("B+ tree is :\n");

traverse(root);

return 0;

}
