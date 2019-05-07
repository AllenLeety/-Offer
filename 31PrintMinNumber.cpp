/*
输入一个正整数数组，把数组里所有数字拼接起来排成一个数，打印能拼接出的所有数字中最小的一个。
例如输入数组{3，32，321}，则打印出这三个数字能排成的最小数字为321323。
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>
using namespace std;

static bool Compare(int a, int b)
{
    string A = to_string(a) + to_string(b);
    string B = to_string(b) + to_string(a);
    return A < B;
}

string PrintMinNumber(vector<int> numbers)
{
    int len = numbers.size();
    if(len == 0){
        return "";
    }
    
    //对数组按照Compare进行排序
    sort(numbers.begin(), numbers.end(), Compare);
    string res;
    //拼接结果
    for(int i=0; i<len; i++){
        res += to_string(numbers[i]);
        cout << numbers[i] << " ";
    }
    cout << endl;
    return res;
}

int main()
{
    int arr[] = {3, 32, 321};
    vector<int> vec(arr, arr+3);
    cout << PrintMinNumber(vec) << endl;
    return 0;
}