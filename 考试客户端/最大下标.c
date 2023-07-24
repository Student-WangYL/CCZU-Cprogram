/*    请编写一个函数fun，它的功能是：找出一维整型数组元素中最大的值和它所在的下标，
最大的值和它所在的下标通过形参传回。数组元素中的值已在主函数中赋予。主函数中x是数组名，n是
x中的数据个数，max存放最大值，index存放最大值所在元素的下标。

输入输出格式样例：
  47  12  16  37  14  34  15  15  19  16
Max =   47 ,  Index =   0
Press any key to continue

其中Press any key to continue是计算机结束程序时的输出.
注意：部分源程序存在文件prog.c中。程序的主要框架已经给出，请仅在
    **********  Begin  **********

    **********   End  ***********
注释对之间的空行中添加你的代码，任何修改该两行注释，以及修改注释外代码均将被判失败
*/

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
void fun(int a[], int n, int *max, int *d)
{

    /**********  Begin  **********/
    int i;
    *max = a[0];
    *d = 0;
    for (i = 0; i < n; i++)
    {
        if (a[i] > *max)
        {
            *max = a[i];
            *d = i;
        }
    }
    /**********   End  ***********/
}
void NONO()
{ /* 本函数用于打开文件，输入数据，调用函数，输出数据，关闭文件。 */
    FILE *fp, *wf;
    int i, x[20], max, index, n = 10, j;

    fp = fopen("bc06.in", "r");
    if (fp == NULL)
    {
        printf("数据文件bc06.in不存在!");
        return;
    }
    wf = fopen("bc06.out", "w");
    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < n; j++)
            fscanf(fp, "%d,", &x[j]);
        fun(x, n, &max, &index);
        fprintf(wf, "Max=%d,Index=%d\n", max, index);
    }
    fclose(fp);
    fclose(wf);
}

main()
{
    int i, x[20], max, index, n = 10;
    srand(time(0));
    for (i = 0; i < n; i++)
    {
        x[i] = rand() % 50;
        printf("%4d", x[i]);
    }
    printf("\n");
    fun(x, n, &max, &index);
    printf("Max =%5d ,  Index =%4d\n", max, index);
    NONO();
}