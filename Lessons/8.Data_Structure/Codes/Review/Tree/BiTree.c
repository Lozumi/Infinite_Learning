#include <stdio.h>
#define DataType int

typedef struct Node{
    DataType data;
    struct Node *LChild;
    struct Node *RChild;
}BiTNode, *BiTree;

//遍历
void PreOrder(BiTree root){
    if(root!=NULL)
    {
        Visit(root->data);
        PreOrder(root->LChild);
        PreOrder(root->RChild);
    }
}

//遍历
void InOrder(BiTree root){
    if(root!=NULL)
    {
        PreOrder(root->LChild);
        Visit(root->data);
        PreOrder(root->RChild);
    }
}

//遍历
void PostOrder(BiTree root){
    if(root!=NULL)
    {
        PreOrder(root->LChild);
        PreOrder(root->RChild);
        Visit(root->data);
    }
}

int PostTreeDepth(BiTree bt){
    int hl,hr,max;
    if(bt!=NULL){
        hl=PostTreeDepth(bt->LChild);
        hr=PostTreeDepth(bt->RChild);
        max=hl>hr?hl:hr;
        return (max+1);
    }
    else
        return 0;
}

// 二叉树的存储
//孩子兄弟节点法
typedef struct CSNode{
    DataType data;
    struct CSNode* FirstChild;
    struct CSNode* NextSibling;
} CSNode, *CSTree;

//树的遍历
void RootFirst(CSTree root){
    if(root!=NULL)
    {
        Visit(root->data);
        RootFirst(root->FirstChild);
        RootFirst(root->NextSibling);
    }
}

// 哈夫曼树的存储
const int N=20; // 叶子结点的最大值
const int M=39; // 所有节点的最大值 2*N+1
typedef struct
{
    int weight;
    int parent;
    int LChild;
    int RChild;
} HTNode,HuffmanTree[21];

void createHuffmanTree(HuffmanTree ht,int w[],int n){ // 构造哈夫曼树ht[M+1]，w[]存放n个权值
    int i,m;
    for (i=1;i<=n;i++)
        ht[i]={w[i],0,0,0};
    m=2*n-1;
    for (i=n+1;i<=m;i++)
        ht[i]={0,0,0,0};
    //初始化完毕
    int s1,s2;
    for(i=n+1;i<=m;i++){
        select(ht,i-1,&s1,&s2);
        ht[i].weight=ht[s1].weight+ht[s2].weight;
        ht[s1].parent=i;
        ht[s2].parent=i;
        ht[i].LChild=s1;
        ht[i].LChild=s2;
    }

}

