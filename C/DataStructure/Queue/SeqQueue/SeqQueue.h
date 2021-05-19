#include "../../global_var.h"

typedef struct _SQueue{
    int data[_MAXSIZE];
}SQueue;

//初始化顺序队列
bool SQueue_Init(SQueue*);

//顺序队列判空
bool SQueue_Empty(SQueue);

//顺序队列入队
void SQueue_EnQueue(SQueue*,int);

//顺序队列出队
bool SQueue_DeQueue(SQueue*,int*);

//顺序队列获取头部
int SQueue_GetHead(SQueue);