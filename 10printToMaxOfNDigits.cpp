#include <iostream>
#include <cstring>
using namespace std;

void printNumber(char *number)
{
    int i=0;
    int length = strlen(number);
    for(i=0; i<length; i++){
        if(number[i] != '0'){
            break;
        }
    }
    if(i != length){    //开始的0不应该输出
        cout << &number[i] << endl;
    }
}

void printToMaxOfNDigitsRecursively(char *number, int length, int index)
{
    if(index == length - 1){
        cout << "we find a number" << endl;
        printNumber(number);
        return;
    }
    //当前位循环0~9
    for(int i=0; i<10; i++){
        number[index+1] = i + '0';
        cout << "now, index = " << index << ", digit = " << number[index+1] << endl;
        printToMaxOfNDigitsRecursively(number, length, index+1);
    }
}

void printToMaxOfNDigits(int n)
{
    if(n <= 0){
        return ;
    }
    char *number = new char[n+1];
    number[n] = '\0';
    //最低位循环0~9
    for(int i=0; i<10; i++){
        cout << "now list all " << i <<" in the low position" << endl;
        number[0] = i + '0';
        printToMaxOfNDigitsRecursively(number, n, 0);
    }
    delete [] number;
} 

int main()
{
    int n;
    cout << "Enter n:" << endl;
    cin >> n;
    printToMaxOfNDigits(n);

    return 0;
}