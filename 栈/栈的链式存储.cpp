#include <stdio.h>
#include <stdbool.h>
#include <cstdlib>  
//栈的链式存储通常不采用带头节点的单链表表示，
//因为栈的操作只涉及到栈顶元素，使用带头节点的单链表会增加不必要的空间开销和操作复杂度。

//栈的插入与删除只在表头进行。

typedef struct StackNode{

    int data;
    StackPtr next;
}StackNode,*StackPtr;


bool InitStack(StackPtr &S){
    S = NULL;
    return 1;
}

bool StackPush(StackPtr &S,int e){
    StackPtr p = (StackPtr)malloc(sizeof(StackNode));
    p->data = e;
    p->next = S;
    S = p;
    return 1;
}

bool StackPull(StackPtr &S,int &e){
    if(!S)return 0;
    // 直接是错的S = S->next;因为你没有释放
    StackPtr p = (StackPtr)malloc(sizeof(StackNode));
    p = S;
    e = p->data;
    S = S->next;
    free(p);

    return 1;
}

int GetElem(StackPtr S){
    if(!S)return 0;
    return S->data;
}