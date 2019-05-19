/*
给一个链表，若其中包含环，请找出该链表的环的入口结点，否则，输出null。
*/
/*
双指针法
第一步 找环中相汇点。
第二部 一个指针指向相汇点，一个指针指向pHead，一步一步移动会再次相遇，相遇点就是环入口
*/
#include <iostream>
using namespace std;

struct ListNode{
    int val;
    struct ListNode* next;
    //ListNode(int x) : val(x), next(NULL){}
};

//找相遇的结点
ListNode* getMeetingNode(ListNode* pHead){
    ListNode* pSlow = pHead;
    ListNode* pFast = pHead;
    //当没有到达链表结尾，则继续前进
    while(pSlow != NULL && pFast->next != NULL){
        pSlow = pSlow->next;
        pFast = pFast->next->next;
        if(pSlow == pFast){
            return pSlow;
        }
    }
    return NULL;
}

ListNode* EntryNodeOfLoop(ListNode* pHead){
    if(pHead == NULL){
        return NULL;
    }
    ListNode* meetingNode = getMeetingNode(pHead);
    if(meetingNode == NULL){
        return NULL;
    }
    ListNode* p1 = meetingNode;
    ListNode* p2 = pHead;
    while(p1 != p2){//p1和p2以相同的速度向前移动，当p2指向环的入口结点时，p1已经围绕环走了n圈又回到了入口点
        p1 = p1->next;
        p2 = p2->next;
    }
    //返回入口点
    return p1;
    
    return NULL;
}

int main()
{
    ListNode list[6];

    list[0].val = 1;
    list[0].next = &list[1];

    list[1].val = 2;
    list[1].next = &list[2];

    list[2].val = 3;
    list[2].next = &list[3];

    list[3].val = 4;
    list[3].next = &list[4];

    list[4].val = 5;
    list[4].next = &list[5];

    list[5].val = 6;
    list[5].next = &list[2];

    cout << EntryNodeOfLoop(list)->val << endl;

    return 0;
}