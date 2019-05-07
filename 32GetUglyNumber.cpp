/*
把只包含质因子2、3和5的数称作丑数（Ugly Number）。例如6、8都是丑数，但14不是，因为它包含质因子7。 
习惯上我们把1当做是第一个丑数。求按从小到大的顺序的第N个丑数。
*/
#include <iostream>

using namespace std;

bool IsUglyNumber(int num)
{
    while(num % 2 == 0){
        num /= 2;
    }
    while(num % 3 == 0){
        num /= 3;
    }
    while(num % 5 == 0){
        num /= 5;
    }
    return (num == 1) ? true : false;
}

int GetUglyNumber_Solution(int index)
{
    if(index <= 0){
        return 0;
    }
    int count = 0;
    int num = 0;
    while(count < index){
        ++num;
        if(IsUglyNumber(num)){
            count++;    //丑数个数
        }
    }
    return num;
}

int main()
{
    int index;
    cout << "Enter index:" << endl;
    cin >> index;
    cout << "the " << index << "ugly number:" << endl;
    cout << GetUglyNumber_Solution(index) << endl;
    return 0;
}