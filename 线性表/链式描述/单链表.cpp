#include <stdio.h>
#include <stdbool.h>
#include <cstdlib>

typedef struct LNode
{
    int data;
    LNodeLink* next;
}LNodeLink;

//头插法    
void CreateListHead(LNodeLink* &L,int n,int arr[]){
    LNodeLink* s;
    int i;
    L = (LNodeLink*)malloc(n*sizeof(LNodeLink));
    L ->next = nullptr;
    
    
    for (int i = 0; i < n; i++)
    {
        s = (LNodeLink*)malloc(sizeof(LNodeLink));
        s->data = arr[i];
        s->next = L ->next;
        L ->next = s;
    }
}

//尾插法
void CreateListTail(LNodeLink* &L,int n,int arr[]){
    L = (LNodeLink*)malloc(sizeof(LNodeLink));
    L->next = nullptr;
    LNodeLink* tail =L;//此时操作tail就是操作头节点
    for (int i = 0; i < n; i++)
    {
        LNodeLink* s = (LNodeLink*)malloc(sizeof(LNodeLink));
        s->data = arr[i];
        tail->next = s;//将tail（当前节点）的next指向s
        tail = s;//将tail移动到s的位置
    }
    tail->next=nullptr;
}


//插入到第n个位置
void InsertNode(LNodeLink* &L,int n,int x){
    LNodeLink* pre = L;
    int i =0;
    while(pre != nullptr&&i < n){
        i++;
        pre = pre->next;//这里我很容易错
    }
    LNodeLink*temp = (LNodeLink*)malloc(sizeof(LNodeLink));
    //此时pre就是要插入到前一个节点 
    temp->data = x;
    temp->next = pre->next;
    pre->next = temp;

}

//删除
void DeleteNode(LNodeLink* &L,int n){
    LNodeLink* pre = L;
    int i=0;
    while(pre !=nullptr&&i < n){
        i++;
        pre = pre->next;
    }
    LNodeLink* q = pre->next;
    pre->next = q->next;
    free(q);
}