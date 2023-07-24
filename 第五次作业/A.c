/*字符函数之求单词个数

定义单词为一串连续的字母.单词内不含非字母字符.
输入一个字符串,在函数内求串中单词的个数

输入输出样例：
hello world
total word= 2

程序的主要框架已经给出，请仅在
    **********  Begin  **********

    **********   End  ***********
  注释对之间的空行中添加你的代码，任何修改该两行注释，以及修改注释外代码均将被判失败
*/

#include <math.h>
#include <stdio.h>
#include <ctype.h>
#define N 256
#define BUFSZ N
int fun(char *p)
{
    /**********  Begin  **********/
    int i, count = 0;
    for (i = 0; p[i] != '\0'; i++)// 遍历字符串
    {
        if (isalpha(p[i]) && !isalpha(p[i + 1])) // 相邻字母一个是字母一个不是字母
            count++;
    }
    return count;
    /**********   End  ***********/
}
void f()
{
    char s[256];
    gets(s);
    printf("total word= %d\n", fun(s));
}
int main()
{
    f();
    return 0;
}