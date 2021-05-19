#include <stdio.h>
#include "DataStructure/List/SeqList/SeqList.h"
#include "DataStructure/List/LinkList/LinkList.h"
#include "DataStructure/Stack/SeqStack/SeqStack.h"
#include "DataStructure/Stack/LinkStack/LinkStack.h"
#include "DataStructure/Queue/LinkQueue/LinkQueue.h"
#include "DataStructure/Queue/SeqQueue/SeqQueue.h"

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

//顺序栈测试函数
void SeqStackTest()
{
    SStack stack = (SStack)malloc(sizeof(SStack));
    printf("初始化顺序栈中…\n");
    SStack_Init(stack);
    printf("初始化成功，此时栈是否为空?%c\n",SStack_Empty(stack)?'Y':'N');
    printf("正在对栈进行0~20的Push\n");
    for (int i = 0; i <= 20; i++)
    {
        if(!SStack_Push(stack,i)) {
            printf("在Push%d的时候失败\n",i);
            break;
        }
    }
    printf("已全部Push完毕!\n");
    printf("此时栈是否为空?%c\n",SStack_Empty(stack)?'Y':'N');
    printf("此时栈顶元素为%d\n",SStack_GetTop(stack));
    printf("开始Pop,如下\n[");
    int pop;
    while(SStack_Pop(stack,&pop))
    {
        printf(" %d",pop);
    }
    printf(" ]\n已经全部Pop成功!正在退出…\n");
}

//链栈测试函数
void LinkStackTest()
{
    printf("初始化链栈中…\n");
    LStack stack = LStack_Init(stack);
    printf("初始化成功，此时栈是否为空?%c\n",LStack_Empty(stack)?'Y':'N');
    printf("正在对栈进行0~20的Push\n");
    for (int i = 1; i <= 10; i++)
    {
        if(!LStack_Push(stack,i)) {
            printf("在Push%d的时候失败\n",i);
            break;
        }
    }
    printf("已全部Push完毕!\n");
    printf("此时栈是否为空?%c\n",LStack_Empty(stack)?'Y':'N');
    printf("此时栈顶元素为%d\n",LStack_GetTop(stack)->data);
    printf("开始Pop,如下\n[");
    int pop;
    while(LStack_Pop(stack,&pop))
    {
        printf(" %d",pop);
    }
    printf(" ]\n已经全部Pop成功!正在退出…\n");
    //free(stack);//此处不释放
}

void LinkQueueTest()
{
    printf("链式队列初始化中…\n");
    LQueue q = LQueue_Init();
    printf("链式队列是否为空?%c\n",LQueue_Empty(q)?'Y':'N');
    printf("入队1~10");
    for(int i = 1;i<=10;i++)
    {
        LQueue_EnQueue(q,i);
    }
    printf("链式队列是否为空?%c\n",LQueue_Empty(q)?'Y':'N');
    printf("此时队头元素为%d\n",LQueue_GetHead(q));
    printf("出队[ ");
    int deInt;
    while(!LQueue_Empty(q))
    {
        LQueue_DeQueue(q,&deInt);
        printf("%d ",deInt);
    }
    printf("]\n");
    printf("链式队列是否为空?%c\n",LQueue_Empty(q)?'Y':'N');
}

void SeqQueueTest()
{
    printf("顺序队列初始化中…\n");
    SQueue q;
    if(!SQueue_Init(&q)){
        printf("顺序队列初始化失败,正在退出…\n");
        return;
    }
    printf("顺序队列是否为空?%c\n",SQueue_Empty(q)?'Y':'N');
    printf("入队1~10");
    for(int i = 1;i<=10;i++)
    {
        SQueue_EnQueue(&q,i);
    }
    printf("顺序队列是否为空?%c\n",SQueue_Empty(q)?'Y':'N');
    printf("此时队头元素为%d\n",SQueue_GetHead(q));
    printf("出队[ ");
    int deInt;
    while(!SQueue_Empty(q))
    {
        SQueue_DeQueue(&q,&deInt);
        printf("%d ",deInt);
    }
    printf("]\n");
    printf("顺序队列是否为空?%c\n",SQueue_Empty(q)?'Y':'N');
}

int main()
{
    int sel;
    printf("请输入一个测试项:(11:SeqList\t12:LinkList\t21:SeqStack\t22:LinkStack\t31:LinkQueue\t32:SeqQueue\tothers:exit)\n");
    while(scanf("%d",&sel))
    {
        switch (sel)
        {
        case 11:
            SeqListTest();
            break;
        
        case 12:
            LinkListTest();
            break;
        
        case 21:
            SeqStackTest();
            break;
        
        case 22:
            LinkStackTest();
            break;

        case 31:
            LinkQueueTest();
            break;

        case 32:
            SeqQueueTest();
            break;

        default:
            printf("输个p，根本就没有");
            continue;
        }
        break;
    }
    return 0;
}
