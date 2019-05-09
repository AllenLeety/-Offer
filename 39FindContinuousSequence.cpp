/*
输出所有和为S的连续正数序列。序列内按照从小至大的顺序，序列间按照开始数字从小到大的顺序
*/
#include <iostream>
#include <vector>
using namespace std;

vector<int> PrintContinuousSequence(int begin, int end){
    vector<int> res;
    for(int i=begin; i<=end; i++){
        res.push_back(i);
    }
    return res;
}

vector<vector<int> > FindContinuousSequence(int sum)
{
    vector<vector<int> > res;
    vector<int> curRes;
    int begin = 1;
    int end = 2;
    if(sum < 3){
        return res;
    }
    int curSum = begin + end;
    int mid = (1 + sum) / 2;
    while(begin < mid && end < sum){
        if(curSum == sum){
            curRes.clear(); //清空当前数组
            for(int i=begin; i<=end; i++){
                curRes.push_back(i);
            }
            res.push_back(curRes);
            end++;
            curSum += end;
        }else if(curSum > sum){
            curSum -= begin;
            begin++;
        }else if(curSum < sum){
            end++;
            curSum += end;
        }
    }
    return res;
}

int main()
{
    int sum;
    vector<vector<int> > res;

    cout << "Enter sum:" << endl;
    cin >> sum;

    cout << "the continuous sequence:" << endl;
    res = FindContinuousSequence(sum);
    for(unsigned int i=0; i<res.size(); i++){
        for(unsigned int j=0; j<res[i].size(); j++){
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    
    return 0;
}