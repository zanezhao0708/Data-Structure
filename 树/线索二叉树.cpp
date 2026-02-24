//以二叉树链表来存储信息时，我们只能得到结点左右的孩子信息，而不能直接得到任意序列的前驱和后继信息
//我们可以利用n+1个空指针域开存放前驱和后继信息

#include <stdio.h>
#include <stdbool.h>
#include <cstdlib>
#define MAXSIZE 100
ThrTreeNodePtr pre;

//仿照线性表的存储结构，在二叉树的线索链表上也添加了一个头节点，
//头节点的rchild域存放指向中序序列的头节点，lchild指向中序遍历的最后一个结点
//这样相当于建立了一个双向结点，可以从第一个，也可以从最后一个

typedef struct ThrTreeNode 
{
    int data;
    int ltag,rtag;//tag=0指示孩子，tag=1指示前驱结点
    struct ThrTreeNode* lchild,* rchild;
}ThrTreeNode , *ThrTreeNodePtr ;


bool CreateInThread(ThrTreeNodePtr &TreHead, ThrTreeNodePtr T) {
    TreHead = (ThrTreeNodePtr)malloc(sizeof(ThrTreeNode)); 
    if (!TreHead) return false;
    TreHead->ltag = 0; // 头节点的左指针指向树的根
    TreHead->rtag = 1; // 头节点的右指针指向中序遍历的最后一个节点
    TreHead->rchild = TreHead; // 右指针初始时指向自己（如果是空树的话）

    if (!T) {
        TreHead->lchild = TreHead; // 如果是空树，左指针也指向自己
    } else {
        TreHead->lchild = T; // 头节点的左孩子指向真正的树根
        pre = TreHead;       // 初始化 pre，让 pre 最开始指向头节点

        InTreading(T);

        // 处理最后一个节点
        // 当上面的 InTreading 执行完后，pre 刚好指向中序遍历的最后一个节点
        pre->rchild = TreHead; // 最后一个节点的后继指向头节点
        pre->rtag = 1;      // 设为线索
        TreHead->rchild = pre; // 头节点的右孩子指向最后一个节点
    }
    return true;
}
void InTreading(ThrTreeNodePtr T){
    /*pre是全局变量，初始化时其右孩子指针为空，便于最左点开始建线索*/
    if(T){
        InTreading(T->lchild);
        if(!T->lchild){
            T->ltag = 1;
            T->lchild = pre;
        }
        else T->ltag = 0;
        if(!pre->rchild){
            pre->rtag = 1;
            pre->rchild = T;
        }
        else pre->rtag= 0;
        pre = T;
        InTreading(T->rchild);
    }
}
