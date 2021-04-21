#include <stdio.h>
#include "DataStructure/List/seqList/seqList.h"
#include "DataStructure/List/linkList/linkList.h"

//顺序表测试
void SeqListTest()
{
    SList list;
    printf("初始化列表中…\n");
    if (!InitList(&list))
    {
        printf("初始化失败!");
        return ;
    }
    printf("list是否为空(Y/N)?%c\n", Empty(list) ? 'Y' : 'N');
    printf("生成数据中…\n");
    for (int i = 1; i <= 10; i++)
        ListInsert(&list, list.length, i);
    printf("list是否为空(Y/N)?%c\n", Empty(list) ? 'Y' : 'N');
    PrintList(list);
    printf("测试在下标为1的位置插入11\n");
    ListInsert(&list, 1, 11);
    PrintList(list);
    printf("查找到元素11的下标位置为%d\n", LocateElem(list, 11));
    printf("查找到元素下标位置为3的元素为%d\n", GetElem(list, 3));
    printf("删除下标为5的表数据中…\n");
    int tail;
    ListDelete(&list, 5, &tail);
    printf("删除成功，数据为%d\n", tail);
    printf("此时表长为%d\n", Length(list));
    printf("销毁表中…\n");
    DestroyList(&list);
}

//链表测试函数
void LinkListTest()
{
    LList l = LList_Init();
    printf("初始化链表…\n");
    if(l==NULL){
        printf("初始化失败，正在退出…\n");
        return;
    }else{
        printf("初始化成功！此时表长为%d\n",LList_Length(l));
    }
    printf("插入数据，10,20,30…100\n");
    LNode* tail = l;
    for(int i = 0;i<=100;i+=10)
    {
        LList_Insert_Back(tail,i);
        tail= tail->next;
    }
    printf("此时的链表为:\n");
    LList_Print(l);
    printf("此时表长为%d，在元素10前插入11\n",LList_Length(l));
    LNode* locate10 =LList_Locate(l,10);
    if(locate10 == NULL)
        printf("找不到元素10的位置\n");
    else
        LList_Insert_Pre(locate10,11);
    printf("此时的链表为:\n");
    LList_Print(l);
    printf("删除第5个元素,");
    int deled;
    LList_Delete(l,5,&deled);
    printf("被删除的数据为%d,此时的链表为:\n",deled);
    LList_Print(l);
    printf("此时列表中第6个元素为%d\n",LList_GetElem(l,6));
    printf("销毁表中…\n");
    LList_DestroyList(l);
    printf("销毁成功！\n");
}

int main()
{
    int sel;
    printf("请输入一个测试项:(1:SeqList 2:LinkList 3:…)\n");
    while(scanf("%d",&sel))
    {
        switch (sel)
        {
        case 1:
            SeqListTest();
            break;
        
        case 2:
            LinkListTest();
            break;
        
        default:
            printf("输个p，根本就没有");
            continue;
        }
        break;
    }
    return 0;
}
