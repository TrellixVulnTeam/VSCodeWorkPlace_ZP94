#include "../../global_inc.h"
#include "SeqQueue.h"

//初始化顺序队列
bool SQueue_Init(SQueue* q)
{
    q->data[0] = 0;
    return true;
}

//顺序队列判空
bool SQueue_Empty(SQueue q)
{
    return !q.data[0];
}

//顺序队列入队
void SQueue_EnQueue(SQueue* q,int e)
{
    if(q->data[0]+1>=_MAXSIZE)return;
    q->data[++q->data[0]] = e;
}

//顺序队列出队
bool SQueue_DeQueue(SQueue* q,int* e)
{
    if(q->data[0]<=0)return false;
    *e = q->data[1];
    for(int i=1;i<q->data[0];i++)
    {
        q->data[i] = q->data[i+1];
    }
    q->data[0]--;
    return false;
}

//顺序队列获取头部
int SQueue_GetHead(SQueue q)
{
    return q.data[1];
}