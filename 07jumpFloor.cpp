/*
一只青蛙一次可以跳上1级台阶，也可以跳上2级。求该青蛙跳上一个n级的台阶总共有多少种跳法
（先后次序不同算不同的结果）。 数学模型：f(n)=f(n-1)+f(n-2)
*/
#include <iostream>
using namespace std;

//跳台阶
int jumpFloor(int n)
{
    if(n<=2){
        return n;
    }
    long one = 1;
    long two = 2;
    long res = 0;
    for(int i=3; i<=n; i++){
        res = one + two;
        one = two;
        two = res;
    }
    return res;
}

int main()
{
    int n;
    cout << "Enter n(n>=1):" << endl;
    cin >> n;
    cout << n <<" floor, jump solution " << jumpFloor(n) << endl;
    return 0;
}