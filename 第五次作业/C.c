/*题目描述
输入一个字符串，删除该串最左边的空格并输出
输入
一个含有空格的字符串
输出
去掉最左边的空格后的字符串
样例输入 复制
    Hello  Boys.
样例输出 复制
Hello  Boys.
提示
使用追赶指针
*/
#include <stdio.h>
#include <ctype.h>
int main(void)
{
    char s[256];
    scanf("%[^\n]", s); //%[^+我们需要停止的字符] scanf的格式化输入
    char *p = s;        // 指针指向字符串的首地址
    while (isspace(*p)) // 指针指向的字符是空格
        p++;
    printf("%s\n", p);
    return 0;
}