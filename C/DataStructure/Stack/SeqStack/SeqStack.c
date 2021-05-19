#include "../../global_inc.h"
#include "SeqStack.h"

//顺序栈初始化
void SStack_Init(SStack s)
{
    s->top = -1;
}

//顺序栈判空
bool SStack_Empty(SStack s)
{
    return s->top<0;
}

//顺序栈压入
bool SStack_Push(SStack s,int e)
{
    if(s->top>=MAX_SIZE-1)return false;
    s->top++;
    s->data[s->top] = e;
    return true;
}

//顺序栈弹出
bool SStack_Pop(SStack s,int* e)
{
    if(SStack_Empty(s)){
        return false;
    }
    else{
        *e = s->data[s->top];
        s->top--;
    }
    return true;
}

//顺序栈获取栈顶元素
int SStack_GetTop(SStack s)
{
    return s->data[s->top];
}