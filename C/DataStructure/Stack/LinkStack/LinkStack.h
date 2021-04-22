#ifndef LINKSTACK_H
#define LINKSTACK_H

#include "../../global_var.h"
#include <stdlib.h>

typedef struct _LSTACK{
    int data;
    struct _LSTACK* next;
}LStackNode,*LStack;

//链栈初始化
LStack LStack_Init();

//链栈判空
bool LStack_Empty(LStack);

//链栈压入
bool LStack_Push(LStack,int);

//链栈弹出
bool LStack_Pop(LStack,int*);

//链栈获取栈顶元素
LStackNode* LStack_GetTop(LStack);

#endif