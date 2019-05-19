/*
给定一棵二叉搜索树，请找出其中的第k小的结点。例如，（5，3，7，2，4，6，8）中，
按结点数值大小顺序第三小结点的值为4。
*/
#include <iostream>
#include <stack>
using namespace std;

struct TreeNode{
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
    TreeNode(int x=0) : val(x), left(NULL), right(NULL){}
};

int count = 0;

TreeNode* KthNode(TreeNode* pRoot, int k){
    if(pRoot == NULL){
        return NULL;
    }
    TreeNode* node = pRoot;
    stack<TreeNode*> nStack;
    while(node != NULL || !nStack.empty()){
        while(node != NULL){//找到二叉搜索树的最左结点
            nStack.push(node);
            node = node->left;
        }
        if(!nStack.empty()){
            node = nStack.top();
            count++;
            if(count == k){
                return node;
            }
            nStack.pop();
            node = node->right;
        }
    }
    return NULL;
}

int main()
{
    TreeNode tree[7];

    tree[0].val = 5;
    tree[0].left = &tree[1];
    tree[0].right = &tree[2];

    tree[1].val = 3;
    tree[1].left = &tree[3];
    tree[1].right = &tree[4];

    tree[2].val = 7;
    tree[2].left = &tree[5];
    tree[2].right = &tree[6];

    tree[3].val = 2;
    tree[3].left = NULL;
    tree[3].right = NULL;

    tree[4].val = 4;
    tree[4].left = NULL;
    tree[4].right = NULL;

    tree[5].val = 6;
    tree[5].left = NULL;
    tree[5].right = NULL;

    tree[6].val = 8;
    tree[6].left = NULL;
    tree[6].right = NULL;
    TreeNode* res = KthNode(tree, 3);
    if(res != NULL){
        cout << res->val << endl;
    }else{
        cout << "Null node" << endl;
    }

    return 0;
}