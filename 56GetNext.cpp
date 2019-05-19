/*
给定一个二叉树和其中的一个结点，请找出中序遍历顺序的下一个结点并且返回。注意，树中的结点不仅包含左右子结点，
同时包含指向父结点的指针。
*/
/*
（1）如果当前结点有右子树，那么其中序遍历的下一个结点就是其右子树的最左结点
（2）如果当前结点没有右子树，而它是其父结点的左子结点，那么其中序遍历的下一个结点就是它的父亲结点
（3）如果当前结点没有右子树，而它是其父节点的右子结点，这种情况下其下一个结点应该是当前结点所在的左子树
    的根，因此我们可以顺着其父结点一直向上遍历，直到找到一个是它父结点的左子结点的结点。
*/
#include <iostream>
using namespace std;

struct TreeLinkNode{
    int val;
    struct TreeLinkNode* left;
    struct TreeLinkNode* right;
    struct TreeLinkNode* next;
    TreeLinkNode(int x=0) : val(x), left(NULL), right(NULL){}
};

TreeLinkNode* GetNext(TreeLinkNode* pNode)
{
    if(pNode == NULL){
        return NULL;
    }
    TreeLinkNode* node = NULL;
    //如果当前结点有右子树，那么其中序遍历的下一个结点是其右子树的最左结点
    if(pNode->right != NULL){
        node = pNode->right;
        while(node->left != NULL){
            node = node->left;
        }
    }else if(pNode->right == NULL && pNode->next != NULL){
        TreeLinkNode* pCurrent = pNode;
        TreeLinkNode* pParent = pNode->next;
        //如果当前结点没有右子树，而它是其父节点的左子结点，那么其下一个结点就是它的父结点
        //如果当前结点没有右子树，而它是其父结点的右子结点，那么其下一个结点是它所在左子树的根
        while(pParent != NULL && pCurrent == pParent->right){
            pCurrent = pParent;
            pParent = pParent->next;
        }
        node = pParent;
    }
    return node;
}

void InOrder(TreeLinkNode* pNode){
    if(pNode == NULL){
        return ;
    }
    InOrder(pNode->left);
    cout << pNode->val <<" ";
    InOrder(pNode->right);
}

int main()
{
    TreeLinkNode tree[10];

    tree[0].val = 4;
    tree[0].left = &tree[1];
    tree[0].right = &tree[2];
    tree[0].next = NULL;

    tree[1].val = 2;
    tree[1].left = &tree[3];
    tree[1].right = &tree[4];
    tree[1].next = &tree[0];

    tree[2].val = 5;
    tree[2].left = NULL;
    tree[2].right = &tree[5];
    tree[2].next = &tree[0];
    
    tree[3].val = 1;
    tree[3].left = &tree[6];
    tree[3].right = NULL;
    tree[3].next = &tree[1];
    
    tree[4].val = 3;
    tree[4].left = NULL;
    tree[4].right = NULL;
    tree[4].next = &tree[1];
    
    tree[5].val = 9;
    tree[5].left = &tree[7];
    tree[5].right = NULL;
    tree[5].next = &tree[2];
    
    tree[6].val = 0;
    tree[6].left = NULL;
    tree[6].right = NULL;
    tree[6].next = &tree[3];
    
    tree[7].val = 7;
    tree[7].left = &tree[8];
    tree[7].right = &tree[9];
    tree[7].next = &tree[5];

    tree[8].val = 6;
    tree[8].left = NULL;
    tree[8].right = NULL;
    tree[8].next = &tree[7];

    tree[9].val = 8;
    tree[9].left = NULL;
    tree[9].right = NULL;
    tree[9].next = &tree[7];
    cout << "the InOrder tree:" << endl;
    InOrder(tree);
    cout << endl;
    cout << tree[6].val << " next : " << GetNext(&tree[6])->val << endl;
    cout << tree[3].val << " next : " << GetNext(&tree[3])->val << endl;
    cout << tree[1].val << " next : " << GetNext(&tree[1])->val << endl;
    cout << tree[4].val << " next : " << GetNext(&tree[4])->val << endl;
    cout << tree[0].val << " next : " << GetNext(&tree[0])->val << endl;
    cout << tree[2].val << " next : " << GetNext(&tree[2])->val << endl;
    cout << tree[8].val << " next : " << GetNext(&tree[8])->val << endl;
    cout << tree[7].val << " next : " << GetNext(&tree[7])->val << endl;
    cout << tree[9].val << " next : " << GetNext(&tree[9])->val << endl;


    return 0;
}