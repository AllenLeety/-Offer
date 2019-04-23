/*
一只青蛙一次可以跳上1级台阶，也可以跳上2级……它也可以跳上n级。求该青蛙跳上一个n级的台阶总共有多少种跳法。
数学模型：f(n)= 2^(n-1)
*/
#include <iostream>
using namespace std;

//n阶跳
int jumpFloorN(int n)
{
    if(n <= 2){
        return n;
    }
    long res = 0;
    long two = 2;
    for(int i=3; i<=n; i++){
        res = 2 * two; //f(n) = 2^(n-1)
        two = res;
    }
    return res;
}

int main()
{
    int n;
    cout << "Enter n(n>0):" << endl;
    cin >> n;
    cout << n << " floor, jump solution " << jumpFloorN(n) << endl;5
    
    return 0;
}