/*
输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是否可能为该栈的弹出顺序。假设压入栈的所有数字均不相等。例如序列1,2,3,4,5是某栈的压入顺序，序列4,5,3,2,1是该压栈序列对应的一个弹出序列，但4,3,5,1,2就不可能是该压栈序列的弹出序列。（注意：这两个序列的长度是相等的）
*/
#include <iostream>
#include <vector>
#include <stack>
#include <iterator>
using namespace std;

bool IsPopOrder(vector<int> pushV, vector<int> popV)
{
    if(pushV.empty() || popV.empty() || pushV.size() != popV.size()){
        return false;
    }
    stack<int> sta;
    int j=0;
    for(int i=0; i<pushV.size(); i++){
        sta.push(pushV[i]);
        while(!sta.empty() && sta.top() == popV[j]){
            sta.pop();
            ++j;
        }
    }
    if(sta.empty()){
        return true;
    }
    return false;
}

int main()
{
    int nPush[] = {1, 2, 3, 4, 5};
    int nPop1[] = {4, 5, 3, 2, 1};
    int nPop2[] = {4, 3, 5, 1, 2};
    vector<int> pushV(nPush, nPush+5);
    vector<int> popV1(nPop1, nPop1+5);
    vector<int> popV2(nPop2, nPop2+5);

    cout << IsPopOrder(pushV, popV1) << endl;
    cout << IsPopOrder(pushV, popV2) << endl;

    return 0;
}