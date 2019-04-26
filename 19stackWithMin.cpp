/*
定义栈的数据结构，请在该类型中实现一个能够得到栈中所含最小元素的min函数
（时间复杂度为O(1)）
*/
#include <iostream>
#include <stack>
#include <iterator>
#include <cassert>
using namespace std;

stack<int> m_data;  //数据栈
stack<int> m_min;   //存储每次栈中最小值的栈信息

void push(int value) {
    m_data.push(value);
    if(m_min.size()==0 || (value < m_min.top())){
        m_min.push(value);
    }else{
        m_min.push(m_min.top());
    }
}

void pop() {
    assert(m_data.size()>0 && m_min.size()>0);
    m_data.pop();
    m_min.pop();
}

int top() {
    assert(m_data.size() > 0 && m_min.size() > 0);
    cout << m_data.top() << " ";
    return m_data.top();
}

int min() {
    if(m_min.empty()){
        return 0;
    }
    cout << m_min.top() << " ";
    return m_min.top();
}

int main()
{
    int num;

    cout << "Enter num:" << endl;
    for(int i=0; i<5; i++){
        cin>>num;
        push(num);
    }
    cout << "m_min:" << endl;
    while(!m_data.empty()){
        //top();
        min();
        pop();
    }
    cout << endl;

    return 0;
}