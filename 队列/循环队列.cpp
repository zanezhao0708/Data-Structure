//在循环队列中，入队是尾指针追赶头指针，出队是头指针追赶尾指针，此时两者重合我们无法判断是空还是满
//解决方法：牺牲一个存储空间，当队列中元素个数为MAXSIZE-1时，认为队列已满
//空：front == rear
//满：（rear + 1）% MAXSIZE == front 

#include <stdio.h>
#include <stdbool.h>
#include <cstdlib>
#define MAXSIZE 100

typedef struct Queue
{
    int data[MAXSIZE];
    int front,rear;
}Queue,*QueuePtr;

void InitQueue(QueuePtr &Q){
    Q = (QueuePtr)malloc(sizeof(Queue));
    Q->front = Q->rear =0;
}

bool EmptyQueue(QueuePtr Q){
    if(Q->front == Q->rear)return 1;
    else return 0;
}

bool QueueEntry(QueuePtr &Q,int e){
    if((Q->rear+1)%MAXSIZE == Q->front)return 0;
    Q->data[Q->rear] = e;
    Q->rear = (Q->rear +1)%MAXSIZE;

    return 1;
}
//切记出/入队前要检查是否空/满
bool QueueExit(QueuePtr &Q,int &e){
    if(Q->front == Q->rear) return 0;
    e =  Q->data[Q->front];//front直接指向要出队元素
    Q->front = (Q->front+1)%MAXSIZE;
    return 1;
}