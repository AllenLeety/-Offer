#include <stdio.h>
#include <stdlib.h>

//链表结点
struct ListNode{
    int m_nValue;
    ListNode* m_pNext;
};

//往链表的末尾添加一个结点
void AddToTail(ListNode** pHead, int value)
{
    ListNode* pNew = new ListNode();
    pNew->m_nValue = value;
    pNew->m_pNext = NULL;

    if(*phead == NULL){
        *pHead = pNew;
    }else{
        ListNode* pNode = *pHead;
        while(pNode->m_pNext != NULL){
            pNode = pNode->m_pNext;
        }
        pNode->m_pNext = pNew;
    }
}

//找到第一个含有某值的结点并删除结点
void RemoveNode(ListNode **pHead, int value)
{
    if(pHead == NULL || *pHead == NULL)
        return;

    ListNode* pToBeDeleted = NULL;
    if((*pHead)->m_nValue == value){
        pToBeDeleted = *pHead;
        *pHead = (*pHead)->m_pNext;
    }else{
        ListNode* pNode = *pHead;
        while(pNode->m_pNext != NULL && pNode->m_pNext->m_nValue != value){
            pNode = pNode->m_pNext;
        }
        if(pNode->m_pNext != NULL && pNode->m_pNext->m_nValue == value){
            pToBeDeleted = pNode->m_pNext;
            pNode->m_pNext = pNode->m_pNext->m_pNext;
        }
    }
    if(pToBeDeleted != NULL){
        delete pToBeDeleted;
        pToBeDeleted = NULL;
    }
}

int main()
{

    return 0;
}