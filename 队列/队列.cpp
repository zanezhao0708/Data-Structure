//在队列中，元素的插入发生在队尾，而元素的删除发生在队头，
//先进先出特性使队列适于需要按顺序处理数据的场景，例如任务调度、数据流处理等。

#include <stdio.h>
#include <stdbool.h>
#include <cstdlib>
#define MAXSIZE 100

typedef struct Queue{
    int data[MAXSIZE];
    int front,rear;//队首队尾指针
}Queue,*QueuePtr;

void InitQueue(QueuePtr &Q){
    Q = (QueuePtr)malloc(sizeof(Queue));
    Q->front = Q->rear =0;
}

void DestroyQueue(QueuePtr &Q){
    free(Q);
}

bool QueueEmpty(QueuePtr Q){
    if(Q->front ==Q->rear)return 1;
    else return 0;
}

bool QueueEnter(QueuePtr &Q,int e){
    if (Q->rear == MAXSIZE)return 0;
    Q->data[Q->rear]=e;
    Q->rear ++;
    return 1;
}

bool QueueExit(QueuePtr &Q,int &e){
    if(Q->front==Q->rear)return 0;
    e = Q->data[Q->front];
    Q->front++;
    return 1;
}