/*
在一个长度为n的数组里的所有数字都在0到n-1的范围内。 数组中某些数字是重复的，但不知道有几个数字是重复的。
也不知道每个数字重复几次。请找出数组中任意一个重复的数字。 例如，如果输入长度为7的数组{2,3,1,0,2,5,3}，
那么对应的输出是第一个重复的数字2。
*/
#include <iostream>
#include <cstring>
using namespace std;

// Parameters:
//numbers:     an array of integers
//length:      the length of array numbers
//duplication: (Output) the duplicated number in the array number
//Return value: true if the input is valid, and there are some duplications in the array number
//                     otherwise false
bool CheckValid(int numbers[], int length){
    if(numbers == NULL || length <= 0){
        return false;
    }
    for(int i=0; i<length; i++){
        if(numbers[i] < 0 || numbers[i] > length - 1){
            return false;
        }
    }
    return true;
}
//利用哈希表的思想
bool duplicate(int numbers[], int length, int* duplication){
    *duplication = -1;
    if(CheckValid(numbers, length) == false){
        return false;
    }
    int count[length];
    memset(count, 0, sizeof(count));
    for(int i=0; i<length; i++){
        if(count[numbers[i]] != 0){
            *duplication = numbers[i];
            return true;
        }else{
            count[numbers[i]] = 1;
        }
    }
    return false;
}

int main()
{
    int res;
    int arr[] = {2, 3, 1, 0, 2, 5, 3};
    if(duplicate(arr, 7, &res) == true){
        cout << res << endl;
    }
    return 0;
}