//由于计算顺序和输出顺序相反及先进后出，考虑使用栈结构

#include <stdio.h>
#include <stdbool.h>
#include <cstdlib> 

typedef struct StackNode{
    int data;
    StackPtr next;
}StackNode,*StackPtr;

//假设为10进制->2进制
void solution (StackPtr S,int e){
    InitStack(S);
    while(e){
        StackPush(S,e%2);
        e=e/2;
    }
    int i;
    while(!StackEmpty(S))
        StackPop(S,i);
        printf("%d",i);
}
 

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

bool StackPop(StackPtr &S,int &e){
    if(!S)return 0;
    // 直接是错的S = S->next;因为你没有释放
    StackPtr p = (StackPtr)malloc(sizeof(StackNode));
    p = S;
    e = p->data;
    S = S->next;
    free(p);

    return 1;
}

bool StackEmpty(StackPtr S){
    if(S == NULL)return 1;
    else return 0;
}