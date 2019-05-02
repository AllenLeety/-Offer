/*
输入一个含有8个数字的数组，判断有没有可能把这个8个数字分别放到正方体的
8个顶点上，使得正方体上三个组合相对的面上的4个顶点的和都相等
*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool canBeCube(vector<int> vec)
{
    bool flag1 = vec[0]+vec[1]+vec[2]+vec[3] == vec[4]+vec[5]+vec[6]+vec[7];
    bool flag2 = vec[0]+vec[1]+vec[4]+vec[5] == vec[2]+vec[3]+vec[6]+vec[7];
    bool flag3 = vec[0]+vec[2]+vec[4]+vec[6] == vec[1]+vec[3]+vec[5]+vec[7];
    return (flag1 && flag2 && flag3);
}

vector<int> cubeSum(vector<int> vec, int begin)
{
    vector<int> res;
    if(begin >= 8){//到达数组尾部，判断当前排列是否符合条件
        if(!canBeCube(vec)){
            return res;
        }
        for(int i=0; i<8; i++){
            cout << vec[i] << " ";
        }
        cout << endl;
        
    }
    //依次将数组中的元素与首元素进行交换，完成递归后，再交换回来
    for(int i=begin; i<8; i++){
        swap(vec[begin], vec[i]);
        cubeSum(vec, begin+1);
        swap(vec[begin], vec[i]);
    }
    return res;
}


int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8};
    vector<int> vec(arr, arr+8);
    cubeSum(vec, 0);

    return 0;
}