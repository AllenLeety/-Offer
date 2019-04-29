/*从上往下打印出二叉树的每个节点，同层节点从左至右打印。*/
#include <iostream>
#include <deque>
#include <vector>
using namespace std;

struct TreeNode
{
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

class BinaryTree{
public:
    BinaryTree();
    ~BinaryTree();
    void insert_tree(int value);
    void delete_tree(TreeNode* root);
    TreeNode* serach(int key);
    vector<int> PrintFromTopToBottom(TreeNode* root);

private:
    void insert_tree(int value, TreeNode* root);
    TreeNode* serach(int key, TreeNode* root);
    TreeNode* root;
};

BinaryTree::BinaryTree(){
    root = NULL;
}

BinaryTree::~BinaryTree(){
    delete_tree(root);
}

void BinaryTree::delete_tree(TreeNode* root){
    if(root != NULL){
        delete_tree(root->left);
        delete_tree(root->right);
        delete root;
    }
}

void BinaryTree::insert_tree(int key){
    if(root != NULL){
        insert_tree(key, root);
    }else{
        root = new TreeNode();
        root->val = key;
        root->left = NULL;
        root->right = NULL;
    }
}

void BinaryTree::insert_tree(int value, TreeNode* root){
    if(value < root->val){//插入左子树
        if(root->left != NULL){
            insert_tree(value, root->left);
        }else{
            root->left = new TreeNode();
            root->left->val = value;
            root->left->left = NULL;
            root->left->right = NULL;
        }
    }else if(value >= root->val){//插入右子树
        if(root->right != NULL){
            insert_tree(value, root->right);
        }else{
            root->right = new TreeNode();
            root->right->val = value;
            root->right->left = NULL;
            root->right->right = NULL;
        }
    }

}

TreeNode* BinaryTree::serach(int key, TreeNode* root){
    if(root != NULL){
        if(key == root->val){
            return root;
        }else if(key < root->val){
            return serach(key, root->left);
        }else{
            return serach(key, root->right);
        }
    }else {
        return NULL;
    }
}

TreeNode* BinaryTree::serach(int key){
    return serach(key, root);
}

vector<int> BinaryTree::PrintFromTopToBottom(TreeNode* root) 
{
    vector<int> tmp;
    if(root == NULL){
        return tmp;
    }
    deque<TreeNode*> que;
    que.push_back(root);
    while(que.size()){
        TreeNode* pNode = que.front();
        que.pop_front();
        tmp.push_back(pNode->val);
        cout << pNode->val << " ";
        if(pNode->left){
            que.push_back(pNode->left);
        }
        if(pNode->right){
            que.push_back(pNode->right);
        }
    }
    return tmp;
}

int main()
{
    //int arr[] = {8, 6, 10, 5, 7, 9, 11};
    BinaryTree* tree = new BinaryTree();
    TreeNode* root = new TreeNode();
    vector<int> vec;

    tree->insert_tree(8);
    tree->insert_tree(6);
    tree->insert_tree(10);
    tree->insert_tree(5);
    tree->insert_tree(7);
    tree->insert_tree(9);
    tree->insert_tree(11);

    root = tree->serach(8);
    vec = tree->PrintFromTopToBottom(root);
    cout << endl;

    return 0;
}