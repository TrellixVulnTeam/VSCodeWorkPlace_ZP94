#include "../../global_inc.h"
#include "LinkQueue.h"

//初始化链式队列
LQueue LQueue_Init()
{
    LQueue tmp = (LQueue)malloc(sizeof(LQueue));
    LQueueNode* tmpNode = (LQueueNode*)malloc(sizeof(LQueueNode*));
    tmpNode->data = 0;
    tmpNode->next = NULL;
    tmp->front = tmpNode;
    tmp->tail = tmpNode;
    return tmp;
}

//链式队列判空
bool LQueue_Empty(LQueue q)
{
    return q->front==q->tail;
}

//链式队列入队
void LQueue_EnQueue(LQueue q,int e)
{
    LQueueNode* tmp = (LQueueNode*)malloc(sizeof(LQueue));
    tmp->data = e;
    tmp->next = NULL;
    q->tail->next = tmp;
    q->tail = tmp;
}

//链式队列出队
bool LQueue_DeQueue(LQueue q,int* e)
{
    if(LQueue_Empty(q))return false;
    LQueueNode* qn = q->front->next;
    *e = qn->data;
    q->front->next = qn->next;
    if(qn==q->tail)
        q->tail = q->front;
    qn->next = NULL;
    free(qn);
    return true;
}

//链式队列获取头部
int LQueue_GetHead(LQueue q)
{
    return q->front->next->data;
}