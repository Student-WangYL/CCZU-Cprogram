#include<stdio.h>
#include <math.h>
int main()
{
    int a, n, i, num, sum;//输入a,重复次数n,累加器,变换后的数字,和
    int b = 0;//递增数
    scanf("%d%d", &a, &n);
    num = a;
    sum = 0;
    for (i = 1; i <= n; i++)
    {
        sum += num;
        b = pow(10, i);
        num = a * b + num;
    }
    printf("%d", sum);
    return 0;
}