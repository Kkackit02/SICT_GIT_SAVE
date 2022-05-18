#include<stdio.h>
#define MAX_SIZE 256

int cnt = 0;
struct Tree_Node
{
	int key;
};

//void Add_Tree(Struct Tree* Target_Tree, int Item)
void Add_Tree(struct Tree_Node* Target_Tree, int item)
{
	if (cnt == MAX_SIZE)
	{
		printf("Tree is Full\n");
		return;
	}
	cnt++;
	Target_Tree[cnt].key = item;
}

void UpdateNode_Tree(struct Tree_Node* Target_Tree, int nodeIndex , int value) // 노드 데이터 변경 함수
{
	Target_Tree[nodeIndex].key = value; // 값 변경
}

int main(void)
{
	struct Tree_Node binaryTree[MAX_SIZE+1];

	
	const int dataArray[] = { 55, 15, 60, 8, 28, 90, 3, 30, 48, 38, 50, 33, 32, 36 };
	const int dataIndexArray[] = {1, 2, 3, 4, 5, 7, 8, 11, 23, 46, 47, 92, 184, 185};
	const int dataSize = sizeof(dataArray ) / sizeof(dataArray[0]);
	

	for (int i = 0; i < MAX_SIZE; i++)
	{
		Add_Tree(binaryTree, 0);
	}
	
	for (int i = 0; i < dataSize; i++)
	{
		UpdateNode_Tree(binaryTree, dataIndexArray[i], dataArray[i]);
	}

	printf("%d | left child : %d right child: %d \n", binaryTree[23].key, binaryTree[23*2].key, binaryTree[23*2+1].key);
	printf("%d | left child : %d right child: %d \n", binaryTree[11].key, binaryTree[11 * 2].key, binaryTree[11 * 2 + 1].key);

	printf("root node : %d \n", binaryTree[1].key);
	return 0;
}