#include <iostream>
using namespace std;

struct ListNode{
    int val;
    struct ListNode* pNext;
   // ListNode* pNext;
};

void deleteNode(ListNode** pHead, ListNode* pToBeDeleted)
{
    if(pToBeDeleted == NULL){
        return;
    }

    //要删除的结点不是尾结点
    if(pToBeDeleted->pNext != NULL){
        ListNode* pNode = pToBeDeleted->pNext;
        pToBeDeleted->val = pNode->val;
        pToBeDeleted->pNext = pNode->pNext;
        delete pNode;
        pNode = NULL;
    }else if(*pHead == pToBeDeleted){   //要删除的结点是头结点
        delete pToBeDeleted;
        pToBeDeleted = NULL;
        *pHead = NULL;
    }else{  //要删除的链表有多个结点，且要删除的结点是尾结点
        ListNode *pNode = *pHead;
        while(pNode->pNext != pToBeDeleted){
            pNode = pNode->pNext;
        }
        pNode->pNext = NULL;
        delete pToBeDeleted;
        pToBeDeleted = NULL;

    }
}

void addToTail(ListNode **pHead, int value)
{
    ListNode* pNew = new ListNode();
    pNew->val = value;
    pNew->pNext = NULL;

    if(*pHead == NULL){
        *pHead = pNew;
    }else{
        ListNode* pNode = *pHead;
        while(pNode->pNext != NULL){
            pNode = pNode->pNext;
        }
        pNode->pNext = pNew;
    }
}

void print(ListNode** pHead)
{
    ListNode *pNode = *pHead;
    if(*pHead == NULL){
        return;
    }
    while(pNode != NULL){
        cout << pNode->val << " ";
        pNode = pNode->pNext;
    }
    cout << endl;
}

int main()
{
    ListNode *pNode = NULL;
    addToTail(&pNode, 1);
    addToTail(&pNode, 2);
    addToTail(&pNode, 3);
    addToTail(&pNode, 4);
    cout << "the original list:" << endl;
    print(&pNode);
    deleteNode(&pNode, pNode->pNext);
    cout << "the delete list:" << endl;
    print(&pNode);

    return 0;
}