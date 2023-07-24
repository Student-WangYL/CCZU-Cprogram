#include <stdio.h>
int main(void)
{
    int n, ex_fac = 1, sum = 0; // 定义输入,单阶乘,阶乘和
    scanf("%d", &n);
    int i, j;                // 定义累计器
    for (i = 1; i <= n; i++) // 数组和
    {
        ex_fac = 1;              // 重制初始值为1
        for (j = 1; j <= i; j++) // 阶乘
        {
            ex_fac *= j;
        }
        sum += ex_fac;
    }
    printf("%d", sum);
    return 0;
}