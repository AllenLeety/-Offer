/*
在一个字符串(0<=字符串长度<=10000，全部由字母组成)中找到第一个只出现一次的字符,并返回它的位置, 
如果没有则返回 -1（需要区分大小写）.
*/
#include <iostream>
#include <cstring>
using namespace std;

int FirstNotRepeatingChar(string str)
{
    int count[256];
    if(str.length() == 0){
        return -1;
    }
    //将计数器数组清零 
    memset(count, '\0', sizeof(count));
    //对字符串中出现的每个字符进行计数
    for(unsigned int i=0; i<str.length(); i++){
        count[(unsigned int)str[i]]++;
    }
    //第一个只出现一次的字符
    for(unsigned int i=0; i<str.length(); i++){
        if(count[(unsigned int)str[i]] == 1){
            return i;
        }
    }
    return -1;
}

int main()
{
    cout << FirstNotRepeatingChar("allen930422@gmail.com") << endl;
    return 0;
}