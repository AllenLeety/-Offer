/*
输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历的结果。
如果是则输出Yes,否则输出No。假设输入的数组的任意两个数字都互不相同。
*/
#include <iostream>
#include <vector>
using namespace std;

bool VerifySquenceOfBST(vector<int> sequence)
{
    if(sequence.size() == 0){
        return false;
    }
    int left = 0, right = sequence.size()-1;
    while(right > 0){
        //左子树的元素都小于根节点
        while(sequence[left] < sequence[right]){
            left++;//循环结束时，left指向第一个大于根节点的元素
        }
        //右子树的元素都大于根节点
        while(sequence[left] > sequence[right]){
            left++;//循环结束时，left等于right
        }
        if(left < right){
            return false;
        }
        left = 0;
        right--;
    }
    //如果循环一直走到right==0才终止，则说明满足后序遍历的定义
    return true;
}

int main()
{
    int arr1[] = {5, 7, 6, 9, 11, 10, 8};
    int arr2[] = {7, 4, 6, 5};
    vector<int> vec1(arr1, arr1 + 7);
    vector<int> vec2(arr2, arr2 + 4);

    cout << VerifySquenceOfBST(vec1) << endl;
    cout << VerifySquenceOfBST(vec2) << endl;
    return 0;
}