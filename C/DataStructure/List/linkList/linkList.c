#include "../../global_inc.h"
#include "linkList.h"

//初始化链表
LList LList_Init()
{
    LList l = (LNode*)malloc(sizeof(LNode));
    if(l == NULL)return;
    l->data = NULL;
    l->next = NULL;
    return l;
}

//求表长
int LList_Length(LList l)
{
    int length = 0;
    LNode* curNode = l;
    while(curNode->next!=NULL)
    {
        curNode = curNode->next;
        length++;
    }
    return length;
}

//删除表元素(打印出来的表的第i个)
void LList_Delete(LList l,int i,int*e)
{
    //下标不正确,在1到长度之间(0为头结点不允许删除)
    if(i<=0||i>LList_Length(l))return;
    LNode* tmp = l;
    for(int idx = 1;idx<i;idx++)
        tmp = tmp->next;
    LNode* tofree = tmp->next;
    *e = tmp->next->data;
    tmp->next = tmp->next->next; 
    free(tofree);
}

//打印表
void LList_Print(LList l)
{
    LNode* tmp = l; 
    printf("[ ");
    do
    {
        if(tmp->next!=NULL){
            tmp = tmp->next;
            printf("%d->",tmp->data);
        }
    }while(tmp->next!=NULL);
    printf("NULL ]\n");
}

//获取元素的指针
LNode* LList_Locate(LList l,int e)
{
    if(l->next==NULL)return NULL;
    LNode* tmp = l->next;
    while(tmp->data!=e)
    {
        tmp = tmp->next;
        if(tmp==NULL)break;
    }
    return tmp;
}

//判空
bool LList_Empty(LList l)
{
    return l->next == NULL;
}

//获取第i个元素(不算头结点)
int LList_GetElem(LList l,int i)
{
    LNode* tmp = l;
    for(int idx = 1;idx<= i;idx++)
    {
        tmp = tmp->next;
    }
    return tmp->data;
}

//销毁表
void LList_DestroyList(LList l)
{
    LNode* tmp= l;
    LNode* nextToFree= tmp->next;
    while (tmp->next!=NULL)
    {
        free(tmp);
        tmp = nextToFree;
        nextToFree = nextToFree->next;
    }
}

//表插入(后插法)
void LList_Insert_Back(LNode* curNode,int e)
{
    LNode* tmp = (LNode*)malloc(sizeof(LNode));
    tmp->data = e;
    tmp->next = curNode->next;
    curNode->next = tmp;
}

//表插入(前插法，可实现链表逆置)
void LList_Insert_Pre(LNode* curNode,int e)
{
    LNode* tmp = (LNode*)malloc(sizeof(LNode));
    tmp->data = curNode->data;
    tmp->next = curNode->next;
    curNode->next = tmp;
    curNode->data = e;
}