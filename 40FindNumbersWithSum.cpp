/*
输入一个递增排序的数组和一个数字S，在数组中查找两个数，使得他们的和正好是S，如果有多对数字的和等于S，
输出两个数的乘积最小的。
*/
#include <iostream>
#include <vector>
#include <iterator>
using namespace std;

vector<int> FindNumbersWithSum(vector<int> array,int sum)
{
    vector<int> res;
    if(array.size() < 2){
        return res;
    }
    unsigned int start = 0, end = array.size() - 1;
    long curSum;
    while(start < end){
        curSum = array[start] +array[end];
        if(curSum == sum){
            res.push_back(array[start]);
            res.push_back(array[end]);
            break;
        }else if(curSum < sum){
            start++;
        }else{
            end--;
        }
    }
    return res;
}

int main()
{
    int arr[] = {1, 2, 4, 7, 11, 15};
    vector<int> vec(arr, arr+6);
    int sum = 15;
    vector<int> res;
    res = FindNumbersWithSum(vec, sum);
    for(vector<int>::iterator iter=res.begin(); iter != res.end(); iter++){
        cout << *iter << " ";
    }
    cout << endl;
    
    return 0;
}