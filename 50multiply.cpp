/*
给定一个数组A[0,1,...,n-1],请构建一个数组B[0,1,...,n-1],其中B中的元素
B[i]=A[0]*A[1]*...*A[i-1]*A[i+1]*...*A[n-1]。不能使用除法。
*/
#include <iostream>
#include <vector>
using namespace std;

vector<int> multiply(const vector<int>& A){
    unsigned int len = A.size();
    vector<int> res(len);
    for(int i=0, temp = 1; i<len; i++){
        res[i] = temp;//res[i] = A[0]*A[1]*...*A[i-1]
        temp *= A[i];
    }
    for(int i=len-1, temp=1; i>=0; i--){
        res[i] *= temp; //res[i] = A[i+1]*A[i+2]*...*A[n-1]
        temp *= A[i];
    }
    return res;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    vector<int> vec(arr, arr+5);
    vector<int> res = multiply(vec);
    for(unsigned int i=0; i<res.size(); i++){
        cout << res[i] << " ";
    }
    cout << endl;
    return 0;
}