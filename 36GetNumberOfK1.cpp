/*
统计一个数字在排序数组中出现的次数。例如输入排序数组{1,2,3,3,3,3,4,5}和数字3，由于3在这个
数组中出现了4次，因此输出4.
*/
#include <iostream>
#include <vector>
using namespace std;

int GetNumberOfK(vector<int> data ,int k)
{
    if(data.size() == 0){
        return 0;
    }
    int count = 0;
    for(unsigned int i=0; i<data.size(); i++){
        if(data[i] == k){
            count++;
        }
    }
    return count;
}

int main()
{
    int arr[] = {1, 2, 3, 3, 3, 3, 4, 5};
    vector<int> vec(arr, arr+8);
    cout << GetNumberOfK(vec, 3) << endl;

    return 0;
}