/*
输入一个复杂链表（每个节点中有节点值，以及两个指针，一个指向下一个节点，
一个特殊指针指向任意一个节点），返回结果为复制后复杂链表的head。
（注意，输出结果中请不要返回参数中的节点引用，否则判题程序会直接返回空）
*/
#include <iostream>
using namespace std;

struct RandomListNode{
    int label;
    struct RandomListNode *next, *random; 
};

class Solution{
public:
//首先复制原链表的普通指针域，一次遍历即可完成，将新的节点链接在原来节点的末尾
    void cloneNode(RandomListNode* pHead)
    {
        RandomListNode* pNode = pHead;
        while(pNode != NULL){
            RandomListNode* pCloned = new RandomListNode();
            pCloned->label = pNode->label;
            pCloned->next = pNode->next;
            pCloned->random = NULL;

            pNode->next = pCloned;
            pNode = pCloned->next;
        }
    }

//接下来复制随机指针域
//原来结点的下一个位置就是其对应的新节点
    void connectRandomNodes(RandomListNode* pHead)
    {
        RandomListNode* pNode = pHead;
        while(pNode != NULL){
            RandomListNode* pCloned = pNode->next;
            if(pNode->random != NULL){
                pCloned->random = pNode->random->next;
                pNode = pCloned->next;
            }
        }
    }

//最后将连接在一起的新旧两个链表拆分开，更新各链表的next指针
    RandomListNode* ReconnectNode(RandomListNode* pHead)
    {
        RandomListNode* pNode = pHead;
        RandomListNode* pCloneHead = NULL;
        RandomListNode* pCloneNode = NULL;
        if(pNode != NULL){
            pCloneHead = pCloneNode = pNode->next;
            pNode->next = pCloneNode->next;
            pNode = pNode->next;
        }
        while(pNode != NULL){
            pCloneNode->next = pNode->next;
            pCloneNode = pCloneNode->next;
            pNode->next = pCloneNode->next;
            pNode = pNode->next;
        }
        return pCloneHead;
    }

    RandomListNode* Clone(RandomListNode* pHead)
    {
        if(pHead == NULL){
            return NULL;
        }
        cloneNode(pHead);
        connectRandomNodes(pHead);
        return ReconnectNode(pHead);
    }
};

int main()
{
    RandomListNode list[4];
    list[0].label = 1;
    list[0].next = &list[1];
    list[1].label = 1;
    list[1].next = &list[2];
    list[2].label = 2;
    list[2].next = &list[3];
    list[3].label = 2;
    list[3].next = NULL;
    Solution solu;
    RandomListNode* head = solu.Clone(list);
    while(head != NULL){
        cout << head->label << " ";
        head = head->next;
    }
    cout << endl;

    return 0;
}