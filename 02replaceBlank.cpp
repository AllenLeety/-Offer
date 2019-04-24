/*
请实现一个函数，将一个字符串中的每个空格替换成“%20”。
例如，当字符串为We Are Happy.则经过替换之后的字符串为We%20Are%20Happy。
*/
#include <iostream>
using namespace std;

void replaceSpace(char *str, int length)
{
    if(str == NULL && length<=0){
        return;
    }
    int count=0;//空格数
    int originalLen=0;//字符串实际长度
    int i=0;
    while(str[i] != '\0'){
        originalLen++;
        if(str[i] == ' '){
            count++;
        }
        i++;
    }

    int newLen = originalLen + count * 2;
    int p1 = originalLen;//原始数组最后一个元素的下标
    int p2 = newLen;    //新数组最后一个元素的下标
    while(p1>=0 && p2>p1){
        if(str[p1] == ' '){
            str[p2--] = '0';
            str[p2--] = '2';
            str[p2--] = '%';
        }else{
            str[p2--] = str[p1];
        }
        p1 --;
    }

}

int main()
{
    char str[10] = "a b c d e";
    cout << "original string:" << endl;
    //for(int i=0; i<10; i++){
    //    cout << str[i];
    //}
    cout << str << endl;

    replaceSpace(str, 10);
    cout << "replace string:" << endl;
    cout << str << endl;

    return 0;
}