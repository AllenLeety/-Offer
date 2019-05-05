/*
输入n个整数，找出其中最小的K个数。例如输入4,5,1,6,2,7,3,8这8个数字，则最小的4个数字是1,2,3,4,。
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;

int Partition(vector<int> &input, int left, int right)
{
    /*int i = left, j = right;
    int pivotIndex = right, pivot = input[pivotIndex];
    while(i < j){
        while(i<j && input[i] < pivot){
            i++;
        }
        swap(input[i], input[j]);
        while(i<j && input[j] >= pivot){
            j--;
        }
        swap(input[i], input[i]);
    }
    input[i] = pivot;
    return i;*/
    int i = left, j = right;
    //选择第一个元素为基准
    int pivotIndex = left, pivotNum = input[pivotIndex];
    while(i < j){
        while(i<j && input[j] > pivotNum){
            j--;    //
        }
        swap(input[i], input[j]);
        while(i<j && input[i] <= pivotNum){
            i++;
        }
        swap(input[i], input[j]);
    }
    input[i] = pivotNum;  //最后的位置i==j就是枢轴的位置
    return i;
}

int FindKth(vector<int> &input, int left, int right, int k)
{
    int pivotIndex = left + 1;
    if(left == right){
        return input[left];
    }
    pivotIndex = Partition(input, left, right);
    if(pivotIndex > k){
        return FindKth(input, left, pivotIndex-1, k);
    }else if(pivotIndex < k){
        return FindKth(input, pivotIndex+1, right, k);
    }else{
        return input[pivotIndex];
    }
}

//O(n)的算法，只适用于可以修改输入数组
vector<int> GetLeastNumbers_Solution(vector<int> input, int k)
{
    int kth;
    vector<int> res;
    for(int i=0; i<k; i++){
        kth = FindKth(input, 0, input.size()-1, i);
        res.push_back(kth);
    }
    return res;
}

int main()
{
    int arr[] = {4, 5, 1, 6, 2, 7, 3, 8};
    vector<int> vec(arr, arr+8);
    vector<int> res;
   
    res = GetLeastNumbers_Solution(vec, 4);
    for(vector<int>::iterator iter=res.begin(); iter!=res.end(); iter++){
        cout << *iter << " ";
    }
    cout << endl;
    return 0;
}