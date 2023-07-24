/*    请编写一个函数void fun(char *tt,int pp[])，统计在tt字符串中'a'到'z'26个字母各自
出现的次数，并依次放在pp所指数组中。

输入输出格式样例：
Please enter a char string;abcdefgabcdeabc
33322110000000000000000000
Press any key to continue

其中Press any key to continue是计算机结束程序时的输出.
注意：部分源程序存在文件prog.c中。程序的主要框架已经给出，请仅在
    **********  Begin  **********

    **********   End  ***********
注释对之间的空行中添加你的代码，任何修改该两行注释，以及修改注释外代码均将被判失败
*/

#include <conio.h>
#include <stdio.h>
#include <windows.h>
void fun(char *tt, int pp[])
{

    /**********  Begin  **********/
    int i;
    for (i = 0; i < 26; i++)
        pp[i] = 0;
    for (i = 0; tt[i] != '\0'; i++)
    {
        if (tt[i] >= 'a' && tt[i] <= 'z')
            pp[tt[i] - 'a']++;
    }
    /**********   End  ***********/
}

NONO()
{ /* 本函数用于打开文件，输入测试数据，调用fun函数，输出数据，关闭文件。*/
    char aa[1000];
    int bb[26], k, i;
    FILE *rf, *wf;

    rf = fopen("bc07.in", "r");
    wf = fopen("bc07.out", "w");
    for (i = 0; i < 10; i++)
    {
        fscanf(rf, "%s", aa);
        fun(aa, bb);
        for (k = 0; k < 26; k++)
            fprintf(wf, "%d ", bb[k]);
        fprintf(wf, "\n");
    }
    fclose(rf);
    fclose(wf);
}

main()
{
    char aa[1000];
    int bb[26], k;
    printf("Please enter a char string;");
    scanf("%s", aa);
    fun(aa, bb);
    for (k = 0; k < 26; k++)
        printf("%d", bb[k]);
    printf("\n");
    NONO();
}