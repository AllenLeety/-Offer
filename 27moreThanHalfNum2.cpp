/*
数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。例如输入一个长度为9的数组
{1,2,3,2,2,2,5,4,2}。由于数字2在数组中出现了5次，超过数组长度的一半，因此输出2。如果不存在输出0。
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*根据数组特点找出O(n)算法*/
int MoreThanHalfNum_Solution(vector<int> numbers)
{
    if(numbers.size() == 0){
        return 0;
    }else if(numbers.size() == 1){
        return numbers[0];
    }
    unsigned int count = 1;
    int num = numbers[0];
    for(unsigned int i=1; i<numbers.size(); i++){
        if(numbers[i] == num){
            count++;    //友军，计数器加1
        }else{
            count--;    //敌军，计数器减1
        }
        if(count == 0){
            count = 1;
            num = numbers[i];   //重新设置
        }
    }
    //再次循环判断num是否大于数组一半
    for(unsigned int i=0; i<numbers.size(); i++){
        if(numbers[i] == num){
            count++;
        }
    }
    if(count*2 <= numbers.size() ){
        return num;
    }else{
        return 0;
    }
}

int main()
{
    int arr1[] = {1, 2, 3, 2, 2, 2, 5, 4, 2};
    //int arr[] = {5, 5, 2, 2, 3, 3, 5, 5, 5};
    int arr2[] = {4, 1, 2, 4, 2, 4};
    vector<int> vec1(arr1, arr1+9);
    cout << MoreThanHalfNum_Solution(vec1) << endl;
    vector<int> vec2(arr2, arr2+6);
    cout << MoreThanHalfNum_Solution(vec2) << endl;

    return 0;
}