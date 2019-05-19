/*
求1+2+3+...+n，要求不能使用乘除法、for、while、if、else、switch、case等关键字及条件判断语句（A?B:C）。
*/
/*
用函数指针求解
用函数指针实现选择函数
*/
#include <iostream>
using namespace std;

typedef int (*func)(int);

//递归终止函数
int Terminator(int n){
    return 0;
}

//选择函数进行递归
int Sum_Solution(int n){
    static func f[2] = { Terminator, Sum_Solution};
    return n+f[!!n](n - 1); //把一个值n转换为布尔类型，对n连续做两次反运算，即!!n。那么非零的n转换为true，0转换为false
}

int main()
{
    cout << Sum_Solution(3) << endl;
    cout << Sum_Solution(5) << endl;
    return 0;
}