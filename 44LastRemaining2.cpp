/*
每年六一儿童节,牛客都会准备一些小礼物去看望孤儿院的小朋友,今年亦是如此。HF作为牛客的资深元老,自然也准备了
一些小游戏。其中,有个游戏是这样的:首先,让小朋友们围成一个大圈。然后,他随机指定一个数m,让编号为0的小朋友开
始报数。每次喊到m-1的那个小朋友要出列唱首歌,然后可以在礼品箱中任意的挑选礼物,并且不再回到圈中,从他的下一
个小朋友开始,继续0...m-1报数....这样下去....直到剩下最后一个小朋友,可以不用表演,并且拿到牛客名贵的“名侦
探柯南”典藏版(名额有限哦!!^_^)。请你试着想下,哪个小朋友会得到这份礼品呢？(注：小朋友的编号是从0到n-1)
*/
/*
f[1] = 0;               n=1
f[i] = (f[i-1]+m) % i;  n>1
*/
#include <iostream>
using namespace std;

int LastRemaining_Solution(int n, int m)
{
    if(n < 1 || m < 1){
        return -1;
    }
    int last = 0;
    for(int i=2; i<=n; i++){
        last = (last + m) % i;
    }
    return last;
}

int main()
{
    cout << LastRemaining_Solution(9, 3) << endl;
    cout << LastRemaining_Solution(5, 3) << endl;
    return 0;
}