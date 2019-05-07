/*
定义一个函数，删除字符串中所有重复出现的字符。例如输入"google",输出"gole"。
*/
#include <iostream>
#include <cstring>
using namespace std;

void deleteRepeatChar(string str)
{
    if(str.length() == 0){
        return;
    }
    int hashTable[256];
    memset(hashTable, 0, sizeof(hashTable));
    int j = 0;
    for(unsigned int i=0; i<str.length(); i++){
        if(hashTable[(unsigned int)str[i]] != 1){
            hashTable[(unsigned int)str[i]] = 1;
            str[j++] = str[i];
            cout << str[i];
        }
    }
    str[j] = 0;
}

int main()
{
    string str = "google";
    deleteRepeatChar(str);
    cout << endl;
    return 0;
}