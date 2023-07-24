/*输入一串字符串，将其中大写字母取出构成第二个字符串，并输出删除大写字母的字符串和大写字母。
分拣工作由函数fun完成，fun框架和主调函数已经给出。请仅在注释对中填写你的代码
*/
#include <stdio.h>
void fun(char a[], char b[])
{
    /****** your code start here   *****/
    int i, j;                     // i: a的下标，j: b的下标
    for (i = 0, j = 0; a[i]; i++) // a[i]是a的第i个元素，a[i] != '\0'，a[i] != 0，a[i] != NULL
    {
        if (a[i] >= 'A' && a[i] <= 'Z') // a[i]是大写字母
            b[j++] = a[i];              // b[j]是b的第j个元素，b[j] = a[i]，j++
    }
    b[j] = '\0';                  // b[j]是b的第j个元素，b[j] = '\0'
    for (i = 0, j = 0; a[i]; i++) // a[i]是a的第i个元素，a[i] != '\0'，a[i] != 0，a[i] != NULL
    {
        if (a[i] < 'A' || a[i] > 'Z') // a[i]不是大写字母
            a[j++] = a[i];            // a[j]是a的第j个元素，a[j] = a[i]，j++
    }
    a[j] = '\0'; // a[j]是a的第j个元素，a[j] = '\0'
    /******  your code end  *****/
}
int main()
{
    char a[1024], b[1024];
    gets(a);
    fun(a, b);
    puts(a);
    puts(b);
    return 0;
}
