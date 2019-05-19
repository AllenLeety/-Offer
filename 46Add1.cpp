/*
写一个函数，求两个整数之和，要求在函数体内不得使用+、-、*、/四则运算符号。
*/
#include <iostream>
using namespace std;

int Add(int num1, int num2){
    int tmp;
    while(num2 != 0){
        tmp = num1 ^ num2;          //计算不带进位的情况
        num2 = (num1 & num2) << 1;  //计算带进位的情况
        num1 = tmp;
    }
    return num1;
}

int main()
{
    int num1, num2, sum;
    cout << "Enter numbers:" << endl;
    cout << "num1 = ";
    cin >> num1;
    cout << "num2 = ";
    cin >> num2;
    sum = Add(num1, num2);
    cout << "sum = " << sum << endl;
    return 0;
}