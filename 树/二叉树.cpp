//对于二叉树，叶子结点为n，度为2点结点为m则，n = m+1
//结点i所在层次为log_2(i)+1
//对于二叉搜索树，左子树均小于根结点，右子树均大于根结点
//平衡二叉树任意结点的左右子树的深度之差的绝对值小于等于1

#include <stdio.h>
#include <stdbool.h>
#include <cstdlib>
#define MAXSIZE 100

typedef struct TreeNode
{
    int data;
    struct TreeNode* lchild,* rchild,* parent;
}TreeNode,*TreeNodePtr;


int VisitTreeNode(TreeNodePtr TreeNode,int &e){
    return e = TreeNode->data;
}

//先序遍历递归实现
void PreOrder_Re(TreeNodePtr TreeNode){
    int i = 0;
    if(TreeNode){
        printf("%d",VisitTreeNode(TreeNode,i));
        PreOrder_Re(TreeNode->lchild);
        PreOrder_Re(TreeNode->rchild);
    }
}

//先序遍历非递归实现
//用一个堆栈存储根结点入栈，出栈时将左右孩子入栈（右孩子先于左孩子）
bool PreOrder_Stack(TreeNodePtr T){
    if(!T)return 0;
    TreeNodePtr Stack[MAXSIZE];
    int top = -1;
    int data = 0;
    TreeNodePtr temp;
    top++;
    Stack[top] = T;
    while(top != -1){
        temp = Stack[top];
        VisitTreeNode(temp,data);
        top--;
        if(temp->rchild){
            top++;
            Stack[top]=temp->rchild;
        }
        if(temp->lchild){
            top++;
            Stack[top]=temp->lchild;   
    }
    return 1;
}
}
//层次遍历，借助队列
void LevelOrder_Queue(TreeNodePtr T){
    TreeNodePtr Queue[MAXSIZE];
    int front = 0;
    int rear = 0;
    Queue[rear] = T;
    rear++;
    int data = 0;
    TreeNodePtr temp = T;

    while(front != rear){
        if(temp->lchild){
            Queue[rear] = T->lchild;
            rear=(rear+1)%MAXSIZE;
        }
        if(temp->rchild){
            Queue[rear] = T->rchild;
            rear=(rear+1)%MAXSIZE;
        }
    VisitTreeNode(temp,data);
    front = (front+1)%MAXSIZE;
    temp = Queue[front];
    }
}


