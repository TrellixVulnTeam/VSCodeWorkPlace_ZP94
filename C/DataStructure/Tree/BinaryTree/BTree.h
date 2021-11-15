#include "../../global_var.h"

typedef struct _BTNode
{
    int data;
    _BTNode* LChild,* RChild;
}_BTNode,*BTree;

//判空
bool BTree_Empty();

//前序遍历
void BTree_PreOrder();

//中序遍历
void BTree_InOrder();

//后序遍历
void BTree_PostOrder();

//层次遍历
void BTree_LvlOrder();

//线索化二叉树
void BTree_Cueing();

//二叉排序树
void BTree_Rank();

//是否是满二叉树
bool BTree_IsFull();

//是否是完全二叉树
bool BTree_IsComplete();

//转为平衡二叉树
bool BTree_Balanced();