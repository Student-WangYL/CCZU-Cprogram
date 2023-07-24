/*------------------------------------------------------------------------------------
编写函数fun，它的功能是：求n以内（不包括n）同时能被3与7整除的所有自然数之和的平方根s，
    并作为函数值返回。输出保留两位小数。

输入输出样例：

以上样例中，第1行是用户输入的数据。
第2行是输出的数据。

程序的主要框架已经给出，请仅在
    **********  Begin  **********

    **********   End  ***********
之间的空行中添加你的代码，任何修改该两行注释，以及修改注释外代码均将被判失败
---------------------------------------------------------------------------------*/

#include <math.h>
#include <stdio.h>
void bky();
double fun(int n)
{

    /**********  Begin  **********/
    int a, b = 0;
    double s;
    for (a = 1; a < n; a++)
    {
        if (a % 3 == 0 && a % 7 == 0)
            b = b + a;
    }
    s = sqrt(b);
    return s;

    /**********   End  ***********/
}

void main()
{
    int n;
    scanf("%d", &n);
    printf("s=%.2f\n", fun(n));
    bky();
}
void bky()
{
    FILE *IN, *OUT;
    int i;
    int t;
    double o;
    IN = fopen("in.dat", "r");
    if (IN == NULL)
    {
        printf("Read FILE Error");
    }
    OUT = fopen("out.dat", "w");
    if (OUT == NULL)
    {
        printf("Write FILE Error");
    }
    for (i = 0; i < 6; i++)
    {
        fscanf(IN, "%d", &t);
        o = fun(t);
        fprintf(OUT, "%.2f\n", o);
    }
    fclose(IN);
    fclose(OUT);
}