/*
在数组中的两个数字，如果前面一个数字大于后面的数字，则这两个数字组成一个逆序对。输入一个数组,
求出这个数组中的逆序对的总数P。并将P对1000000007取模的结果输出。 即输出P%1000000007
例：输入：1，2,3,4,5,6,7,0
    输出：7
*/
#include <iostream>
#include <vector>
using namespace std;

int InversePairs(vector<int> data)
{
    if(data.size() == 0){
        return 0;
    }
    int count = 0;
    for(unsigned int i=0; i<data.size(); i++){
        for(unsigned int j=i+1; j<data.size(); j++){
            if(data[i] > data[j]){
                count++;
            }
        }
    }
    return count;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 0};
    vector<int> vec(arr, arr+8);
    cout << InversePairs(vec) << endl;
    
    return 0;
}