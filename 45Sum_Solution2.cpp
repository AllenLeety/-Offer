/*
求1+2+3+...+n，要求不能使用乘除法、for、while、if、else、switch、case等关键字及条件判断语句（A?B:C）。
*/
/*
递归+短路判断终止
    从n开始递减进程递归的相加运算
    当递归至0时使递归短路即可
*/
#include <iostream>
using namespace std;

int Sum_Solution(int n){
    int res = n;
    res && (res += Sum_Solution(n - 1));
    return res;
}

int main()
{
    int n;
    int sum;

    cout << "Enter N:" << endl;
    cin >> n;

    sum = Sum_Solution(n);
    cout << "sum = " << sum << endl;
    
    return 0;
}