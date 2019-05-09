/*
输入一棵二叉树的根结点，判断该树是不是平衡二叉树。如果某二叉树中任意结点的左右子树的深度相差
不超过1，那么它就是一棵平衡二叉树。
*/
#include <iostream>
using namespace std;

struct BinaryTreeNode{
    int val;
    struct BinaryTreeNode* left;
    struct BinaryTreeNode* right;
};

int TreeDepth(BinaryTreeNode *pRoot){
    if(pRoot == NULL){
        return 0;
    }
    int nleft = TreeDepth(pRoot->left);
    int nright = TreeDepth(pRoot->right);
    return (nleft > nright) ? (nleft+1) : (nright+1);
}

bool IsBalanced(BinaryTreeNode* pRoot){
    if(pRoot == NULL){
        return true;
    }
    int left = TreeDepth(pRoot->left);
    int right = TreeDepth(pRoot->right);
    int diff = left - right;
    if(diff > 1 || diff < -1){
        return false;
    }

    return IsBalanced(pRoot->left) && IsBalanced(pRoot->right);
}

int main()
{
    BinaryTreeNode tree[7];

    tree[0].val = 1;
    tree[0].left = &tree[1];
    tree[0].right = &tree[2];
    tree[1].val = 2;
    tree[1].left = &tree[3];
    tree[1].right = &tree[4];
    tree[2].val = 3;
    tree[2].left = NULL;
    tree[2].right = &tree[5];
    tree[3].val = 4;
    tree[3].left = NULL;
    tree[3].right = NULL;
    tree[4].val = 5;
    tree[4].left = &tree[6];
    tree[4].right = NULL;
    tree[5].val = 6;
    tree[5].left = NULL;
    tree[5].right = NULL;
    tree[6].val = 7;
    tree[6].left = NULL;
    tree[6].right = NULL;

    cout << IsBalanced(tree) << endl;

    return 0;
}