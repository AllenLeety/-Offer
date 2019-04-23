/*
输入一个整数，输出该数二进制表示中1的个数。其中负数用补码表示。
思路：把一个整数减去1，再和原来整数做与运算，会把该整数最右边一个1变成0
*/
#include <iostream>
using namespace std;

int numberOf1(int n)
{
    int count = 0;
    while(n){
        count++;
        n = (n - 1) & n;
    }
    return count;
}

int main()
{
    int n;

    cout << "Enter n:" << endl;
    cin >> n;
    cout << n << " has " << numberOf1(n) << " number of 1!" << endl;
    return 0;
}