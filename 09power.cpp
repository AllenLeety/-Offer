#include <iostream>
#include <bitset>
#include <cmath>
using namespace std;

bool Equal(double left, double right)
{
    if(fabs(left - right) < 0.0000001){
        return true;
    }else{
        return false;
    }
}

double PowerNormal(double base, int exponent)
{
    if(exponent == 0){
        return 1;
    }else if(exponent == 1){
        return base;
    }

    double res = PowerNormal(base, exponent >> 1);
    res *= res;
    if( (exponent & 1) == 1){
        res *= base;
    }

    return res;
}

double Power(double base, int exponent)
{
    //指数为0的情况，不管底数是多少都应该是0
    if(exponent == 0){
        return 1;
    }
    //指数为负数的情况下，底数不能为0
    if(exponent < 0 && Equal(base, 0.0)){
        return 0.0;
    }
    double res = 1.0;
    if(exponent > 0){
        res = PowerNormal(base, exponent);
    }else{
        res = PowerNormal(base, -exponent);
        res = 1 / res;
    }
    return res;
}

int main()
{
    double base, res;
    int exponent;

    cout << "Enter base: " << endl;
    cin >> base;
    cout << "Enter exponent: " << endl;
    cin >> exponent;

    res = Power(base, exponent);
    cout << "the result is: " << res << endl;

    return 0;
}