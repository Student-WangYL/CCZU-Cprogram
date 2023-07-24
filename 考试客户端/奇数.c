/*    函数fun的功能是：将s所指字符串中下标为奇数的字符删除，串中剩余字符形成一个新串放在t所指的数组中。
    例如，当s所指字符串为："ABCDEFGHIJK"时，t所指的数组的内容应是："ACEGIK"。
    注意：部分源程序存在文件prog.c中。
    请勿改动主函数main和其他函数中的任何内容，仅在函数fun的花括号中填入你编写的若干语句。*/

#include <conio.h>
#include <stdio.h>
#include <string.h>
#include <windows.h>
void fun(char *s, char t[])
{
    /**********  Begin  **********/
    int i, j = 0;
    for (i = 0; i < strlen(s); i++)
    {
        if (i % 2 == 0)
            t[j++] = s[i];
    }
    t[j] = '\0';
    /**********   End  ***********/
}

NONO()
{ /* 本函数用于打开文件，输入数据，调用函数，输出数据，关闭文件。 */
    char s[100], t[100];
    FILE *rf, *wf;
    int i;

    rf = fopen("bc01.dat", "r");
    wf = fopen("bc01.out", "w");
    for (i = 0; i < 10; i++)
    {
        fscanf(rf, "%s", s);
        fun(s, t);
        fprintf(wf, "%s\n", t);
    }
    fclose(rf);
    fclose(wf);
}

main()
{
    char s[100], t[100];
    system("cls");
    printf("\nPlease enter string S:");
    scanf("%s", s);
    fun(s, t);
    printf("\nThe result is: %s\n", t);
    NONO();
}