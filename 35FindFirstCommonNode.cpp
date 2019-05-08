/*输入两个链表，找出它们的第一个公共结点。*/
#include <iostream>
#include <stack>
using namespace std;

struct ListNode{
    int val;
    struct ListNode* next;
  //  ListNode(int x) : val(x), next(NULL){}
};

ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2)
{
    stack<ListNode*> stack1;
    stack<ListNode*> stack2;
    ListNode *phead1 = pHead1;
    ListNode *phead2 = pHead2;
    //依次进栈
    while(phead1 != NULL){
        stack1.push(phead1);
        phead1 = phead1->next;
    }
    while(phead2 != NULL){
        stack2.push(phead2);
        phead2 = phead2->next;
    }
    //弹出元素
    while(!stack1.empty() && !stack2.empty()){
        phead1 = stack1.top();
        phead2 = stack2.top();
        //不相同的元素就是合并的前一个结点
        if(phead1 != phead2){
            break;
        }
        stack1.pop();
        stack2.pop();
    }
    //不相同元素的下一个结点就是共同结点
    if(phead1 != phead2){
        return phead1->next;
    }else{
        return NULL;
    }
}

int main()
{
    ListNode common[2];
    common[0].val = 6;
    common[0].next = &common[1];
    common[1].val = 7;
    common[1].next = NULL;

    ListNode left[3];
    left[0].val = 1;
    left[0].next = &left[1];
    left[1].val = 2;
    left[1].next = &left[2];
    left[2].val = 3;
    left[2].next = &common[0];

    ListNode right[2];
    right[0].val = 4;
    right[0].next = &right[1];
    right[1].val = 5;
    right[1].next = &common[0];

    ListNode *node = FindFirstCommonNode(left, right);
    while(node != NULL)
    {
        cout <<node->val <<" ";
        node = node->next;
    }
    cout <<endl;

    return 0;
}