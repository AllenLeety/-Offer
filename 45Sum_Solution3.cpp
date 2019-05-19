/*
求1+2+3+...+n，要求不能使用乘除法、for、while、if、else、switch、case等关键字及条件判断语句（A?B:C）。
*/
/*
位运算计算 1+2+3+...+n=n(n+1)/2 ---> Multi(n, n+1) >> 1
a*b运算在计算机内部其实是通过移位和加法来完成的
int Multi(int a, int b){
    int res = 0;
    while(a != 0){
        if((a & 1) != 0){
            res += b;
        }
        a >> 1;
        b << 1;
    }
    return res;
}
因为乘法函数中仍然有循环和判断，所以循环用递归来代替，分支用短路运算来代替
*/
#include <iostream>
using namespace std;

int res;
int MultiRecursion(int a, int b){
    a && MultiRecursion(a >> 1, b << 1);    //递归的进行运算
    (a & 1) && (res += b);  //短路
    return res;
}

int Sum_Solution(int n){
    res = 0;
    return (MultiRecursion(n, n+1) >> 1);
}

int main()
{
    cout << Sum_Solution(3) << endl;
    cout << Sum_Solution(5) << endl;
    return 0;
}