/*
从上到下按层打印二叉树，同一层结点从左至右输出。每一层输出一行。
*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode{
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
    TreeNode(int x=0) : val(x), left(NULL), right(NULL){}
};

vector<vector<int> > Print(TreeNode* pRoot){
    vector<vector<int> > res;
    queue<TreeNode*> que;
    if(pRoot == NULL){
        return res;
    }
    que.push(pRoot);
    while(!que.empty()){
        int size = que.size();//每一层元素的数量
        vector<int> levelNode;
        while(size--){
            TreeNode* node = que.front();
            que.pop();
            levelNode.push_back(node->val);
            if(node->left != NULL){
                que.push(node->left);
            }
            if(node->right != NULL){
                que.push(node->right);
            }
        }
        res.push_back(levelNode);
    }

    return res;
}

int main()
{
    TreeNode tree[9];
    vector<vector<int> > res;

    tree[0].val =8;
    tree[0].left = &tree[1];
    tree[0].right = &tree[2];
    tree[1].val =6;
    tree[1].left = &tree[3];
    tree[1].right = &tree[4];
    tree[2].val =10;
    tree[2].left = &tree[5];
    tree[2].right = &tree[6];
    tree[3].val =4;
    tree[3].left = &tree[7];
    tree[3].right = &tree[8];
    tree[4].val =7;
    tree[4].left = NULL;
    tree[4].right = NULL;
    tree[5].val =9;
    tree[5].left = NULL;
    tree[5].right = NULL;
    tree[6].val =11;
    tree[6].left = NULL;
    tree[6].right = NULL;
    tree[7].val =3;
    tree[7].left = NULL;
    tree[7].right = NULL;
    tree[8].val =5;
    tree[8].left = NULL;
    tree[8].right = NULL;
    res = Print(tree);
    for(unsigned int i=0; i<res.size(); i++){
        for(unsigned int j=0; j<res[i].size(); j++){
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    return 0;
}