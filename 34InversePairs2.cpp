/*
在数组中的两个数字，如果前面一个数字大于后面的数字，则这两个数字组成一个逆序对。输入一个数组,
求出这个数组中的逆序对的总数P。并将P对1000000007取模的结果输出。 即输出P%1000000007
例：输入：1，2,3,4,5,6,7,0
    输出：7
*/
/*
统计逆序对的过程：先把数组分隔成子数组，先统计出子数组内部的逆序对的数目，然后再统计出两个相
邻子数组之间的逆序对的数目。在统计逆序对的过程中，需要用归并排序对数组进行排序。
*/
#include <iostream>
#include <vector>
using namespace std;

int Merge(vector<int> &data, int start, int mid, int end, vector<int> &temp)
{
    int i = mid;
    int j = end;
    int k = 0;
    int count = 0;
    //设定两个指针i，j分别指向两段有序数组的尾元素，将小的那一个放入到临时数组中去
    while(i >= start && j > mid){
        if(data[i] > data[j]){
            temp[k++] = data[i--];  //从临时数组的最后一个位置开始排序
            count += j - mid;
        }else{
            temp[k++] = data[j--];
        }
    }
    while(i >= start){  //表示前半段数组中还有元素未放入临时数组
        temp[k++] = data[i--];
    }
    while(j > mid){
        temp[k++] = data[j--];
    }
    //将临时数组中的元素写回到原数组当中
    for(int i=0; i<k; i++){
        data[end-i] = temp[i];
    }
    return count;
}

int InversePairsCore(vector<int> &data, int start, int end, vector<int> &temp)
{
    int count = 0;
    if(start < end){
        int mid = (start + end) / 2;
        count += InversePairsCore(data, start, mid, temp);  //左半段的逆序对数目
        count += InversePairsCore(data, mid+1, end, temp);  //右半段的逆序对数目
        //在找完左右半段逆序对以后两段数组有序，然后找两段之间的逆序对，最小的逆序段只有一个元素
        count += Merge(data, start, mid, end, temp);    
    }
    return count;
}

int InversePairs(vector<int> data)
{
    if(data.size() == 0){
        return 0;
    }
    vector<int> temp(data.size());
    int count = InversePairsCore(data, 0, data.size()-1, temp);
    return count;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 0};
    vector<int> vec(arr, arr+8);
    cout << InversePairs(vec) << endl;
    return 0;
}