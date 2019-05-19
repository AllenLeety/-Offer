/*
请实现一个函数，用来判断一颗二叉树是不是对称的。注意，如果一个二叉树同此二叉树的镜像是同样的，定义其为对称的。
*/
#include <iostream>
using namespace std;

struct TreeNode{
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
    TreeNode(int x=0) : val(x), left(NULL), right(NULL){}
};

bool isSymmetricalRecursion(TreeNode* pLeft, TreeNode* pRight){
    if(pLeft == NULL && pRight == NULL){
        return true;
    }
    if(pLeft == NULL || pRight == NULL){
        return false;
    }
    if(pLeft->val != pRight->val){
        return false;
    }
    //左子树的左与右子树的右  左子树的右与右子树的左
    return isSymmetricalRecursion(pLeft->left, pRight->right) && isSymmetricalRecursion(pLeft->right, pRight->left);
}

bool isSymmetrical(TreeNode* pRoot){
    if(pRoot == NULL){
        return true;
    }
    return isSymmetricalRecursion(pRoot->left, pRoot->right);
}

int main()
{
    TreeNode tree[7];

    tree[0].val = 8;
    tree[0].left = &tree[1];
    tree[0].right = &tree[2];

    
    tree[1].val = 6;
    tree[1].left = &tree[3];
    tree[1].right = &tree[4];

    
    tree[2].val = 6;
    tree[2].left = &tree[5];
    tree[2].right = &tree[6];

    
    tree[3].val = 5;
    tree[3].left = NULL;
    tree[3].right = NULL;
    
    tree[4].val = 7;
    tree[4].left = NULL;
    tree[4].right = NULL;
    
    tree[5].val = 7;
    tree[5].left = NULL;
    tree[5].right = NULL;
    
    tree[6].val = 5;
    tree[6].left = NULL;
    tree[6].right = NULL;

    cout << isSymmetrical(tree) << endl;
    
    return 0;
}