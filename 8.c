#include <stdio.h>
#include <stdlib.h>
typedef struct BST {
 int data;
 struct BST *lchild, *rchild;
} node;
node *get_node();
void insert(node *root, node *new_node);
void inorder(node *temp);
void preorder(node *temp);
void postorder(node *temp);
int main() {
 int choice;
 int ans = 1;
 node *new_node, *root = NULL;
 printf("\nProgram For Binary Search Tree");
 do {
 printf("\n\n1. Create");
 printf("\n2. Recursive Traversals");
 printf("\n3. Exit");
 printf("\nEnter your choice: ");
 scanf("%d", &choice);
 switch(choice) {
 case 1:
 do {
 new_node = get_node();
 printf("Enter the element: ");
 scanf("%d", &new_node->data);
 if (root == NULL) // Tree is not created yet
 root = new_node;
 else
 insert(root, new_node);
 printf("Want to enter more elements? (1/0): ");
 scanf("%d", &ans);
 } while(ans == 1);
 break;
 case 2:
 if (root == NULL)
 printf("Tree is not created yet.\n");
 else {
 printf("\nInorder traversal: ");
 inorder(root);
 printf("\nPreorder traversal: ");
 preorder(root);
 printf("\nPostorder traversal: ");
 postorder(root);
 printf("\n");
 }
 break;
 case 3:
 printf("Exiting program.\n");
 exit(0);
 default:
 printf("Invalid choice, please try again.\n");
 }
 } while (1);
 return 0;
}
node *get_node() {
 node *temp = (node *) malloc(sizeof(node));
 temp->lchild = NULL;
 temp->rchild = NULL;
 return temp;
}
void insert(node *root, node *new_node) {
 if (new_node->data < root->data) {
 if (root->lchild == NULL)
 root->lchild = new_node;
 else
 insert(root->lchild, new_node);
 }
 else if (new_node->data > root->data) {
 if (root->rchild == NULL)
 root->rchild = new_node;
 else
 insert(root->rchild, new_node);
 }
 // If equal, do nothing or handle duplicates as per your need
}
void inorder(node *temp) {
 if (temp != NULL) {
 inorder(temp->lchild);
 printf("%d ", temp->data);
 inorder(temp->rchild);
 }
}
void preorder(node *temp) {
 if (temp != NULL) {
 printf("%d ", temp->data);
 preorder(temp->lchild);
 preorder(temp->rchild);
 }
}
void postorder(node *temp) {
 if (temp != NULL) {
 postorder(temp->lchild);
 postorder(temp->rchild);
 printf("%d ", temp->data);
 }
}
