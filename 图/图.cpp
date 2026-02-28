#include <stdio.h>
#include <stdbool.h>
#include <cstdlib>
#define MAXSIZE 30
// 比较难
//邻接表
typedef struct AdjArc
{
    int adjvex;//该弧指向的顶点的位置
    struct AdjArc* next;
    int info;
}AdjArc;

typedef struct AdjNode
{
    int data;
    AdjArc* first;
}AdjNode, AdjList[MAXSIZE];

typedef struct AdjGraph
{
    int kind;
    int arc ,vex;
    AdjList vexs;
}AdjGraph;







