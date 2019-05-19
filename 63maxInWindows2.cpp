/*
给定一个数组和滑动窗口的大小，找出所有滑动窗口里数值的最大值。例如，如果输入数组{2,3,4,2,6,2,5,1}及滑动窗口
的大小3，那么一共存在6个滑动窗口，他们的最大值分别为{4,4,6,6,6,5}； 针对数组{2,3,4,2,6,2,5,1}的滑动窗口
有以下6个： {[2,3,4],2,6,2,5,1}， {2,[3,4,2],6,2,5,1}， {2,3,[4,2,6],2,5,1}， {2,3,4,[2,6,2],5,1}，
 {2,3,4,2,[6,2,5],1}， {2,3,4,2,6,[2,5,1]}。
*/
/*
单调队列
队列中存储的是最大值的下标，为了得到滑动窗口的最大值，队列序可以从两端删除元素，因此使用双端队列。
原则：
    对新来的元素k，将其与双端队列中的元素相比较
        前面比k小的，直接移出队列（因为不再可能成为后面滑动窗口的最大值了）
        前面比k大的x，比较两者下标，判断x是否已不在窗口之内，不在了，直接移出队列
    队列的第一个元素是滑动窗口中的最大值
*/
#include <iostream>
#include <vector>
#include <deque>
using namespace std;

vector<int> maxInWindows(const vector<int>& num, unsigned int size){
    vector<int> res;
    deque<int> deq;
    if(num.size() == 0 || size < 1){
        return res;
    }
    for(unsigned int i=0; i<num.size(); i++){
        while(deq.size() && num[deq.back()] <= num[i]){
            deq.pop_back();//从后面一次弹出队列中比当前num值小的元素，同时也能保证队列首元素为当前窗口最大值下标
        }
        while(deq.size() && i - deq.front() + 1 > size){
            deq.pop_front();//当前窗口移出队首元素所在的位置，即队首元素坐标对应的num不在窗口中，需要弹出
        }
        deq.push_back(i);//把每次每次滑动的num下标加入队列
        //当滑动窗口首地址i大于等于size时才开始写入窗口最大值
        if(size && i + 1 >= size){
            res.push_back(num[deq.front()]);
        }
    }
    return res;
}

int main()
{
    int arr[] = {2, 3, 4, 2, 6, 2, 5, 1};
    vector<int> num(arr, arr+8);
    cout << "the num:" << endl;
    for(unsigned int i=0; i<num.size(); i++){
        cout << num[i] << " ";
    }
    cout << endl;
    cout << "max in windows:" << endl;
    vector<int> res = maxInWindows(num, 3);
    for(unsigned int i=0; i<res.size(); i++){
        cout << res[i] << " ";
    }
    cout << endl;

    return 0;
}