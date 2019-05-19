/*
地上有一个m行和n列的方格。一个机器人从坐标0,0的格子开始移动，每一次只能向左，右，上，下四个方向移动一格，
但是不能进入行坐标和列坐标的数位之和大于k的格子。 例如，当k为18时，机器人能够进入方格（35,37），因为
3+5+3+7 = 18。但是，它不能进入方格（35,38），因为3+5+3+8 = 19。请问该机器人能够达到多少个格子？
*/
#include <iostream>
#include <vector>
using namespace std;

int getNum(int num1, int num2){
    int sum = 0;
    while(num1>0){
        sum += num1 % 10;
        num1 /= 10;
    }
    while(num2>0){
        sum += num2 % 10;
        num2 /= 10;
    }
    return sum;
}

bool check(int threshold, int rows, int cols, int x, int y, vector<bool> &visited){
    if(x >= 0 && x < rows && y >= 0 && y < cols && !visited[x * cols + y] && getNum(x, y) <= threshold){
        return true;
    }else{
        return false;
    }
}

int movingCountCore(int threshold, int rows, int cols, int x, int y, vector<bool> &visited){
    
    int count = 0;
    if(check(threshold, rows, cols, x, y, visited)){
        visited[x * cols + y] = true;
        count = 1 + movingCountCore(threshold, rows, cols, x-1, y, visited) 
                + movingCountCore(threshold, rows, cols, x, y-1, visited)
                + movingCountCore(threshold, rows, cols, x+1, y, visited)
                + movingCountCore(threshold, rows, cols, x, y+1, visited);
    }
    return count;
}

int movingCount(int threshold, int rows, int cols){
    vector<bool> visited(rows * cols);
    int count = movingCountCore(threshold, rows, cols, 0, 0, visited);
    return count;
}

int main()
{
    int expected;
    cout << "the expected number:" << endl;
    cin >> expected;
    if(movingCount(5, 10, 10) == expected){
        cout << "passed" << endl;
    }else{
        cout << "failed" << endl;
    }
    return 0;
}