/*
求出1~13的整数中1出现的次数,并算出100~1300的整数中1出现的次数？为此他特别数了一下1~13中包含1的数字有
1、10、11、12、13因此共出现6次,是对于后面问题他就没辙了。ACMer希望你们帮帮他,并把问题更加普遍化,可以
很快的求出任意非负整数区间中1出现的次数（从1 到 n 中1出现的次数）。
*/
#include <iostream>
using namespace std;
/*时间复杂度O(logn)*/
int NumberOf1Between1AndN_Solution(int n)
{
    long count = 0; //1出现次数
    long i = 1; //位数
    long current = 0, before = 0, after = 0;

    while((n/i) != 0){
        before = n / (i * 10);  //高位
        current = (n / i) % 10; //当前位
        after = n - (n / i) * i;//低位
        if(current > 1){
            //如果current大于1，则出现1的次数为其高位before的数字加1乘以当前位数
            count += (before + 1) * i;
        }else if(current == 0){
            //如果current等于0，则出现1的次数为其高位before的数字乘以当前位数
            count += before * i;
        }else if(current == 1){
            //如果current等于1，则出现1的次数为其高位before的数字乘以当前位数，加上低位数字再加1
            count += before * i + after + 1;
        }
        i *= 10;
    }
    return count;
}

int main()
{
    cout << NumberOf1Between1AndN_Solution(12) << endl;
    cout << NumberOf1Between1AndN_Solution(123) << endl;
    cout << NumberOf1Between1AndN_Solution(113) << endl;
    return 0;
}