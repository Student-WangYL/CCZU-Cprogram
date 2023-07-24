/*------------------------------------------------------
【程序设计】
--------------------------------------------------------
功能：删去一维数组中所有重复的数，只保留不同的数。
数组中的数已按由小到大的顺序排列，
函数返回删除后数组中数据的个数。
例如：一维数组中的数据是: 2 2 2 3 4 4 5 6 6 6 6 7 7 8 9 9 10 10 10。
删除后，数组中的内容应该是: 2 3 4 5 6 7 8 9 10。
注意：请勿改动主函数main和其它函数中的任何内容。
*********Begin**********和**********  End  **********不可删除

------------------------------------------------------*/
#include "stdio.h"
#define N 80
void TestFunc();
int fun(int a[], int n)
{
    /*********Begin**********/
    int i, j, k = 0;
    for (i = 0; i < n - 1; i++)
    {
        if (a[i] != a[i + 1])
        {
            a[k] = a[i];
            k++;
        }
    }
    a[k] = a[i];
    return k + 1;
    /**********  End  **********/
}

int main()
{
    void TestFunc();
    int a[N] = {2, 2, 2, 3, 4, 4, 5, 6, 6, 6, 6, 7, 7, 8, 9, 9, 10, 10, 10, 10}, i, n = 20;
    printf("The original data:\n");
    for (i = 0; i < n; i++)
        printf("%3d", a[i]);
    n = fun(a, n);
    printf("\n\nThe data after deleted:\n");
    for (i = 0; i < n; i++)
        printf("%3d", a[i]);
    printf("\n\n");
    TestFunc();
}

void TestFunc()
{
    FILE *IN, *OUT;
    int a[N];
    int n;
    int i;
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
    fscanf(IN, "%d", &n);
    for (i = 0; i < n; i++)
        fscanf(IN, "%d", &a[i]);
    n = fun(a, n);
    for (i = 0; i < n; i++)
        fprintf(OUT, "%3d", a[i]);
    fclose(IN);
    fclose(OUT);
}