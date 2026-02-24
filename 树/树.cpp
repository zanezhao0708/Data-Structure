//一些基础性质
//树的节点个数=所有节点的度数之和+1
//度为m的树的i层上最多有m^(i-1)个结点
//高度为h的m叉树至多有（m^h-1）/m-1个结点
//具有n个结点的m叉树的最小高度为log_m (n(m-1)+1)
//n个结点的度为k的树中必有nk-（n-1）=n（k-1）+1个空链域


//树的顺序存储，
//用一个二元组来表示，一元表示自己，另一元表示自己的负结点（最上方的为-1）
#define MAXSIZE 100

typedef struct TreeNode//用于存放单一的结点
{
    int data;
    int parent;
}TreeNode;

typedef struct Tree//用于记录整棵树的信息
{
    TreeNode nodes[MAXSIZE];
    int root;//根结点位置
    int n;//节点数
}Tree;




//孩子表示法，每个节点有多个指针域，每个指针指向一棵子树的根结点

//孩子链表表示法：由两个域组成，一个存放自己的信息，另一个存放指针，指针指向由该节点孩子组成的单链表的表头

typedef struct ChildNode//孩子结点
{
    int child;
    struct ChildNode* next;
}ChildNode,*ChildNodePtr;

typedef struct TreeNode//每个节点
{
    int data;
    ChildNodePtr first;//指向第一个孩子
}TreeNode;

typedef struct Tree//整棵树的结构
{
    TreeNode nodes[MAXSIZE];
    int root;
    int n;
}Tree;
//但是这样只方便找孩子，不方便找双亲，所以可以把上面两种方式结合起来



//孩子兄弟表示法，两个指针域，左边指向第一个孩子，另一边指向下一个兄弟结点，破坏了树的层次
typedef struct TreeNode
{
    int data;
    struct TreeNode* broNode,*ChildNode;
}TreeNode,*TreeNodePtr;
