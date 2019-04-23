/*
我们可以用2*1的小矩形横着或者竖着去覆盖更大的矩形。请问用n个2*1的小矩形无重叠地覆盖一个2*n的大矩形，
总共有多少种方法？ 数学模型：f(n)=f(n-1)+f(n-2)
*/
#include <iostream>
using namespace std;

//矩形覆盖
int rectCover(int n)
{
    if(n == 0){
        return 1;
    }else if(n == 1){
        return 1;
    }
    long res = 0;
    long one = 1;
    long two = 1;
    for(int i=2; i<=n; i++){
        res = one + two;
        one = two;
        two = res;
    }
    return res;
}

int main()
{
    int n; //2*1矩形个数
    cout << "Enter n(n>=0):" << endl;
    cin >> n;
    cout << n << " 2*1 rect, " << rectCover(n) << " solution" << endl;  
    return 0;
}