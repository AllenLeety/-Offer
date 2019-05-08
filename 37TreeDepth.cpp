/*
输入一棵二叉树，求该树的深度。从根结点到叶结点依次经过的结点（含根、叶结点）形成树的一条路径，
最长路径的长度为树的深度。
*/
#include <iostream>
#include <vector>
using namespace std;

struct TreeNode{
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
    //TreeNode(int x) : val(x), left(NULL), right(NULL){}
};

int TreeDepth(TreeNode* pRoot)
{
    if(pRoot == NULL){
        return 0;
    }
    int nleft = TreeDepth(pRoot->left);
    int nright = TreeDepth(pRoot->right);
    return (nleft > nright) ? (nleft+1) : (nright+1);
}

int main()
{
    TreeNode tree[7];

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

    cout << TreeDepth(tree) << endl;
    
    return 0;
}