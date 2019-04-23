#include <iostream>
using namespace std;

//斐波那契数列
int fibonacci(int n)
{
    if(n < 2){
        return n;
    }
    long fibN = 0;
    long fibOne = 0;
    long fibTwo = 1;
    cout << "0 1 ";
    for(int i=2; i<=n; i++){
        fibN = fibOne + fibTwo;
        fibOne = fibTwo;
        fibTwo = fibN;
        cout << fibN << " ";
    }
    cout << endl;
    return fibN;
}

int main()
{
    int num;
    cout << "Enter n(n>=0):" << endl;
    cin >> num;
    cout << fibonacci(num) << endl;;
    return 0;
}