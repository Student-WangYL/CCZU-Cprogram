/*
函数fun的功能是：找出形参s所指字符串中出现频率最高的字母(不区分大小写),可能不止一个，并统计出它们出现的次数。
输入
一行字符串
输出
可能有多行，每一行的格式：字符 次数
*/
#include <stdio.h>
#include <string.h>
void fun(char *s)
{
    int i, j, k, max, count[26] = {0}; // count[26] = {0}，初始化count数组
    char c;                            // c是字符
    for (i = 0; s[i]; i++)             // s[i]是s的第i个元素，s[i] != '\0'，s[i] != 0，s[i] != NULL
    {
        if (s[i] >= 'a' && s[i] <= 'z')      // s[i]是小写字母
            count[s[i] - 'a']++;             // count[s[i] - 'a']是count的第s[i] - 'a'个元素，count[s[i] - 'a']++
        else if (s[i] >= 'A' && s[i] <= 'Z') // s[i]是大写字母
            count[s[i] - 'A']++;             // count[s[i] - 'A']是count的第s[i] - 'A'个元素，count[s[i] - 'A']++
    }
    max = count[0];          // max是count的第0个元素
    for (i = 1; i < 26; i++) // i: 1 -> 25
    {
        if (count[i] > max) // count[i] > max
            max = count[i]; // max = count[i]
    }
    for (i = 0; i < 26; i++) // i: 0 -> 25
    {
        if (count[i] == max)                 // count[i] == max
            printf("%c %d\n", i + 'a', max); // i + 'a'是i + 'a'的ASCII码，printf("%c %d\n", i + 'a', max)
    }
}
int main()
{
    char s[100];
    gets(s);
    fun(s);
    return 0;
}