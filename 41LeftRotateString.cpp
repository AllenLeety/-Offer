/*
汇编语言中有一种移位指令叫做循环左移（ROL），现在有个简单的任务，就是用字符串模拟这个指令的运算结果。
对于一个给定的字符序列S，请你把其循环左移K位后的序列输出。例如，字符序列S=”abcXYZdef”,要求输出循环左
移3位后的结果，即“XYZdefabc”。是不是很简单？OK，搞定它！
*/
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

void Reverse(string &str, int left, int right){
    while(left < right){
        swap(str[left], str[right]);
        left++;
        right--;
    }
}

string LeftRotateString(string str, int n)
{
    if(str.size() == 0){
        return "";
    }
    n %= str.size();
    Reverse(str, 0, n - 1);
    Reverse(str, n, str.size() - 1);
    Reverse(str, 0, str.size() - 1);

    return str;
}

int main()
{
    string str = "abcdefgh";
    for(unsigned int i=0; i<str.size(); i++){
        cout << str[i];
    }
    cout << endl;
    string res = LeftRotateString(str, 3);
    for(unsigned int i=0; i<res.size(); i++){
        cout << res[i];
    }
    cout << endl;
    return 0;
}