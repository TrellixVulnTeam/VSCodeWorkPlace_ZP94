#ifndef SEQLIST_H
#define SEQLIST_H

#include "../../global_var.h"
#define MAXSIZE 100

typedef struct{
    int* data;
    int maxSize,length;
}SList;

//初始化表
bool InitList(SList* l);

//求表长
int Length(SList l);

//删除表
void ListDelete(SList* l,int i,int* e);

//打印表
void PrintList(SList l);

//定位元素下标
int LocateElem(SList l,int e);

//判空
bool Empty(SList l);

//获取i下标元素
int GetElem(SList l,int i);

//销毁表
void DestroyList(SList* l);

//表插入
void ListInsert(SList* l,int i,int e);

#endif