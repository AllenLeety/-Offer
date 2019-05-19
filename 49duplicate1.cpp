/*
在一个长度为n的数组里的所有数字都在0到n-1的范围内。 数组中某些数字是重复的，但不知道有几个数字是重复的。
也不知道每个数字重复几次。请找出数组中任意一个重复的数字。 例如，如果输入长度为7的数组{2,3,1,0,2,5,3}，
那么对应的输出是第一个重复的数字2。
*/
//排序
#include <iostream>
#include <algorithm>
using namespace std;

bool CheckValid(int numbers[], int length){
    if(numbers == NULL || length <= 0){
        return false;
    }
    for(int i=0; i<length; i++){
        if(numbers[i] > length - 1){
            return false;
        }
    }
    return true;
}

bool duplicate(int numbers[], int length, int* duplication){
    *duplication = -1;
    bool isDup = false;
    if(CheckValid(numbers, length) == false){
        return false;
    }
    sort(numbers, numbers+length);
    for(int i=1; i<length; i++){
        if(numbers[i] == numbers[i-1]){
            *duplication = numbers[i];
            isDup = true;
            break;
        }
    }
    return isDup;
}

int main()
{
    int arr[] = {2, 3, 1, 0, 2, 5, 3};
    int res;
    if(duplicate(arr, 7, &res) == true){
        cout << res << endl;
    }
    return 0;
}