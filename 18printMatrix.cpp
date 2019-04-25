/*
输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字，例如，
如果输入如下4 X 4矩阵： 1  2  3  4 
                    5  6  7  8
                    9  10 11 12 
                    13 14 15 16 
则依次打印出数字1,2,3,4,8,12,16,15,14,13,9,5,6,7,11,10.
*/
#include <iostream>
#include <vector>
using namespace std;

vector<int> printMatrix(vector<vector<int> > matrix)
{
    int row = matrix.size();
    int column = matrix[0].size();
    vector<int> res;
    int start = 0;
    while(row > start*2 && column > start*2){
        int endX = column - 1 - start;
        int endY = row - 1 - start;
        //从左到右打印一行
        for (int i = start; i <= endX; ++i)
        {
            int number = matrix[start][i];
            res.push_back(number);
        }
        //从上到下打印一列
        if(start < endY){
            for(int i = start+1; i<= endY; i++){
                int number = matrix[i][endY];
                res.push_back(number);
            }
        }
        //从右到左打印一行
        if(start < endX && start < endY){
            for(int i = endX-1; i >= start; i--){
                int number = matrix[endY][i];
                res.push_back(number);
            }
        }
        //从下到上打印一列
        if(start < endX && start < endY-1){
            for(int i = endY-1; i > start; i--){
                int number = matrix[i][start];
                res.push_back(number);
            }
        }
        start++;
    }
    return res;
}

void print(vector<vector<int> > matrix)
{
    int row = matrix.size();
    int column = matrix[0].size();
    for(int i = 0; i<row; i++){
        for(int j = 0; j<column; j++){
            cout << matrix[i][j] << " ";
        }
    }
    cout << endl;
}

int main()
{
    int a1[] = {1, 2, 3, 4};
    int a2[] = {5, 6, 7, 8};
    int a3[] = {9, 10, 11, 12};
    int a4[] = {13, 14, 15, 16};
    vector<int> tmp;
    vector<int> vec1(a1, a1+4);
    vector<int> vec2(a2, a2+4);
    vector<int> vec3(a3, a3+4);
    vector<int> vec4(a4, a4+4);
    vector<vector<int> > vec;
    vec.push_back(vec1);
    vec.push_back(vec2);
    vec.push_back(vec3);
    vec.push_back(vec4);
    cout << "the original matrix:" << endl;
    print(vec);

    tmp = printMatrix(vec);
    cout << "thr matrix in circle:" << endl;
    for(int i=0; i<tmp.size(); i++){
        cout << tmp[i] << " ";
    }
    cout << endl;

    return 0;
}