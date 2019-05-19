/*
如何得到一个数据流中的中位数？如果从数据流中读出奇数个数值，那么中位数就是所有数值排序之后位于中间的数值。
如果从数据流中读出偶数个数值，那么中位数就是所有数值排序之后中间两个数的平均值。我们使用Insert()方法读取数
据流，使用GetMedian()方法获取当前读取数据的中位数。
*/
/*
采用multiset来实现，set和multiset会根据特定的排序准则，自动将元素进行排序。不同的是后者允许元素重复而
前者不允许。
*/
#include <iostream>
#include <vector>
#include <set>
#include <iterator>
using namespace std;

multiset<int> m_left; //左半部分
multiset<int> m_right;//右半部分

void Insert(int num){
    if(((m_left.size() + m_right.size()) & 1) == 0){    //偶数
        if(!m_right.empty() && num > *m_right.begin()){
            m_right.insert(num);
            num = *m_right.begin();
            m_right.erase(m_right.find(num));
        }
        m_left.insert(num);
    }else{
        if(!m_left.empty() && num < *m_left.rbegin()){
            m_left.insert(num);
            num = *m_left.rbegin();
            m_left.erase(m_left.find(num));
        }
        m_right.insert(num);
    }
}

double GetMedian(){
    if(((m_left.size() + m_right.size()) & 1) == 0){
        return (*m_left.rbegin() + *m_right.begin()) / 2.0;
    }else{
        return *m_left.rbegin();
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