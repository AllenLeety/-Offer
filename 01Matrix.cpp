/*
在一个二维数组中（每个一维数组的长度相同），每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。请完成一个函数，
输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。
*/
#include <iostream>
#include <vector>
using namespace std;

bool Find(vector<vector<int> > array, int target)
{
    bool found = false;
    int rows = array.size();
    int cloumns = array[0].size();
    for(int i = 0, j = cloumns - 1; (i>=0 && i<rows) && (j>=0 && j<cloumns); ){
        if(array[i][j] == target){
            found = true;
            break;
        }else if(array[i][j] > target){ //target在当前位置的左侧
            j--;
        }else{                          //target在当前位置的下方
            i++;
        }
    }

    return found;
}

void print(vector<vector<int> > array, int row, int cloumn)
{
    for(int i=0; i< row; i++){
        for(int j=0; j<cloumn; j++){
            cout << array[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int main()
{
    int a1[] = { 1, 2, 8, 9, };
    int a2[] = { 2, 4, 9, 12, };
    int a3[] = { 4, 7, 10, 13, };
    int a4[] = { 6, 8, 11, 15, };
    vector<vector<int> > array;
    array.push_back(vector<int>(a1, a1 + 4));
    array.push_back(vector<int>(a2, a2 + 4));
    array.push_back(vector<int>(a3, a3 + 4));
    array.push_back(vector<int>(a4, a4 + 4));
    int num;
    
    cout << "Enter the find number:" << endl;
    cin >> num;

    cout << "the matrix is:" << endl;
    print(array, 3, 4);

    if(Find(array, num)){
        cout << "找到" << num << endl;
    }else{
        cout << "未找到" << num << endl;
    }

    //system("pause");
    return 0;
}
