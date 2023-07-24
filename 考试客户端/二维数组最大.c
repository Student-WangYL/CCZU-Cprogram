/*------------------------------------------------
【程序设计】
--------------------------------------------------

题目：请编一个函数
      void fun(int tt[M][N],int pp[N]),
      tt指向一个M行N列的二维数组，求出
      二维数组每列中最大元素，并依次放
      入pp所指一维数组中。二维数组中的
      数已在主函数中赋予。
--------------------------------------------------
注意：部分源程序给出如下。请勿改动主函数main
      和其它函数中的任何内容，仅在函数fun的花
      括号中填入所编写的若干语句。
*********Begin**********和**********  End  **********不可删除

------------------------------------------------*/
#include <conio.h>
#include <stdio.h>
#define M 3
#define N 4
void NONO();
void fun(int tt[M][N], int pp[N])
{
    /**********Begin**********/
    int i, j;
    for (j = 0; j < N; j++)
    {
        pp[j] = tt[0][j];
        for (i = 1; i < M; i++)
        {
            if (tt[i][j] > pp[j])
                pp[j] = tt[i][j];
        }
    }
    /**********  End  **********/
}
main()
{
    int t[M][N] = {{22, 45, 56, 30},
                   {19, 33, 45, 38},
                   {20, 22, 66, 40}};
    int p[N], i, j, k;
    // clrscr();
    printf("The original data is:\n");
    for (i = 0; i < M; i++)
    {
        for (j = 0; j < N; j++)
            printf("%6d", t[i][j]);
        printf("\n");
    }
    fun(t, p);
    printf("\nThe result is:\n");
    for (k = 0; k < N; k++)
        printf("%4d", p[k]);
    printf("\n");
    // getch();
    NONO();
}
void NONO()
{

    int i, j, array[3][4], p[4];
    FILE *rf, *wf;
    rf = fopen("in.dat", "r");
    wf = fopen("out.dat", "w");
    for (i = 0; i < 3; i++)
        for (j = 0; j < 4; j++)
            fscanf(rf, "%d", &array[i][j]);
    fun(array, p);
    for (j = 0; j < 4; j++)

    {
        fprintf(wf, "%7d", p[j]);
        fprintf(wf, "\n");
    }
    fclose(rf);
    fclose(wf);
}