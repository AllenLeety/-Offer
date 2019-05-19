/*
将一个字符串转换成一个整数(实现Integer.valueOf(string)的功能，但是string不符合数字要求时返回0)，要求不能
用字符串转换整数的库函数。 数值为0或者字符串不是一个合法的数值则返回0。
*/
#include <iostream>
#include <string>
#include <iterator>
using namespace std;

int StrToInt(string str){
    string::iterator pstr = str.begin();
    //排除前导的空格
    while(*pstr == ' '){
        pstr++;
    }
    bool minus = false;
    //判断符号位 + -
    if(*pstr == '+'){
        pstr++;
    }else if(*pstr == '-'){
        pstr++;
        minus = true;
    }

    long long int value = 0;
    for( ; pstr != str.end(); pstr++){
        if(*pstr >= '0' && *pstr <= '9'){
            value *= 10;
            value += *pstr - '0';
        }else{
            break;
        }
        //解决溢出问题 INT_MAX 2147483647 INT_MIN -2147483648
        if((minus == true && value > (unsigned long)(INT_MAX) + 1) || (minus == false && value > INT_MAX)){
            break;
        }
    }
    if(pstr != str.end()){
        return 0;
    }else{
        if(minus == true){
            value = -value;
        }
        if(value >= INT_MAX){
            value = INT_MAX;
        }else if(value <= INT_MIN){
            value = INT_MIN;
        }
        return (int)value;
    }
}

int main()
{
    cout << StrToInt("1a33") << endl;
    cout << StrToInt("-12345678ji1") << endl;
    cout << StrToInt("-2147483648") << endl;
    return 0;
}