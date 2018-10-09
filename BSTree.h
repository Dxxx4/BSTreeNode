#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <Windows.h>
#include <assert.h>

typedef int DataType;

typedef struct BSTreeNode{
	DataType data;
	struct BSTreeNode* left;
	struct BSTreeNode* right;
}	BSTreeNode;

//查找
int BSTreeSearch(BSTreeNode* pRoot, DataType data)
{
	BSTreeNode* pNode = pRoot;
	if(pRoot == NULL)
	{
		return -1;
	}
	while(pNode != NULL)
	{
		if(pNode->data == data)
		{
			return 0;
		}
		else if(pNode->data < data)
		{
			pNode = pNode->right;
		}
		else if(pNode->data > data)
		{
			pNode = pNode->left;
		}
	}
	return -1;
}

//插入
void BSTreeDataPush(BSTreeNode** pRoot, DataType data)
{
	BSTreeNode* pNode = *pRoot;
	BSTreeNode* pNew = (BSTreeNode*)malloc(sizeof(BSTreeNode));
	BSTreeNode* pParent;
	int flag = BSTreeSearch(*pRoot, data);
	pNew->data = data;
	pNew->left = NULL;
	pNew->right = NULL;
	if(flag == 0)
	{
		printf("该数已在树中\n");
		return;
	}
	else
	{
		if(*pRoot == NULL)
		{
			*pRoot = pNew;
		}
		else
		{
			while(pNode != NULL)
			{
				pParent = pNode;
				if(data < pNode->data)
				{
					pNode = pNode->left;
				}
				else if(data > pNode->data)
				{
					pNode = pNode->right;
				}
				else if(data == pNode->data)
				{
					printf("该数据已在树中\n");
					return;
				}
			}
			if(data < pParent->data)
			{
				pParent->left = pNew;
			}
			else
			{
				pParent->right = pNew;
			}
		}
	}
}

//删除
void BSTreeDataPop(BSTreeNode** pRoot, DataType data)
{
	BSTreeNode* pDel = *pRoot;
	BSTreeNode* pParent = NULL;
	BSTreeNode* pMin;
	BSTreeNode* pMParent;
	if(pRoot == NULL)
	{
		printf("该数不在树中\n");
		return;
	}
	while(pDel != NULL && pDel->data != data)
	{
		pParent = pDel;
		if(pDel->data < data)
		{
			pDel = pDel->right;
		}
		else if(pDel->data > data)
		{
			pDel = pDel->left;
		}
	}
	
	if(pDel != NULL)
	{
		if(pDel->left == NULL && pDel->right != NULL)
		{
			if(pParent == NULL)
			{
				*pRoot = pDel->right;
			}
			else if(pDel == pParent->left)
			{
				pParent->left = pDel->right;
			}
			else if(pDel == pParent->right)
			{
				pParent->right = pDel->right;
			}
			free(pDel);
			return;
		}
		else if(pDel->right == NULL && pDel->left != NULL)
		{
			if(pParent == NULL)
			{
				*pRoot = pDel->left;
			}
			else if(pDel == pParent->left)
			{
				pParent->left = pDel->left;
			}
			else if(pDel == pParent->right)
			{
				pParent->right = pDel->left;
			}
			free(pDel);
			return;
		}
		else
		{
			pMParent = pDel;
			pMin = pDel->right;
			while(pMin->left != NULL)
			{
				pMParent = pMin;
				pMin = pMin->left;
			}
			pDel->data = pMin->data;

			if(pMParent == pDel)
			{
				pMParent->right = pMin->right;
			}
			else
			{
				pMParent->left = pMin->right;
			}
			free(pMin);
			return;
		}
	}
	else if(pDel == NULL)
	{
		printf("该数不在树中\n");
	}
	
}








