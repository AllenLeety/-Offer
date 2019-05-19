/*
给一个链表，若其中包含环，请找出该链表的环的入口结点，否则，输出null。
*/
/*
断链法
时间复杂度为O(n),两个指针，一个在前面，另一个紧邻着这个指针，在后面。两个指针同时向前移动，每移动一次，前面
的指针的next指向NULL。也就是说：访问过的结点都断开，最后到达的那个结点一定是尾结点的下一个，也就是循环的第
一个。这时候已经是第二次访问循环的第一节点了，第一次访问的时候我们已经让它指向了NULL，所以到这结束。
这种方法修改了链表的指向
*/
#include <iostream>
using namespace std;

struct ListNode{
    int val;
    struct ListNode* next;
};

ListNode* EntryNodeOfLoop(ListNode* pHead){
    if(pHead == NULL || pHead->next == NULL){
        return NULL;
    }
    ListNode* pre = pHead;
    ListNode* cur = pHead->next;
    while(cur != NULL){
        pre->next = NULL;
        pre = cur;
        cur = cur->next;
    }
    return pre;
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