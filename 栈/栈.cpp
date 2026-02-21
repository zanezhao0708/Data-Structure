#include <stdio.h>
#include <stdbool.h>
#include <cstdlib>

#define STACK_INIT_SIZE 100

typedef struct stack
{
    int* top;
    int* base;
    int stacksize;
}stack;

//base指向栈底，若*base=null则栈不存在

bool Initstack(stack &S){
    S.base = (int*)malloc(STACK_INIT_SIZE*sizeof(int));
    //S.base 是指向栈底的指针，但它要指向一块能存放所有栈元素的内存，
    //所以要分配 size * sizeof(元素类型) 的空间
    
    if(!S.base)exit(-2);
    S.top=S.base;
    S.stacksize = STACK_INIT_SIZE;
    return 1;
}
bool GetStackTop(stack S,int &e){
    if(S.top == S.base)return 0;
    //栈顶元素在top的前一个位置，但我们只是查看栈顶元素，所以不需要移动top指针
    e = *(S.top - 1);
    
    return 1;
}

bool PushStack(stack &S ,int e){ 
    if(S.top-S.base >=S.stacksize){
        int newstacksize = S.stacksize+STACK_INIT_SIZE;
        int* newBase = (int*)realloc(S.base, newstacksize * sizeof(int));
        if(!newBase)return -1;
        S.base = newBase;
        S.stacksize = newstacksize;
        S.top = S.base + S.stacksize;
    }
    
    *(S.top)=e;
    S.top++;
    return 1;
}