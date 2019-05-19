/*
请实现一个函数用来找出字符流中第一个只出现一次的字符。例如，当从字符流中只读出前两个字符"go"时，
第一个只出现一次的字符是"g"。当从该字符流中读出前六个字符“google"时，第一个只出现一次的字符是"l"。
如果当前字符流没有存在出现一次的字符，返回#字符。
*/
/*
字符只能一个接着一个从字符流中读取出来，因此我们可以定义一个数据容器来保存字符在字符流中的位置
，当一个字符第一次从字符流中出来的时候，把它保存在字符流中的位置保存到容器中。
当这个字符再次从字符流中被读取出来的时候，那么它就不是只出现一次的字符，也就是被忽略了。这时候就
把在数据容器里保存的值更新成一个特殊的值即可。
*/
#include <iostream>
#include <cstring>
using namespace std;

string str = "";
int count[256];
//memset(count, '\0', sizeof(count));
//Insert one char from stringstream
void Insert(char ch)
{
    str += ch;
    count[(int)ch]++;
}
  //return the first appearence once char in current stringstream
char FirstAppearingOnce()
{
    int len = str.size();
    for(int i=0; i<len; i++){
        if(count[(int)str[i]] == 1){
            return str[i];
        }
    }
    return '#';
}

int main()
{
    Insert('g');
    cout << FirstAppearingOnce() << endl;
    Insert('o');
    cout << FirstAppearingOnce() << endl;
    Insert('o');
    cout << FirstAppearingOnce() << endl;
    Insert('g');
    cout << FirstAppearingOnce() << endl;
    Insert('l');
    cout << FirstAppearingOnce() << endl;
    Insert('e');
    cout << FirstAppearingOnce() << endl;

    return 0;
}