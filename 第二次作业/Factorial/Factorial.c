#include<stdio.h>
int main(void)
{
    int n,fac;//定义输入值,阶乘值
    scanf("%d", &n);
    for (int i = 1; i <= n;i++)
    {
        fac *= i;

    }
    printf("%d", fac);
    return 0;
}