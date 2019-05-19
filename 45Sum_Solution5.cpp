/*
求1+2+3+...+n，要求不能使用乘除法、for、while、if、else、switch、case等关键字及条件判断语句（A?B:C）。
*/
/*
利用模板类型求解  让编译器帮助完成类似于递归的计算。
*/
#include <iostream>
using namespace std;
/*Sum_Solution<100>::N就是1+2+...+100的结果。当编译器看到Sum_Solution<100>时，就会为模板类
Sum_Solution以参数100生成该类型的代码。但以100为参数的类型需要得到以99为参数的类型，因为
Sum_Solution<100>::N=Sum_Solution<99>::N+100。这个过程会递归一直到参数为1的类型，由于该类型
已经显示定义，编译器无需生成，递归编译到此结束。由于这个过程是在编译过程中完成的，因此要求输入n
必须是在编译期间就能确定的常量，不能动态输入，是该方法最大的缺点。*/
template <unsigned int n> struct Sum_Solution{
    enum Value{
        N = Sum_Solution<n - 1>::N + n
    };
};

template <> struct Sum_Solution<1>{
    enum Value{N = 1};
};

int main()
{
    cout << Sum_Solution<3>::N << endl;
    cout << Sum_Solution<5>::N << endl;
    return 0;
}