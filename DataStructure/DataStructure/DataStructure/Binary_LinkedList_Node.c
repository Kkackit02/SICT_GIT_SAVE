// Tree traversal in C

#include <stdio.h>
#include <stdlib.h>

struct node {
	//int item;
	char item;
	struct node* left;
	struct node* right;
};

// Inorder traversal
void inorderTraversal(struct node* root) {
	if (root == NULL) return;
	inorderTraversal(root->left);
	printf("%c ->", root->item);
	inorderTraversal(root->right);
}

// Preorder traversal
void preorderTraversal(struct node* root) {
	if (root == NULL) return;
	printf("%c ->", root->item);
	preorderTraversal(root->left);
	preorderTraversal(root->right);
}

// Postorder traversal
void postorderTraversal(struct node* root) {
	if (root == NULL) return;
	postorderTraversal(root->left);
	postorderTraversal(root->right);
	printf("%c ->", root->item);
}

// Create a new Node
struct node* createNode(char value) {
	struct node* newNode = malloc(sizeof(struct node));
	newNode->item = value;
	newNode->left = NULL;
	newNode->right = NULL;

	return newNode;
}

// Insert on the left of the node
struct node* insertLeft(struct node* root, char value) {
	root->left = createNode(value);
	return root->left;
}

// Insert on the right of the node
struct node* insertRight(struct node* root, char value) {
	root->right = createNode(value);
	return root->right;
}

int main() {
	struct node* root = createNode('A');
	insertLeft(root, 'B');
	insertRight(root, 'C');

	insertLeft(root->left, 'D');
	insertRight(root->left, 'E');

	insertLeft(root->right, 'F');
	insertRight(root->right, 'G');

	insertLeft(root->left->left, 'H');
	insertRight(root->left->left, 'I');
	
	insertLeft(root->left->right, 'J');
	insertRight(root->left->right, 'K');

	insertLeft(root->right->left, 'J');

	printf("Inorder traversal \n");
	inorderTraversal(root);

	printf("\nPreorder traversal \n");
	preorderTraversal(root);

	printf("\nPostorder traversal \n");
	postorderTraversal(root);
}