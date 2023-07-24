/*
请编一个函数fun(char *s)，函数的功能是把字符串中的内容逆置。

输入输出格式样例：
Enter a string: abcdefg
The original string is:  abcdefg

The string after modified:  gfedcba
Press any key to continue

其中Press any key to continue是计算机结束程序时的输出.
注意：部分源程序存在文件prog.c中。程序的主要框架已经给出，请仅在
    **********  Begin  **********

    **********   End  ***********
注释对之间的空行中添加你的代码，任何修改该两行注释，以及修改注释外代码均将被判失败
*/

#include <string.h>
#include <conio.h>
#include <stdio.h>
#include <windows.h>
#define N 81
fun(char *s)
{

    /**********  Begin  **********/
    int i, j, k;
    char temp;
    k = strlen(s);
    for (i = 0, j = k - 1; i < j; i++, j--)
    {
        temp = s[i];
        s[i] = s[j];
        s[j] = temp;
    }
    /**********   End  ***********/
}

NONO()
{ /* 请在此函数内打开文件，输入测试数据，调用 fun 函数，
     输出数据，关闭文件。 */
    int i;
    char a[N];
    FILE *rf, *wf;

    rf = fopen("bc8.in", "r");
    wf = fopen("bc8.out", "w");
    for (i = 0; i < 9; i++)
    {
        fscanf(rf, "%s", a);
        fun(a);
        fprintf(wf, "%s\n", a);
    }
    fclose(rf);
    fclose(wf);
}

main()
{
    char a[N];
    system("cls");
    printf("Enter a string: ");
    gets(a);
    printf("The original string is:  ");
    puts(a);
    fun(a);
    printf("\n");
    printf("The string after modified:  ");
    puts(a);
    NONO();
}