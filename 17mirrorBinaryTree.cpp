/*操作给定的二叉树，将其变换为源二叉树的镜像*/
#include <iostream>
using namespace std;

struct TreeNode{
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
 //   TreeNode(int x):val(x), left(NULL), right(NULL){}
};

class BinaryTree{
public:
    BinaryTree();
    ~BinaryTree();
    void insert(int key);
    void destory_tree();
    TreeNode* serach(int key);
    void preOrder_print();

private:
    void insert(int key, TreeNode* root);
    TreeNode* serach(int key, TreeNode* root);
    void destory_tree(TreeNode* root);
    void preOrder_print(TreeNode* root);
    TreeNode* root;
};

BinaryTree::BinaryTree(){
    root = NULL;
}

BinaryTree::~BinaryTree(){
    destory_tree();
}

void BinaryTree::destory_tree(){
    destory_tree(root);
}

void BinaryTree::destory_tree(TreeNode* root){
    if(root != NULL){
        destory_tree(root->left);
        destory_tree(root->right);
        delete root;
    }
}

void BinaryTree::insert(int key, TreeNode* root){
    if(key < root->val){ //插入左子树
        if(root->left != NULL){
            insert(key, root->left);
        }else{
            root->left = new TreeNode();
            root->left->val = key;
            root->left->left = NULL;
            root->left->right = NULL;
        }
    }else if(key >= root->val){ //插入右子树
        if(root->right != NULL){
            insert(key, root->right);
        }else{
            root->right = new TreeNode();
            root->right->val = key;
            root->right->left = NULL;
            root->right->right = NULL;
        }
    }
}

void BinaryTree::insert(int key){
    if(root != NULL){
        insert(key, root);
    }else{
        root = new TreeNode();
        root->val = key;
        root->left = NULL;
        root->right = NULL;
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

void BinaryTree::preOrder_print(TreeNode* root){
    if(root == NULL){
        return;
    }
    cout << root->val << " ";
    preOrder_print(root->left);
    preOrder_print(root->right);
}

void BinaryTree::preOrder_print(){
    preOrder_print(root);
}


void Mirror(TreeNode* pRoot)
{
    if(pRoot == NULL || (pRoot->left == NULL && pRoot->right)){
        return;
    }
    TreeNode* pTmp = pRoot->left;
    pRoot->left = pRoot->right;
    pRoot->right = pTmp;

    if(pRoot->left){
        Mirror(pRoot->left);
    }
    if(pRoot->right){
        Mirror(pRoot->right);
    }
}

int main()
{
    BinaryTree* tree = new BinaryTree();
    TreeNode* root = new TreeNode();

    cout << "the original tree:" << endl;
    tree->insert(8);
    tree->insert(6);
    tree->insert(10);
    tree->insert(4);
    tree->insert(7);
    tree->insert(9);
    tree->insert(11);
    tree->preOrder_print();
    root = tree->serach(8);
    cout << endl;
    //二叉树镜像
    Mirror(root);
    cout << "the mirror tree:" << endl;
    tree->preOrder_print();
    cout << endl;

    return 0;
}