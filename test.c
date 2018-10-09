#define _CRT_SECURE_NO_WARNINGS 1

#include "BSTree.h"

int main()
{
	BSTreeNode* pRoot = NULL;
	BSTreeDataPush(&pRoot, 5);
	BSTreeDataPush(&pRoot, 3);
	BSTreeDataPush(&pRoot, 7);
	BSTreeDataPush(&pRoot, 1);
	BSTreeDataPush(&pRoot, 4);
	BSTreeDataPush(&pRoot, 6);
	BSTreeDataPush(&pRoot, 8);

	//BSTreeDataPop(&pRoot, 3);
	BSTreeDataPop(&pRoot, 9);

	system("pause");
	return 0;
}

