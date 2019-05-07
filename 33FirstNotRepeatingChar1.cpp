/*
在一个字符串(0<=字符串长度<=10000，全部由字母组成)中找到第一个只出现一次的字符,并返回它的位置, 
如果没有则返回 -1（需要区分大小写）.
*/
#include <iostream>
#include <string>
using namespace std;

int FirstNotRepeatingChar(string str)
    {
        if(str.length( ) == 0)
        {
            return -1;
        }

        unsigned int length = str.length( );
        unsigned int i, j;
        bool isrepeat = false;


        for(i = 0; i < length; i++)
        {
            isrepeat = false;
            if(str[i] == '\0')
            {
                continue;
            }

            //  堆每一个当前字符i判断其后面有没有跟它相同的字符
            for(j = i + 1; j < length; j++)
            {
                if(str[j] == '\0')
                {
                    continue;
                }
                else if(str[i] == str[j])   // 将所有与当前i位置字符相同的字符都置为'\0'
                {
                    str[j] = '\0';
                    isrepeat = true;
                }
            }
            if(isrepeat == false)
            {
                return i;
            }
        }
        return -1;
    }

int main()
{
    cout << FirstNotRepeatingChar("allen930422@gmail.com") << endl;
    return 0;
}