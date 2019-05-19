/*
给定一个数组和滑动窗口的大小，找出所有滑动窗口里数值的最大值。例如，如果输入数组{2,3,4,2,6,2,5,1}及滑动窗口
的大小3，那么一共存在6个滑动窗口，他们的最大值分别为{4,4,6,6,6,5}； 针对数组{2,3,4,2,6,2,5,1}的滑动窗口
有以下6个： {[2,3,4],2,6,2,5,1}， {2,[3,4,2],6,2,5,1}， {2,3,[4,2,6],2,5,1}， {2,3,4,[2,6,2],5,1}，
 {2,3,4,2,[6,2,5],1}， {2,3,4,2,6,[2,5,1]}。
*/
#include <iostream>
#include <vector>
using namespace std;

vector<int> maxInWindows(const vector<int>& num, unsigned int size){
    vector<int> res;
    if(num.size() == 0 || size == 0){
        return res;
    }
    for(unsigned int start = 0; start <= num.size()-size; start++){
        int end = start + size;
        int max = num[start];
        for(int i = start + 1; i < end; i++){
            if(num[i] > max){
                max = num[i];
            }
        }
        res.push_back(max);
    }
    return res;
}

int main()
{
    int arr[] = {2, 3, 4, 2, 6, 2, 5, 1};
    vector<int> num(arr, arr+8);
    cout << "the num:" << endl;
    for(unsigned int i=0; i<num.size(); i++){
        cout << num[i] << " ";
    }
    cout << endl;
    cout << "max in windows:" << endl;
    vector<int> res = maxInWindows(num, 3);
    for(unsigned int i=0; i<res.size(); i++){
        cout << res[i] << " ";
    }
    cout << endl;
    return 0;
}