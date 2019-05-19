/*
请实现一个函数按照之字形打印二叉树，即第一行按照从左到右的顺序打印，第二层按照从右至左的顺序打印，
第三行按照从左到右的顺序打印，其他行以此类推。
*/
/*
用栈来保存结点的每一层
一个栈实现先进先出，即入栈顺序为右子结点、左子结点
一个栈实现后进先出，即入栈顺序为左子结点、右子结点
*/
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct TreeNode{
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
    TreeNode(int x=0) : val(x), left(NULL), right(NULL){}
};

vector<vector<int> > Print(TreeNode* pRoot){
    vector<vector<int> > res;
    if(pRoot == NULL){
        return res;
    }
    stack<TreeNode*> stack1, stack2;
    stack1.push(pRoot);
    while(!stack1.empty() || !stack2.empty()){
        if(!stack1.empty()){
            vector<int> vec;
            while(!stack1.empty()){
                TreeNode* node = stack1.top();
                stack1.pop();
                vec.push_back(node->val);
                if(node->left != NULL){
                    stack2.push(node->left);
                }
                if(node->right != NULL){
                    stack2.push(node->right);
                }
            }
            res.push_back(vec);
        }
        if(!stack2.empty()){
            vector<int> vec;
            while(!stack2.empty()){
                TreeNode* node = stack2.top();
                stack2.pop();
                vec.push_back(node->val);
                if(node->right != NULL){
                    stack1.push(node->right);
                }
                if(node->left != NULL){
                    stack1.push(node->left);
                }
            }
            res.push_back(vec);
        }
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