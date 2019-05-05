/*
在8*8的国际象棋上拜访8个皇后，使其不能相互攻击，即任意两个皇后不得处在同一行
、同一列或者同一对角线上。请问有多少种符合条件的摆法？
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <stdlib.h>
using namespace std;

int count = 0;

void chessQueen(vector<int> &vec, int begin)
{
    bool can = true;
    if(begin==7){
        for(int i=0; i<8; i++){
            for(int j=i+1; j<8; j++){
                if(i-j==vec[i]-vec[j] || j-i==vec[j]-vec[i]){
                    can = false;
                    break;
                }
            }
            if(can == false){
                break;
            }
        }
        if(can){
            for(int i=0; i<8; i++){
                cout << vec[i] << " ";
            }
            cout << endl;
            count++;
        }
    }else{
        for(int i=begin; i<8; i++){
            swap(vec[begin], vec[i]);
            chessQueen(vec, begin+1);
            swap(vec[begin], vec[i]);
        }
    }
    
}

int main()
{
    int arr[] = {0, 1, 2, 3, 4, 5, 6, 7};
    vector<int> vec(arr, arr+8);
    chessQueen(vec, 0);
    cout << count << endl;
    return 0;
}