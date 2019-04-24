/*
输入两个递增排序的链表，合并这两个链表并使新链表中结点仍然按照递增排序的。
*/
#include <iostream>
using namespace std;

struct ListNode{
	int val;
	struct ListNode* pNext;
};

void addToTail(ListNode** pHead, int value)
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

void print(ListNode **pHead)
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

ListNode* Merge(ListNode *pHead1, ListNode *pHead2)
{
	ListNode* pMergeHead = NULL;
    if(pHead1 == NULL){
        return pHead2;
    }else if(pHead2 == NULL){
        return pHead1;
    }else{
        if(pHead1->val < pHead2->val){
            pMergeHead = pHead1;
            pMergeHead->pNext = Merge(pHead1->pNext, pHead2);
        }else{
            pMergeHead = pHead2;
            pMergeHead->pNext = Merge(pHead1, pHead2->pNext);
        }
        return pMergeHead;
    }
}


int main()
{
	ListNode* pNode1 = NULL;
    ListNode* pNode2 = NULL;
    ListNode* pNewHead = NULL;

    addToTail(&pNode1, 1);
    addToTail(&pNode1, 3);
    addToTail(&pNode1, 5);
    addToTail(&pNode1, 7);
    cout << "list 1:" << endl;
    print(&pNode1);

    addToTail(&pNode2, 2);
    addToTail(&pNode2, 4);
    addToTail(&pNode2, 6);
    cout << "list 2:" << endl;
    print(&pNode2);

    cout << "merge list:" << endl;
    pNewHead = Merge(pNode1, pNode2);
    print(&pNewHead);

	return 0;
}