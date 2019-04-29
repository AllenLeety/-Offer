/*
输入一个整数数组，判断该数组是不是某二叉搜索树的前序遍历的结果。
如果是则输出Yes,否则输出No。假设输入的数组的任意两个数字都互不相同。
*/
#include <iostream>
#include <vector>
using namespace std;

bool VerifySqueOfBSTPreOrder(vector<int> squence)
{
    if(squence.size() == 0){
        return false;
    }
    int left = 0; 
    int right = squence.size() - 1;
    while(left <= squence.size()-1){
        //右子树的结点都大于根节点
        while(squence[right] > squence[left]){
            right--;//循环结束时，right指向第一个小于根节点的元素
        }
        //左子树的结点都小于根节点
        while(squence[right] < squence[left]){
            right--;//循环结束时，right==left
        }
        if(right > left){
            return false;
        }
        right = squence.size() - 1;
        left++;
    }
    return true;
}

int main()
{
    int arr1[] = {8, 6, 5, 7, 10, 9, 11};
    int arr2[] = {5, 6, 4, 7};
    vector<int> vec1(arr1, arr1 + 7);
    vector<int> vec2(arr2, arr2 + 4);

    cout << VerifySqueOfBSTPreOrder(vec1) << endl;
    cout << VerifySqueOfBSTPreOrder(vec2) << endl;

    return 0;
}