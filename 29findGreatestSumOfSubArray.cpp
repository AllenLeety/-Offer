/*
HZ偶尔会拿些专业问题来忽悠那些非计算机专业的同学。今天测试组开完会后,他又发话了:在古老的一维模式识别中,
常常需要计算连续子向量的最大和,当向量全为正数的时候,问题很好解决。但是,如果向量中包含负数,是否应该包含某
个负数,并期望旁边的正数会弥补它呢？例如:{6,-3,-2,7,-15,1,2,2},连续子向量的最大和为8(从第0个开始,到
第3个为止)。给一个数组，返回它的最大连续子序列的和，你会不会被他忽悠住？(子向量的长度至少是1)
*/
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

/*贪心思想 O(n)，对数组只扫描一次*/
int FindGreatestSumOfSubArray(vector<int> array)
{
    if(array.size() == 0){
        return 0;
    }
    int sum = 0;
    int maxSum = INT_MIN;
    for(unsigned int i=0; i<array.size(); i++){
        if(sum < 0){
            sum = array[i];
        }else{
            sum += array[i]; 
        }

        if(sum > maxSum){
            maxSum = sum;
        }
    }
    return maxSum;
}

int main()
{
    int tmp;
    int arr[] = {1, -2, 3, 10, -4, 7, 2, -5};
    int arr1[] = {6, -3, -2, 7, -15, 1, 2, 2};
    std::vector<int> vec(arr, arr+8);
    std::vector<int> vec1(arr1, arr1+8);

    tmp = FindGreatestSumOfSubArray(vec);
    cout << tmp << endl;
    tmp = FindGreatestSumOfSubArray(vec1);
    cout << tmp << endl;

    return 0;
}