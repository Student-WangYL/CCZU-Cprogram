/*    请编写函数fun，函数的功能是：将M行N列的二维数组中的字符数据按列的顺序依次放到一个字符串中。
    例如，二维数组中的数据为：
         W  W  W  W
         S  S  S  S
         H  H  H  H
    则字符串中的内容应是：WSHWSHWSHWSH。
    注意：部分源程序存在文件prog.c中。
    请勿改动主函数main和其它函数中的任何内容，仅在函数fun的花括号中填入你编写的若干语句。*/

#include <stdio.h>
#define M 3
#define N 4
void fun(char (*s)[N], char *b)
{
    /**********  Begin  **********/
    int i, j, k = 0;
    for (j = 0; j < N; j++)
        for (i = 0; i < M; i++)
            b[k++] = s[i][j];
    b[k] = '\0';
    /**********   End  ***********/
}

NONO()
{ /* 请在此函数内打开文件，输入测试数据，调用 fun 函数，输出数据，关闭文件。 */
    FILE *rf, *wf;
    int i, j, k;
    char a[100], w[M][N], b;
    rf = fopen("bc.in", "r");
    wf = fopen("bc.out", "w");
    for (k = 0; k < 10; k++)
    {
        for (i = 0; i < M; i++)
        {
            for (j = 0; j < N; j++)
                fscanf(rf, "%c", &w[i][j]);
            fscanf(rf, "%c", &b);
        }
        fun(w, a);
        fprintf(wf, "%s\n", a);
    }
    fclose(rf);
    fclose(wf);
}

main()
{
    char a[100], w[M][N] = {{'W', 'W', 'W', 'W'}, {'S', 'S', 'S', 'S'}, {'H', 'H', 'H', 'H'}};
    int i, j;
    printf("The matrix:\n");
    for (i = 0; i < M; i++)
    {
        for (j = 0; j < N; j++)
            printf("%3c", w[i][j]);
        printf("\n");
    }
    fun(w, a);
    printf("The A string:\n");
    puts(a);
    printf("\n\n");
    NONO();
}