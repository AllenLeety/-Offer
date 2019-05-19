/*
在一个排序的链表中，存在重复的结点，请删除该链表中重复的结点，重复的结点不保留，返回链表头指针。 
例如，链表1->2->3->3->4->4->5 处理后为 1->2->5
*/
#include <iostream>
using namespace std;

struct ListNode{
    int val;
    struct ListNode* next;
    //ListNode(int x) : val(x), next(NULL){}
};

ListNode* deleteDuplication(ListNode* pHead){
    //设置一个temp作为头指针，这样就无需单独考虑第一个元素
    ListNode* first = new ListNode();
    first->val = -1;
    first->next = pHead;
    ListNode* p = pHead;
    ListNode* last = first;

    while(p != NULL && p->next != NULL){
        //如果有重复元素
        if(p->val == p->next->val){
            int value = p->val;
            while(p != NULL && p->val == value){
                p = p->next;
            }
            last->next = p;
        }else{
            last = p;
            p = p->next;
        }
    }
    return first->next;
}

int main()
{
    ListNode list[7];
    ListNode* pHead;

    list[0].val = 1;
    list[0].next = &list[1];
    list[1].val = 2;
    list[1].next = &list[2];
    list[2].val = 3;
    list[2].next = &list[3];
    list[3].val = 3;
    list[3].next = &list[4];
    list[4].val = 4;
    list[4].next = &list[5];
    list[5].val = 4;
    list[5].next = &list[6];
    list[6].val = 5;
    list[6].next = NULL;
    cout << "the original list:" << endl;
    ListNode *node = &list[0];
    while(node != NULL){
        cout << node->val << " ";
        node = node->next;
    }
    cout << endl;

    pHead = deleteDuplication(list);
    cout << "the delete duplication list:" << endl;
    while(pHead != NULL){
        cout << pHead->val << " ";
        pHead = pHead->next;
    }
    cout << endl;

    return 0;
}