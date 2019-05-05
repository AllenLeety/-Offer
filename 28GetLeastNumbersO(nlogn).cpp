/*
输入n个整数，找出其中最小的K个数。例如输入4,5,1,6,2,7,3,8这8个数字，则最小的4个数字是1,2,3,4,。
*/
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <iterator>
using namespace std;

/*O(nlogk)的算法，适合海量数据*/
vector<int> GetLeastNumbers_Solution(vector<int> input, int k)
{
    vector<int> res;
    if(input.size() == 0 || input.size() < k){
        return res;
    }
    multiset<int, greater<int> > intSet;
    multiset<int, greater<int> >::iterator setIterator;
    for(vector<int>::iterator iter=input.begin(); iter != input.end(); iter++){
        if(intSet.size() < k){
            intSet.insert(*iter);
        }else{
            setIterator = intSet.begin();
            if(*iter < *setIterator){
                intSet.erase(setIterator);
                intSet.insert(*iter);
            }
        }
    }
    for(setIterator = --intSet.end(); setIterator != --intSet.begin(); setIterator--){
        res.push_back(*setIterator);
    }
    return res;
}

int main()
{
    int arr[] = {4, 5, 1, 6, 2, 7, 3, 8};
    vector<int> vec(arr, arr+8);
    vector<int> res;
   
    res = GetLeastNumbers_Solution(vec, 4);
    for(vector<int>::iterator iter=res.begin(); iter!=res.end(); iter++){
        cout << *iter << " ";
    }
    cout << endl;
    return 0;
}