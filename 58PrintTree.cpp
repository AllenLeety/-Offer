/*
请实现一个函数按照之字形打印二叉树，即第一行按照从左到右的顺序打印，第二层按照从右至左的顺序打印，
第三行按照从左到右的顺序打印，其他行以此类推。
*/
#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

struct TreeNode{
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
    TreeNode(int x=0) : val(x), left(NULL), right(NULL){}
};

vector<vector<int> > Print(TreeNode* pRoot){
    vector<vector<int> > res;
    deque<TreeNode*> deq;
    if(pRoot ==NULL){
        return res;
    }
    vector<int> cur;
    deq.push_back(NULL);    //层分隔符
    deq.push_back(pRoot);
    bool flag = true;
    while(deq.size() != 1){
        TreeNode* node = deq.front();
        deq.pop_front();
        if(node == NULL){   //到达每层分隔符
            if(flag){   //从前往后遍历
                deque<TreeNode*>::iterator iter;
                for(iter = deq.begin(); iter != deq.end(); iter++){
                    cur.push_back((*iter)->val);
                }
            }else{  //从后往前遍历
                deque<TreeNode*>::reverse_iterator iter;
                for(iter = deq.rbegin(); iter != deq.rend(); iter++){
                    cur.push_back((*iter)->val);
                }
            }
            flag = !flag;
            res.push_back(cur);
            cur.clear();
            deq.push_back(NULL);//添加分隔符
            continue;
        }
        if(node->left != NULL){
            deq.push_back(node->left);
        }
        if(node->right != NULL){
            deq.push_back(node->right);
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