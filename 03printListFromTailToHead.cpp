#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct ListNode{
    int val;
    struct ListNode* next;
    ListNode(int x):val(x), next(NULL){}
};

//往链表的末尾添加一个结点
void AddToTail(ListNode** head, int value)
{
    ListNode* pNew = new ListNode();
    pNew->val = value;
    pNew->next = NULL;

    if(*head == NULL){
        *head = pNew;
    }else{
        ListNode *Node = *head;
        while(Node->next != NULL){
            Node = Node->next;
        }
        Node->next = pNew;
    }
}

//输入一个链表，按链表值从尾到头的顺序返回一个ArrayList
vector<int> printListFromTailToHead(ListNode* head) {
    stack<int> nodeVal;
    vector<int> vec;
    ListNode* pNode = head;
    while(pNode != NULL){
        nodeVal.push(pNode->val);
        pNode = pNode->next;
    }
    while(!nodeVal.empty()){
        vec.push_back(nodeVal.top());
        nodeVal.pop();
    }
    return vec;
}

int main()
{
    std::vector<int> vec;
    ListNode *head;
    //int x;
    AddToTail(*head, 1);
    AddToTail(*head, 2);
    AddToTail(*head, 3);
    AddToTail(*head, 4);
    vec = printListFromTailToHead(head);

    return 0;
}