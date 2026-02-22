#include <stdio.h>
#include <stdbool.h>
#include <cstdlib>
//共享栈是指，在同一块连续的内存空间中，两个栈分别从两端向中间生长，
//共享栈的实现需要维护两个栈顶指针，分别指向两个栈的顶部。

//当一个栈需要入栈时，首先检查两个栈顶指针之间的空间是否足够，
//如果足够，则将元素压入对应的栈中，并更新对应的栈顶指针；如果空间不足，则需要进行扩容操作    

typedef struct sharedstack{
    int* base;
    int* top1;
    int* top2;
    int stacksize;
}sharedstack;

bool InitSharedStack(sharedstack &S, int size){
    S.base = (int*)malloc(size * sizeof(int));
    if(!S.base)return 0;
    S.top1 = S.base;
    S.top2 = S.base + size;
    S.stacksize = size;
    return 1;
}

bool PushSharedStack(sharedstack &S, int e, bool isLeft){
    if(S.top1 >= S.top2)return 0; //栈满
    if(isLeft){
        *(S.top1) = e;
        S.top1++;
        return 1;
    }else{
        *(S.top2 - 1) = e;
        S.top2--;
        return 1;
    }
}

bool PullSharedStack(sharedstack &S, int &e, bool isLeft){
    //top1 = -1时，左栈空
    if(isLeft && S.top1 == S.base)return 0; //左栈空
    //top2 = stacksize时，右栈空    
    if(!isLeft && S.top2 == S.base + S.stacksize)return 0; //右栈空
    if(isLeft){
        S.top1--;
        e = *(S.top1);
        return 1;
    }else{
        e = *(S.top2);
        S.top2++;
        return 1;
    }
}