/*
数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。例如输入一个长度为9的数组
{1,2,3,2,2,2,5,4,2}。由于数字2在数组中出现了5次，超过数组长度的一半，因此输出2。如果不存在输出0。
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*基于Partition函数的O(n)算法*/

//Partition快速排序的划分函数，返回枢轴(left下标元素)在排序的数组中应该所处的位置，
//即下标为left的元素是第几大的元素
int Partition(vector<int> numbers, int left, int right)
{
    int i = left, j = right;
    //选择第一个元素为基准
    int pivotIndex = left, pivotNum = numbers[pivotIndex];
    while(i < j){
        while(i<j && numbers[j] > pivotNum){
            j--;    //
        }
        swap(numbers[i], numbers[j]);
        while(i<j && numbers[i] <= pivotNum){
            i++;
        }
        swap(numbers[i], numbers[j]);
    }
    numbers[i] = pivotNum;  //最后的位置i==j就是枢轴的位置
    return i;
}

//查找数组中第k大的元素
int FindKth(vector<int> numbers, int left, int right, int k)
{
    int pivotIndex = left + 1;
    if(left == right){
        return numbers[left];
    }
    pivotIndex = Partition(numbers, left, right);
    if(pivotIndex < k){    //当前查找到的比第k个数小
        //第k大的在pivot之前，在[pivotIndex+1, right]之间查找
        return FindKth(numbers, pivotIndex+1, right, k);
    }else if(pivotIndex > k){   //当前查找到的比第k个数大
        //第k小的在pivot之前，在[left, pivotIndex-1]之间查找
        return FindKth(numbers, left, pivotIndex-1, k);
    }else{  //返回
        return numbers[pivotIndex];
    }
}

//检查num元素在数组numbers中出现的次数是否超过一半
bool CheckMoreThanHalf(vector<int> numbers, int num)
{
    unsigned int count = 0;
    for(unsigned int i=0; i<numbers.size(); i++){
        if(numbers[i] == num){
            count++;
        }
    }
    if(count > numbers.size()/2){
        return true;
    }else{
        return false;
    }
}

int MoreThanHalfNum_Solution(vector<int> numbers)
{
    if(numbers.size() == 0){
        return 0;
    }else if(numbers.size() == 1){
        return numbers[0];
    }

    int num = FindKth(numbers, 0, numbers.size()-1, numbers.size() / 2);
    if(CheckMoreThanHalf(numbers, num)){
        return num;
    }else{
        return 0;
    }
}

int main()
{
    int arr[] = {1, 2, 3, 2, 2, 2, 5, 4, 2};
    vector<int> vec(arr, arr+9);
    cout << MoreThanHalfNum_Solution(vec) << endl;
    return 0;
}