/*函数fun的功能是：将形参a所指数组中的前半部分元素中的值与后半部分元素中的值对换。形参n中存放数组中数据的个数，若n为奇数，则中间的元素不动。
输入输出要求：第一行输入元素个数，第二行输入每个元素值，第三行输出交换的值。
样例输入输出：
8
1 2 3 4 5 6 7 8
    5    6    7    8    1    2    3    4
注意：部分源程序存在文件prog.c中。程序的主要框架已经给出，请仅在
    **********  Begin  **********

    **********   End  ***********
注释对之间的空行中添加你的代码，任何修改该两行注释，以及修改注释外代码均将被判失败
*/
#include <stdio.h>
#define N 100
void fun(int a[], int n)
{
    /**********  Begin  **********/
    int i, j, temp;
    for (i = 0; i < n / 2; i++)
    {
        temp = a[i];
        a[i] = a[i + n / 2];
        a[i + n / 2] = temp;
    }
    /**********   End  ***********/
}
main()
{
    int b[N], i, n;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
        scanf("%d", &b[i]);
    fun(b, n);
    for (i = 0; i < n; i++)
        printf("%4d ", b[i]);
    printf("\n");
    NONO();
}
NONO()
{
    FILE *rf, *wf;
    int b[N], i, n, SampleCount;
    ;
    rf = fopen("bc.in", "r");
    wf = fopen("bc.out", "w");
    if (rf == NULL || wf == NULL)
        printf("文件打开失败");
    for (SampleCount = 1; SampleCount <= 2; SampleCount++)
    {
        fscanf(rf, "%d", &n);
        for (i = 0; i < n; i++)
            fscanf(rf, "%d", &b[i]);
        fun(b, n);
        for (i = 0; i < n; i++)
            fprintf(wf, "%4d ", b[i]);
        fprintf(wf, "\n");
    }
    fclose(rf);
    fclose(wf);
}