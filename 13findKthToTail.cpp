/*输入一个链表，输出该链表中倒数第k个结点。*/
#include <iostream>
using namespace std;

struct ListNode{
    int val;
    struct ListNode* pNext;
};

ListNode* findKthToTail(ListNode *pHead, unsigned int k)
{
    if(pHead == NULL || k == 0){
        return NULL;
    }
    ListNode* p1 = pHead;
    ListNode* p2 = NULL;
    for(unsigned int i=0; i<k; i++){
        if(p1->pNext != NULL){
            p1 = p1->pNext;
        }else{
            return NULL;
        }
    }
    p2 = pHead;
    while(p1/*->pNext*/ != NULL){
        p2 = p2->pNext;
        p1 = p1->pNext;
    }
    return p2;
}

void addToTail(ListNode** pHead, int value)
{
    ListNode *pNew = new ListNode();
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

void print(ListNode **pHead)
{
    ListNode *pNode = *pHead;
    while(pNode != NULL){
        cout << pNode->val << " ";
        pNode = pNode->pNext;
    }
    cout << endl;
}

int main()
{
    ListNode* pNode = NULL;
    int k;
    addToTail(&pNode, 1);
    addToTail(&pNode, 2);
    addToTail(&pNode, 3);
    addToTail(&pNode, 4);
    addToTail(&pNode, 5);
    addToTail(&pNode, 6);
    addToTail(&pNode, 7);
    cout << "the list is:" << endl;
    print(&pNode);
    cout << "Enter k:" << endl;
    cin >> k;
    cout << "the " << k << "th number is " << findKthToTail(pNode, k)->val << endl;

    return 0;
}