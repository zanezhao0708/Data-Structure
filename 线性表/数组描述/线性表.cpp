#include <stdio.h>
#include <stdbool.h>
#include <cstdlib>

typedef struct LNode
{
    char name;
    struct LNode *next;
}LNode,*LinkList;

bool GetElem(LinkList L,int i,int j){//查找节点
    LinkList p = L->next;
    j = 1;
    while (j != i)
    {   
        if(!p)return 0 ;
        j++;
        p = p -> next;
    }
    return 1 ;
}

bool ListInsert(LinkList L,char e ,int site){//插入节点
    LinkList p = L->next;
    LinkList NewList = (LinkList)malloc(sizeof(LNode));
    if (NewList == NULL) return false;
    NewList->name = e;

    int j = 0;
    while(p != NULL &&j != site-1){
        if(p == NULL || p->next == NULL)return false;
        p = p->next;
        j++;
    }
    NewList->next = p->next;
    p->next = NewList;
    return true;
}

bool ListDelete(LinkList L,int site){//删除节点
    LinkList p = L;
    int j =0;
    while (p != NULL&&j < site-1)
    {
        p = p->next;
        j++;
    }
    if (p == NULL || p->next == NULL || site < 1) {
        return false; // 任何一个不满足
    }
    LinkList q = p->next;
    p->next = q -> next;
    free(q);
    return true;
}

typedef struct 
{
    int* data;//指向数据地址    
    int length;
}Sqlist;

//采用动态分配
void create(Sqlist* &L,int a[],int n){
    int length = 0;
    L = (Sqlist*) malloc(n * sizeof(Sqlist));
    L->data = (int*)malloc(n * sizeof(int));
    while (length < n)
    {
        L->data[length] = a[length];
        length++;
    }
    L->length = length;

}

bool insert(Sqlist* &L,int i,int e){
    int p;
    if(i < 1||i > L->length)return false;
    for(p = L->length-1 ; p >= i-1 ;p--){
        L->data[p+1] = L->data[p];
    }
    L->data[i-1]=e;
    L->length++;
    return true;
}

bool delet(Sqlist* &L,int i){
    int q;
    if(i-1 < 0||i -1> L->length-1)return false;
    for(q = i-1;q < L->length-1;q++){
        L->data[q] = L->data[q+1];
    }
    L->length--;
    return true;
}


int main(){
    return 0;
}