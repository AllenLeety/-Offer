#include <iostream>
#include <queue>
using namespace std;

template <typename T>class CStack{
public:
    CStack(void){};
    ~CStack(void){};
    void push(const T& node);
    T pop();

private:
    queue<int> que1;
    queue<int> que2;
};

//插入元素
template <typename T> void CStack<T>::push(const T& element)
{
    if(que1.size() > 0){    //que1不空，则插入que1中
        que1.push(element);
    }else if(que2.size() > 0){  //que2不空，则插入que2中
        que2.push(element);
    }else{  //两个都空，则插入que1中
        que1.push(element);
    }
}

//删除元素
template <typename T> T CStack<T>::pop()
{
    if(que1.size() == 0){   //如果que1为空
        while(que2.size() > 1){
            que1.push(que2.front());
            que2.pop();
        }
        T& data = que2.front();
        que2.pop();
        return data;
    }else{  //如果que2为空
        while(que1.size() > 1){
            que2.push(que1.front());
            que1.pop();
        }
        T& data = que1.front();
        que1.pop();
        return data;
    }
}

int main()
{
    CStack<int> stack;
    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.push(4);

    int len=4;
    while(len>0){
        cout << stack.pop() << " ";
        len--;
    }
    cout << endl;
    return 0;
}