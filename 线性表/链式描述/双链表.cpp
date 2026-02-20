#include <stdio.h>
#include <stdbool.h>
#include <cstdlib>

typedef struct DNode
{
    int data;
    DNodeLink* next;
    DNodeLink* prior;
}DNodeLink;


//头插法   
void   CreateListHead(DNodeLink* &L,int n, int arr[]){
    L = (DNodeLink*)malloc(sizeof(DNodeLink));
    L->next =nullptr;
    L->prior = nullptr;
    for(int i=0;i<n;i++){
        DNodeLink *s = (DNodeLink*)malloc(sizeof(DNodeLink));
        s->data = arr[i];


        s->next = L->next;
        if (L->next != nullptr)
        {
            L->next->prior = s;
        }
        L->next = s;
        s->prior =L;

    }

}