/*
请实现一个函数用来匹配包括'.'和'*'的正则表达式。模式中的字符'.'表示任意一个字符，而'*'表示它前面的字符可以
出现任意次（包含0次）。 在本题中，匹配是指字符串的所有字符匹配整个模式。
例如，字符串"aaa"与模式"a.a"和"ab*ac*a"匹配，但是与"aa.a"和"ab*a"均不匹配
*/
/*
分治搜索
A 考虑特殊情况即S字符串或者P字符串结束
    1.S字符串结束，要求P也结束或者间隔'*'，否则无法匹配
    2.S字符串未结束，而P字符串结束，则无法匹配
B S字符串与P字符串均未结束
    1.(P+1)字符不为'*'，则只需比较S字符与P字符，若相等则递归到(S+1)字符串与(P+1)字符串的比较，否则无法匹配
    2.(P+1)字符为'*'，则P字符可匹配S字符串中从0开始任意多(记为i)等于P的字符，然后递归到(S+i+1)字符串与
        *(P+2)字符串的比较
*/
#include <iostream>
using namespace std;

bool match(char* str, char* pattern){
    if(str[0] == 0 && pattern[0] == 0){
        return true;
    }
    if(pattern[0] != 0 && pattern[1] == '*'){
        if(match(str, pattern+2)){
            return true;
        }
    }
    if((pattern[0] == '.' && str[0]) || str[0] == pattern[0]){
        if(match(str+1, pattern+1)){
            return true;
        }
        if(pattern[1] == '*' && match(str+1, pattern)){
            return true;
        }
    }
    return false;
}

int main()
{
    char str[] = "aa";
    char pattern[] = "ab*a";
    cout << match(str, pattern) << endl;

    return 0;
}