#include "LinkStack.h"

//链栈初始化
LStack LStack_Init()
{
    LStack r = (LStack)malloc(sizeof(LStack));
    r->data = NULL;
    r->next = NULL;
    return r;
}

//链栈判空
bool LStack_Empty(LStack stack)
{
    return stack->next==NULL; 
}

//链栈压入
bool LStack_Push(LStack stack,int e)
{
    LStackNode* node = LStack_GetTop(stack);
    if(node == NULL)return false;
    LStackNode* newNode = (LStackNode*)malloc(sizeof(LStackNode));
    if(newNode == NULL)return false;
    newNode->data = e;
    newNode->next = NULL;
    node->next = newNode;
    return true;
}

//链栈弹出
bool LStack_Pop(LStack stack,int* e)
{
    LStackNode* tail,*tail_p;
    tail = stack;
    while(tail->next!=NULL)
    {
        tail_p = tail;
        tail = tail->next;
    }
    if(tail == NULL)return false;
    *e = tail->data;
    tail->data = NULL;
    if(tail==stack)return false;
    free(tail);
    tail_p->next = NULL;
    return true;
}

//链栈获取栈顶元素
LStackNode* LStack_GetTop(LStack stack)
{
    LStackNode* node = stack;
    while(node->next!=NULL)
    {
        node = node->next;
    }
    return node;
}
