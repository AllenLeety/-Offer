/*
求1+2+3+...+n，要求不能使用乘除法、for、while、if、else、switch、case等关键字及条件判断语句（A?B:C）。
*/
/*
C++里面类对象里面的静态计数器的设计，静态的count可以在构造函数中进行累加，从而维护出类对象的个数。
采用相同的思路，在类的构造函数里面进行计数器的累加和求和操作，构造出N个对象即可完成所需操作。
*/
#include <iostream>
using namespace std;

class Temp
{
public:
    Temp(){
        ++N;
        Sum += N;
    }
    static void Reset(){
        N = 0;
        Sum = 0;
    }
    static unsigned int GetSum(){
        return Sum;
    }
private:
    static unsigned int N;
    static unsigned int Sum;
};

unsigned int Temp::N = 0;
unsigned int Temp::Sum = 0;

int Sum_Solution(int n){
    Temp::Reset();
    Temp *a = new Temp[n];
    delete []a;
    a = NULL;
    return Temp::GetSum();
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