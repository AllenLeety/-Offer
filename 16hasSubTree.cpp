/*
输入两棵二叉树A，B，判断B是不是A的子结构。（ps：我们约定空树不是任意一个树的子结构）
*/
#include <iostream>
using namespace std;

struct TreeNode{
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

class BinaryTree{
public:
    BinaryTree();
    ~BinaryTree();
    void insert(int key);
    void destory_tree();
    TreeNode* serach(int key);
    void preOrder_print();
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2);

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

void BinaryTree::destory_tree(TreeNode* root){
    if(root != NULL){
        destory_tree(root->left);
        destory_tree(root->right);
        delete root;
    }
}

void BinaryTree::destory_tree(){
    destory_tree(root);
}

void BinaryTree::insert(int key, TreeNode* root)
{
    if(key < root->val){//插入左子树
        if(root->left != NULL){
            insert(key, root->left);
        }else{
            root->left = new TreeNode();
            root->left->val = key;
            root->left->left = NULL;
            root->left->right = NULL;
        }
    }else if(key >= root->val){//插入右子树
        if(root->right != NULL){
            insert(key, root->right);
        }else{
            root->right = new TreeNode();
            root->right->val = key;
            root->right->right = NULL;
            root->right->left = NULL;
        }
    }
}

void BinaryTree::insert(int key)
{
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
    }else{
        return NULL;
    }
}

TreeNode* BinaryTree::serach(int key){
    return serach(key, root);
}

//先序遍历
void BinaryTree::preOrder_print(TreeNode* root)
{
    if(root == NULL){
        return;
    }
    cout << root->val << " ";
    preOrder_print(root->left);
    preOrder_print(root->right);
}

void BinaryTree::preOrder_print(){
    preOrder_print(root);
    cout << endl;
}

//判断是否有子树
bool DoesParentHaveChild(TreeNode* pRoot1, TreeNode* pRoot2)
{
    if(pRoot2 == NULL){//子树为NULL，那么必然是子树
        return true;
    }else if(pRoot1 == NULL){
        return false;
    }
    return DoesParentHaveChild(pRoot1->left, pRoot2->left) && DoesParentHaveChild(pRoot1->right, pRoot2->right);
}

bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
{
    if(pRoot1 == NULL || pRoot2 == NULL){
        return false;
    }
    bool result;
    //如果当前父树的结点与子树的根节点相同，则直接从父树的当前位置开始判定
    if(pRoot1->val == pRoot2->val){
        result = DoesParentHaveChild(pRoot1, pRoot2);
    }
    if(!result){    //从左子树查找
        result = HasSubtree(pRoot1->left, pRoot2);
    }
    if(!result){
        result = HasSubtree(pRoot1->right, pRoot2);
    }
    return result;
}

int main()
{
    BinaryTree* Parent = new BinaryTree();
    BinaryTree* Child = new BinaryTree();
    bool flag;
    TreeNode* pRoot1 = NULL;
    TreeNode* pRoot2 = NULL;
    
    cout << "parent tree:" << endl;
    Parent->insert(8);//1代表插入左子树
    Parent->insert(6);
    Parent->insert(10);//2代表插入右子树
    Parent->insert(4);
    Parent->insert(7);
    Parent->insert(9);
    Parent->insert(11);  
    Parent->preOrder_print();
    pRoot1 = Parent->serach(8);

    cout << "child tree:" << endl;
    Child->insert(6);
    Child->insert(4);
    Child->insert(7);
    Child->preOrder_print();
    pRoot2 = Child->serach(6);

    flag = HasSubtree(pRoot1, pRoot2);
    if(flag){
        cout << "yes! HasSubtree" << endl;
    }else{
        cout << "no! not HasSubtree" << endl;
    }

    delete Parent;
    delete Child;

    return 0;
}