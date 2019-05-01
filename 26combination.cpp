/*
输入一个字符串,按字典序打印出该字符串中字符的所有组合。例如输入字
符串abc,则打印出由字符a,b,c所能组合出来的所有字符串
a, b, c, ab, ac, bc和abc。
输入一个字符串,长度不超过9(可能有字符重复),字符只包括大小写字母。
*/
#include <iostream>
#include <vector>
#include <iterator>
#include <cstring>
#include <assert.h>
using namespace std;

void CombinationRecursion(char* str, int m, vector<char> res)
{
    assert(str != NULL);
    if(m == 0){
        vector<char>::iterator iter = res.begin();
        for(; iter != res.end(); iter++){
            cout << *iter;
        }
        cout << endl;
        return;
    }
    if(*str == '\0'){
        return;
    }
    res.push_back(*str);
    CombinationRecursion(str+1, m-1, res);
    res.pop_back();
    CombinationRecursion(str+1, m, res);
}

void Combination(char* str)
{
    assert(str != NULL);
    vector<char> res;
    int length = strlen(str);
    for(int i=1; i<=length; i++){//1 << m << length
        CombinationRecursion(str, i, res);
    } 
}

int main()
{
    char str[] = "abc";
    Combination(str);

    return 0;
}
