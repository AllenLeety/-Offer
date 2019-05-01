/*
输入一个字符串,按字典序打印出该字符串中字符的所有排列。例如输入字
符串abc,则打印出由字符a,b,c所能排列出来的所有字符串
abc,acb,bac,bca,cab和cba。
输入一个字符串,长度不超过9(可能有字符重复),字符只包括大小写字母。
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

vector<string> res;

void permutationRecursion(string str, int begin)
{
    if(begin == str.length()){
        res.push_back(str);
        cout << str << endl;
        return;
    }
    for(int i = begin; str[i] != '\0'; i++){
        if(i != begin && str[begin] == str[i]){
            continue;
        }
        swap(str[begin], str[i]);
        permutationRecursion(str, begin+1);
        swap(str[begin], str[i]);
    }
}

vector<string> Permutation(string str)
{
    if(str.length() == 0){
        return res;
    }
    permutationRecursion(str, 0);
    sort(res.begin(), res.end());
    return res;
}

int main()
{
    Permutation("abc");

    return 0;
}