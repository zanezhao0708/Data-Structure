//链式存储不会在再出现假溢

#include <stdio.h>
#include <stdbool.h>
#include <cstdlib>

typedef struct DataNode{
    int data;
    DataNodePtr next;
}DataNode,*DataNodePtr;

typedef struct QueueLink
{
    DataNodePtr front;
    DataNodePtr rear;
}QueueLink,*QueueLinkPtr;

void InitQueue(QueueLinkPtr &Q){
    Q = (QueueLinkPtr)malloc(sizeof(QueueLink));
    DataNodePtr Dummy = (DataNodePtr)malloc(sizeof(DataNode));
    Dummy->next = nullptr;//next指针滞空
    Q->front = Q->rear=Dummy;
}

bool EmptyQueue(QueueLinkPtr Q){
    if(Q->rear==nullptr)return 1;
    return 0;
}
//重要  
void DestortQueue(QueueLinkPtr &Q){
    DataNodePtr pre = Q->front;
    if(pre){
        while (pre)
        {
            DataNodePtr temp =pre->next;
            free(pre);
            pre = temp;
        }
    }
    free(Q);
    Q = nullptr;
}

void QueueEntry(QueueLinkPtr &Q,int e){
    DataNodePtr temp = (DataNodePtr)malloc(sizeof(DataNode));
    temp->data = e;
    temp->next = nullptr;
    
    Q->rear->next = temp;
    Q->rear = temp;
}

bool QueueExit(QueueLinkPtr &Q,int &e){
    if(Q->front ==Q->rear) return 0;//队列为空
    e = Q->front->next->data;
    
    DataNodePtr temp =  Q->front->next;
    Q->front->next = temp->next;
    if(temp == Q->rear)Q->rear = Q->front;
    
    free(temp);
    return 1;
}