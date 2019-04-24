/*
输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有的奇数位于数组的前半部分，
所有的偶数位于数组的后半部分，并保证奇数和奇数，偶数和偶数之间的相对位置不变。
*/
#include <iostream>
#include <vector>
#include <iterator>
using namespace std;

bool isEven(int n)
{
    return (n & 1) == 0;
}
//利用辅助空间实现
void ReOrder(vector<int> &array){
        if(array.size() <= 1){
            return;
        }
        vector<int> temp;
        for(vector<int>::iterator iter = array.begin(); iter != array.end(); ){
            //遇到偶数，就保存到新数组，同时从原数组中删除偶数
            if(isEven(*iter)){
                temp.push_back(*iter);
                iter = array.erase(iter);
            }else{
                iter++;
            }
        }
        //将新数组添加到原来数组
        for(vector<int>::iterator it = temp.begin(); it != temp.end(); it++){
            array.push_back(*it);
        }
    }
//可是实现奇数和偶数分离，但是不会保证奇数和奇数，偶数和偶数之间的相对位置不变
void reOrder(vector<int> &array)
{
    if(array.size() <=1){
        return;
    }
    vector<int>::iterator left = array.begin();
    vector<int>::iterator right = array.end() - 1;
    while(left < right){
        //left向后移动指向偶数
        while(left < right && !isEven(*left)){
            left++;
        }
        //right向前移动指向奇数
        while(left < right && isEven(*right)){
            right--;
        }
        if(left < right){
            int tmp = *left;
            *left = *right;
            *right = tmp;
        }
    }
}

void reorderOddEven(vector<int> &array)
{
   // reOrder(array);
    ReOrder(array);
}

void print(vector<int> &array)
{
    for(vector<int>::iterator it = array.begin(); it != array.end(); it++){
        cout << *it << " ";
    }
    cout << endl;
}

int main()
{
    int a[] = {1, 2, 3, 4, 5, 6, 7};
    vector<int> array(a, a+7);

    cout << "the original array:" << endl;
    print(array);
    reorderOddEven(array);
    cout << "the reorderOddEven array:" << endl;
    print(array);
    return 0;
}