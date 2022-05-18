#include<stdio.h>

#define MAX_SIZE 13

int cnt = 0;
struct Tree_Node
{
	//int key;
	char key;
};


//void Add_Tree(Struct Tree* Target_Tree, int Item)
void Add_Tree(struct Tree_Node * Target_Tree, char item)
{
	if (cnt == MAX_SIZE)
	{
		printf("Tree is Full\n");
		return;
	}
	cnt++;
	Target_Tree[cnt].key = item;
}

int main(void)
{
	struct Tree_Node binaryTree[MAX_SIZE];
	/*
	Add_Tree(binaryTree, 'A');
	Add_Tree(binaryTree, 'B');
	Add_Tree(binaryTree, 'C');
	Add_Tree(binaryTree, 'D');
	Add_Tree(binaryTree, 'E');
	Add_Tree(binaryTree, 'F');
	Add_Tree(binaryTree, 'G');
	Add_Tree(binaryTree, 'H');
	Add_Tree(binaryTree, 'I');
	Add_Tree(binaryTree, 'J');
	Add_Tree(binaryTree, 'K');
	Add_Tree(binaryTree, 'L');
	*/
	
	Add_Tree(binaryTree, 'A');
	Add_Tree(binaryTree, 'B');
	Add_Tree(binaryTree, ' '); 
	Add_Tree(binaryTree, 'C');
	Add_Tree(binaryTree, ' ');
	Add_Tree(binaryTree, ' ');
	Add_Tree(binaryTree, ' ');
	Add_Tree(binaryTree, 'D');
	
	for (int i = 1; i < cnt; i++)
	{
		printf("%c[%d]--> ", binaryTree[i].key, i);
	}

	printf("\n");

	int num;
	printf("node num: ");
	scanf("%d", &num);

	
	printf("%c | left child : %c right child: %c \n", 
		binaryTree[num], binaryTree[num*2], binaryTree[num* 2 + 1]);

	printf("%c parent node : %c \n", binaryTree[num], binaryTree[num / 2]);
	printf("%c root node : %c \n", binaryTree[num], binaryTree[1]);
	return 0;
}