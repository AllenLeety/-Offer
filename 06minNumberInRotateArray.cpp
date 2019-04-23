#include <iostream>
#include <vector>
using namespace std;

//顺序查找最小值
int minOrder(vector<int> rotateArray, int begin, int end)
{
    int min = rotateArray[begin];
    for(int i=begin+1; i<end; i++){
        if(rotateArray[i] < min){
            min = rotateArray[i];
        }
    }
    return min;
}

//
int minNumberInRotateArray(vector<int> rotateArray)
{
    if(rotateArray.size() == 0){
        return 0;
    }
    int begin = 0;
    int end = rotateArray.size() - 1;
    int mid = begin;
    while(rotateArray[begin] >= rotateArray[end]){
        //如果前一个元素与后一个元素差一位，说明找到了最大最小元素
        if(end - begin == 1){
            mid = end;
            break;
        }
        mid = (end + begin) / 2;
        //如果无法确定中间元素是属于前面还是属于后面的递增子数组，只能顺序查找
        if(rotateArray[begin] == rotateArray[mid] && rotateArray[mid] == rotateArray[end]){
            return minOrder(rotateArray, begin, end);
        }
        //如果中间元素属于前面递增子数组
        if(rotateArray[mid] >= rotateArray[begin]){
            begin = mid;
        }else if(rotateArray[mid] <= rotateArray[end]){
            end = mid;
        }
    }
    return rotateArray[mid];
}

int main()
{
    int i = 0;
    int a[] = {1, 0, 1, 1, 1};
    vector<int> vec(a, a+5);

    cout << "the array is:" << endl;
    for(i=0; i < vec.size(); i++){
        cout << vec[i] << " ";
    }
    cout << endl;

    int tmp = minNumberInRotateArray(vec);
    cout << "the Min is:" << tmp << endl;
    return 0;
}