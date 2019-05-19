/*
如何得到一个数据流中的中位数？如果从数据流中读出奇数个数值，那么中位数就是所有数值排序之后位于中间的数值。
如果从数据流中读出偶数个数值，那么中位数就是所有数值排序之后中间两个数的平均值。我们使用Insert()方法读取数
据流，使用GetMedian()方法获取当前读取数据的中位数。
*/
/*
比如将元素插在后半段（最小堆）中，则最小堆调整后的堆顶（最小值）需要弹出并压入到前半段中才能保证平衡。也就是
说，在最小堆中插入元素，最后完成调整后将导致最大堆中元素加1。
假定0 <= m_min.size() - m_max.size() <= 1，那么插入前如果整个数组的元素个数为偶数，说明两个堆中元素个数相等，
则最终元素应该插入m_min中，即先把元素插入到m_max中再调整到m_min中；插入前如果整个数组的元素个数为奇数，说明m_max元
素多了一个，则最终元素应该插入m_max中，即先把元素插入到m_min中再调整到m_max中。
由于假定0 <= m_min.size() - m_max.size() <= 1，因此，当总元素个数为偶数时，中位数为(m_max[0]+m_min[0])/2；
当总元素个数为奇数时，中位数为m_min[0]。
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> m_min;    //数组中的后一半元素组成一个最小化堆
vector<int> m_max;    //数组中的前一半元素组成一个最大化堆

void Insert(int num)
{
    if(((m_min.size() + m_max.size()) & 1) == 0){   //偶数，将新数据插入到后半段m_min，m_min中多出一个最小元素，将其弹出后，压入m_max中
        if(m_max.size() > 0 && num < m_max[0]){
            m_max.push_back(num);
            push_heap(m_max.begin(), m_max.end(), less<int>());
            num = m_max[0];
            pop_heap(m_max.begin(), m_max.end(), less<int>());
            m_max.pop_back();
        }
        m_min.push_back(num);//把前一半找到的最大值放到后一半中
        push_heap(m_min.begin(), m_min.end(), greater<int>());
    }else{//奇数，将新数据插入到前半段m_max，m_max中多出一个最大元素，将其弹出后，压入m_min中
        if(m_min.size() > 0 && num > m_min[0]){
            m_min.push_back(num);
            push_heap(m_min.begin(), m_min.end(), greater<int>());
            num = m_min[0];
            pop_heap(m_min.begin(), m_min.end(), greater<int>());
            m_min.pop_back();
        }
        m_max.push_back(num);//把后一半找到的最小值放到前一半中
        push_heap(m_max.begin(), m_max.end(), less<int>());
    }
}

double GetMedian()
{ 
    int size = m_min.size() + m_max.size();
    if(size <= 0){
        return -1;
    }
    if((size & 1) == 0){
        return (m_min[0] + m_max[0]) / 2.0;
    }else{
        return m_min[0];
    }
}

int main()
{
    int arr[] = {5, 2, 3, 4, 1, 6, 7, 0, 8};
    vector<int> vec(arr, arr+9);
    for(int i=0; i<vec.size(); i++){
        Insert(vec[i]);
        cout << "Insert(" << vec[i] << "),Median = " << GetMedian() << endl;
    }

    return 0;
}