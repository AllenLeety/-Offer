/*
LL今天心情特别好,因为他去买了一副扑克牌,发现里面居然有2个大王,2个小王(一副牌原本是54张^_^)...他随机从中
抽出了5张牌,想测测自己的手气,看看能不能抽到顺子,如果抽到的话,他决定去买体育彩票,嘿嘿！！“红心A,黑桃3,小
王,大王,方片5”,“Oh My God!”不是顺子.....LL不高兴了,他想了想,决定大\小 王可以看成任何数字,并且A看作1,
J为11,Q为12,K为13。上面的5张牌就可以变成“1,2,3,4,5”(大小王分别看作2和4),“So Lucky!”。LL决定去买体育彩
票啦。 现在,要求你使用这幅牌模拟上面的过程,然后告诉我们LL的运气如何， 如果牌能组成顺子就输出true，否则就
输出false。为了方便起见,你可以认为大小王是0。
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool IsContinuous( vector<int> numbers )
{
    if(numbers.size() == 0){
        return false;
    }
    //排序
    sort(numbers.begin(), numbers.end());
    //统计零的个数
    int numberOfZero = 0;
    while(numbers[numberOfZero] == 0){
        numberOfZero++;
    }
    //判断看0能不能填补两个数之间的空缺
    for(unsigned int i=numberOfZero+1; i<numbers.size(); i++){
        //如果数组中的非0数字重复出现，则该数组不是连续的
        if(numbers[i] == numbers[i - 1]){
            return false;
        }else{
            numberOfZero -= (numbers[i] - numbers[i-1] - 1);
        }
    }
    if(numberOfZero >= 0){
        return true;
    }else{
        return false;
    }
}

int main()
{
    int arr1[] = {1, 4, 6, 5, 2};
    int arr2[] = {3, 5, 1, 0, 4};
    vector<int> vec1(arr1, arr1+5);
    vector<int> vec2(arr2, arr2+5);
    cout << IsContinuous(vec1) << endl;
    cout << IsContinuous(vec2) << endl;
    return 0;
}