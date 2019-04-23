#include <iostream>
#include <stack>
using namespace std;

class Solution{
public:
    void push(int node)
    {
        stack1.push(node);
    }

    int pop()
    {
        int tmp;
        if(stack2.empty()){
            while(!stack1.empty()){
                tmp = stack1.top();
                stack1.pop();
                stack2.push(tmp);
            }
        }
        tmp = stack2.top();
        stack2.pop();

        return tmp;
    }

    bool empty()
    {
        return (stack1.empty() == true && stack2.empty() == true);
    }

private:
    stack<int> stack1;
    stack<int> stack2;
};


int main()
{
    Solution solu;
    solu.push(1);
    solu.push(2);
    solu.push(3);
    solu.push(4);
    //int node;
    while(!solu.empty()){
        cout << solu.pop() << " ";
    }
    cout << endl;

    return 0;
}