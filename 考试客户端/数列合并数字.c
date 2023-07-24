/*    请编写函数fun，函数的功能是：将M行N列的二维数组中的数据按列的顺序依次放到一维数组中。
   例如，二维数组中的数据为：
        33  33  33  33
        44  44  44  44
        55  55  55  55
   则一维数组中的内容应是：
   33  44  55  33  44  55  33  44  55  33  44  55。
   注意：部分源程序存在文件prog.c中。
   请勿改动主函数main和其它函数中的任何内容，仅在函数fun的花括号中填入你编写的若干语句。*/

#include <stdio.h>
void fun(int (*s)[10], int *b, int *n, int mm, int nn)
{
    /**********  Begin  **********/
    int i, j;
    for (i = 0; i < nn; i++)
    {
        for (j = 0; j < mm; j++)
        {
            b[*n] = s[j][i];
            (*n)++;
        }
    }
    /**********   End  ***********/
}

NONO()
{
    /* 请在此函数内打开文件，输入测试数据，调用 fun 函数，输出数据，关闭文件。 */
    FILE *rf, *wf;
    int i, j, k;
    int w[10][10], a[100], n = 0, mm, nn;
    rf = fopen("bc.in", "r");
    wf = fopen("bc.out", "w");
    for (k = 0; k < 5; k++)
    {
        fscanf(rf, "%d %d", &mm, &nn);
        for (i = 0; i < mm; i++)
            for (j = 0; j < nn; j++)
                fscanf(rf, "%d", &w[i][j]);
        n = 0;
        fun(w, a, &n, mm, nn);
        for (i = 0; i < n; i++)
            fprintf(wf, "%3d", a[i]);
        fprintf(wf, "\n");
    }
    fclose(rf);
    fclose(wf);
}

main()
{
    int w[10][10] = {{33, 33, 33, 33}, {44, 44, 44, 44}, {55, 55, 55, 55}}, i, j;
    int a[100] = {0}, n = 0;
    printf("The matrix:\n");
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 4; j++)
            printf("%3d", w[i][j]);
        printf("\n");
    }
    fun(w, a, &n, 3, 4);
    printf("The A array:\n");
    for (i = 0; i < n; i++)
        printf("%3d", a[i]);
    printf("\n\n");
    NONO();
}