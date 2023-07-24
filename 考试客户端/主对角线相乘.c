/*------------------------------------------------
【程序设计】
--------------------------------------------------

题目：fun函数的功能是，计算二维数组主对角线元素的乘积。

例如：输入如下数据
1 2 3
4 5 6
7 8 9
输出：  Multi=45
*********Begin**********和**********  End  **********不可删除




------------------------------------------------*/

#include "stdio.h"

int fun(int a[3][3])
{
    /**********Begin**********/
    int i,s = 1;
    for (i = 0; i < 3; i++)
    {
        s *= a[i][i];
    }
    return s;
    /**********  End  **********/
}

main()
{
    int i, j, s, a[3][3];
    ;
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
            scanf("%d", &a[i][j]);
    }
    s = fun(a);
    printf("Multi=%d\n", s);
    yzj();
}

yzj()
{
    FILE *IN, *OUT;
    int m;
    int n;
    int i[3][3];
    int o;
    IN = fopen("in.dat", "r");
    if (IN == NULL)
    {
        printf("Read File Error");
    }
    OUT = fopen("out.dat", "w");
    if (OUT == NULL)
    {
        printf("Write File Error");
    }
    for (m = 0; m < 3; m++)
    {
        for (n = 0; n < 3; n++)
            fscanf(IN, "%d", &i[m][n]);
    }
    o = fun(i);
    {
        fprintf(OUT, "%d\n", o);
        getch();
    }
    fclose(IN);
    fclose(OUT);
}