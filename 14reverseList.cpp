/*输入一个链表，反转链表后，输出新链表的表头。*/
#include <iostream>
using namespace std;

struct ListNode{
    int val;
    struct ListNode* next;
};

void addToTail(ListNode** pHead, int value)
{
    ListNode *pNew = new ListNode();
    pNew->val = value;
    pNew->next = NULL;

    if(*pHead == NULL){
        *pHead = pNew;
    }else{
        ListNode *pNode = *pHead;
        while(pNode->next != NULL){
            pNode = pNode->next;
        }
        pNode->next = pNew;
    }
}

void print(ListNode **pHead)
{
    ListNode *pNode = *pHead;
    while(pNode != NULL){
        cout << pNode->val << " ";
        pNode = pNode->next;
    }
    cout << endl;
}

//反转链表
ListNode* reverseList(ListNode** pHead)
{
    ListNode* pReverseHead = NULL;
    ListNode* pPre = NULL;
    ListNode* pNode = *pHead;

    while(pNode != NULL){
        ListNode* pNext = pNode->next;
        if(pNext == NULL){
            pReverseHead = pNode;
        }
        pNode->next = pPre;
        pPre = pNode;
        pNode = pNext;
    }
    return pReverseHead;
}

int main()
{
    ListNode* pNode = NULL;
    ListNode* pReverseHead = NULL;

    addToTail(&pNode, 1);
    addToTail(&pNode, 2);
    addToTail(&pNode, 3);
    addToTail(&pNode, 4);
    addToTail(&pNode, 5);
    addToTail(&pNode, 6);
    addToTail(&pNode, 7);
    cout << "the original list:" << endl;
    print(&pNode);
    //反转链表
    pReverseHead = reverseList(&pNode);
    cout << "the reverse list:" << endl;
    print(&pReverseHead);
    return 0;
}