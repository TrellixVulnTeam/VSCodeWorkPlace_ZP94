#include "seqList.h"
#include <stdio.h>
#include <stdlib.h>

//初始化表
bool InitList(SList* l){
    l->length=0;
    l->maxSize = MAXSIZE;
    l->data = (int*) malloc(sizeof(int)*MAXSIZE);
    return true;
}

//求表长
int Length(SList l)
{
    return l.length;
}

//删除表元素，并返回给e
void ListDelete(SList* l,int i,int* e)
{
    *e = l->data[i];
    for(int idx = i;idx < l->length;idx++)
    {
        l->data[idx] = l->data[idx+1];
    }
    l->length--;
}

//打印表
void PrintList(SList l)
{
    printf("[ ");
    for(int i = 0;i<l.length;i++)
        printf("%d ",l.data[i]);
    printf("]\n");
}

//定位元素下标
int LocateElem(SList l,int e)
{
    int rt = -1;
    for(int i=0;i<l.length;i++)
        rt = l.data[i]==e?i:rt;
    return rt;
}

//判空
bool Empty(SList l)
{
    return l.length == 0 ;
}

//获取i下标元素
int GetElem(SList l,int i)
{
    return l.data[i];
}

//销毁表
void DestroyList(SList* l)
{
    free(l->data);
    l->length=0;
}

//表插入
void ListInsert(SList* l,int i,int e)
{
    if(i<0||i>l->maxSize)return;
    for(int idx =l->length;idx>=i;idx--)
        l->data[idx] = l->data[idx-1];
    l->data[i] = e;
    l->length++;
}