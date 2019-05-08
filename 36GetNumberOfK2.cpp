/*
统计一个数字在排序数组中出现的次数。例如输入排序数组{1,2,3,3,3,3,4,5}和数字3，由于3在这个
数组中出现了4次，因此输出4.
*/
#include <iostream>
#include <vector>
using namespace std;
//利用二分法查找 递归
int GetFirstIndex(vector<int> &data, int k, int low, int high)
{
    if(low > high){
        return -1;
    }
    int mid = (low + high) / 2;
    if(data[mid] == k){
        if((mid > 0 && data[mid-1] != k) || mid == 0){
            return mid;
        }else{
            high = mid - 1;
        }
    }else if(data[mid] > k){
        high = mid - 1;
    }else if(data[mid] < k){
        low = mid + 1;
    }
    return GetFirstIndex(data, k, low, high);
}

int GetLastIndex(vector<int> &data, int k, int low, int high)
{
    if(low > high){
        return -1;
    }
    int mid = (low + high) / 2;
    if(data[mid] == k){
        if((mid < high && data[mid+1] != k) || mid == high){
            return mid;
        }else{
            low = mid + 1;
        }
    }else if(data[mid] > k){
        high = mid - 1;
    }else if(data[mid] < k){
        low = mid + 1;
    }
    return GetLastIndex(data, k, low, high);
}
int GetNumberOfK(vector<int> data ,int k)
{
    if(data.size() == 0){
        return 0;
    }
    int count = 0;
    int first = GetFirstIndex(data, k, 0, data.size() - 1);
    int last = GetLastIndex(data, k, 0, data.size() - 1);

    if(first > -1 && last > -1){
        count = last - first + 1;
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