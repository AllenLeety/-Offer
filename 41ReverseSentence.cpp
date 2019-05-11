/*
输入一个英文句子，翻转句子中单词的顺序，但单词内字符的顺序不变。为简单起见，标点符号和普通
字母一样处理。例如输入字符串"I am a student."，则输出"student. a am I"。
*/
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

void Reverse(string &str,int begin,int end){
    while(begin < end){
        swap(str[begin++],str[end--]);
    }
}

string ReverseSentence(string str) {
    int len = str.length();
    if(len == 0) return "";
    int begin=0;
    int end=0;
    Reverse(str,0,len-1);
    begin=end=0;
    while(str[begin]!='\0')
    {
        if(str[begin]==' ')
        {
            begin++;
            end++;
        }
        else if(str[end]==' '||str[end]=='\0')
        {
            Reverse(str,begin,--end);
            begin=++end;
        }
        else end++;
    }
    return str;
}
    
int main()
{
    //string str = "I am a student.";
    string str = "Wonderful";
    for(unsigned int i=0; i<str.size(); i++){
        cout << str[i];
    }
    cout << endl;
    string res = ReverseSentence(str);
    for(unsigned int i=0; i<res.size(); i++){
        cout << res[i];
    }
    cout << endl;
    return 0;
}