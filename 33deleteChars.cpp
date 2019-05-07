/*
输入两个字符串，从第一个字符串中删除第二个字符串中所有的字符。例如"We are student."和"aeiou"，
删除后为"W r stdnt."。
*/
#include <iostream>
#include <cstring>
using namespace std;

void deleteChars(string str1,  string str2)
{
    if(str1.length() == 0 || str2.length() == 0){
        return ;
    }
    int hashTable[256];
    memset(hashTable, 0, sizeof(hashTable));
    //遍历字str2，更新哈希表
    for(unsigned int i=0; i<str2.length(); i++){
        hashTable[(unsigned int)str2[i]] = 1;
    }
    //遍历str1
    int j = 0;
    for(unsigned int i=0; i<str1.length(); i++){
        if(hashTable[(unsigned int)str1[i]] != 1){
            str1[j++] = str1[i];
            cout << str1[i];
        }
    }
    str1[j] = 0;
}

int main()
{
    string str1 = "We are student.";
    string str2 = "aeiou";
    cout << str1 << endl;
    cout << str2 << endl;
    deleteChars(str1, str2);
    cout << endl;
    return 0;
}