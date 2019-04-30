/*
输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的双向链表。要求不能创建任何新的结点，只能调整树中结点的指向
*/
#include <iostream>
using namespace std;

struct TreeNode{
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
    //TreeNode(int x):val(x), left(NULL), right(NULL){}
};

void ConvertRecursion(TreeNode* root, TreeNode** pLastNode)
{
    if(root == NULL){
        return;
    }
    TreeNode* currentNode = root;
    //中序遍历 左子树
    if(root->left != NULL){
        ConvertRecursion(root->left, pLastNode);
    }
    /*访问根节点，将左子树的根与根节点连接成一个链表*/
    //开始连接左子树和当前根节点
    currentNode->left = *pLastNode;
    if(*pLastNode != NULL){
        (*pLastNode)->right = currentNode;
    }
    //更新上一个访问的指针域
    *pLastNode = currentNode;
    if(currentNode->right != NULL){
        ConvertRecursion(currentNode->right, pLastNode);
    }
}

TreeNode* Convert(TreeNode* pRootOfTree)
{
    if(pRootOfTree == NULL){
        return NULL;
    }
    TreeNode* pLastNode = NULL;
    ConvertRecursion(pRootOfTree, &pLastNode);
    //当递归结束后，*pLastNode指向了双向链表的尾结点
   // TreeNode* node = pLastNode;
    while(pLastNode != NULL && pLastNode->left != NULL){
        pLastNode = pLastNode->left;
    }
    return pLastNode;
}

int main()
{
    TreeNode tree[4];

    tree[0].val = 4;
    tree[0].left = &tree[1];
    tree[0].right = &tree[2];
    tree[1].val = 3;
    tree[1].left = &tree[3];
    tree[1].right = NULL;
    tree[2].val = 5;
    tree[2].left = NULL;
    tree[2].right = NULL;
    tree[3].val = 2;
    tree[3].left = NULL;
    tree[3].right = NULL;

    TreeNode* head = Convert(tree);
    while(head != NULL){
        cout << head->val << " ";
        head = head->right;
    }
    cout << endl;

    return 0;
}