/*
请实现一个函数用来判断字符串是否表示数值（包括整数和小数）。例如，字符串"+100","5e2","-123","3.1416"和
"-1E-16"都表示数值。 但是"12e","1a3.14","1.2.3","+-5"和"12e+4.3"都不是。
*/
/*
分析可能是数值的字符串的格式：在数值之前可能有一个表示正负的'-'或者'+'。接线来是若干个0到9的数位表示数值
的整数部分（在某些小数里可能没有数值的整数部分）。如果数值是一个小数，那么在小数点后面可能会有若干个0到9
的数位表示数值的小数部分。如果数值用科学计数法表示，接下来是一个'e'或者'E'，以及紧跟着一个整数（可以有正
负号）表示指数。
判断一个字符串是否符合上述模式时，首先看第一个字符是不是正负号。如果是，在字符串上移动一个字符，继续扫描
剩余的字符串中0到9的位数。如果是一个小数，则将遇到小数点。另外，如果是用科学计数法表示的数值，在整数或者
小数的后面还有可能遇到'e'或者'E'。
*/
#include <iostream>
//#include <string>
using namespace std;

void ScanDigits(char **string){
    while(**string != '\0' && (**string >= '0' && **string <= '9')){
        ++(*string);
    }
}

bool IsExponential(char **string){
    if(**string != 'e' && **string != 'E'){
        return false;
    }
    ++(*string);
    if(**string == '+' || **string == '-'){
        ++(*string);
    }
    if(**string == '\0'){
        return false;
    }
    ScanDigits(string);
    return (**string == '\0') ? true : false;
}

bool isNumeric(char* string){
    if(string == NULL){
        return false;
    }
    //第一个字符可能是'+','-'
    if(*string == '+' || *string == '-'){
        ++string;
    }
    if(*string == '\0'){
        return false;
    }
    bool numberic = true;
    //处理可能遇见的数字
    ScanDigits(&string);
    if(*string != '\0'){
        if(*string == '.'){
            ++string;
            ScanDigits(&string);
            if(*string == 'e' || *string == 'E'){
                numberic = IsExponential(&string);
            }
        }else if(*string == 'e' || *string == 'E'){
            numberic = IsExponential(&string);
        }else{
            numberic = false;
        }
    }
    return (numberic && *string == '\0');
}

int main()
{
    char str[] = "123.45e+6";
    cout << isNumeric(str) << endl;
    return 0;
}