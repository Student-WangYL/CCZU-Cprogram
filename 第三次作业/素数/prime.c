#include <stdio.h>

int fun(int n)
{
    if (n <= 1)
        return 0; // 1不是素数，小于等于1的数也不是素数
    for (int i = 2; i * i <= n; i++)
    { // 只需判断到sqrt(n)即可
        if (n % i == 0)
            return 0; // n能被i整除，说明n不是素数
    }
    return 1; // n不能被2~sqrt(n)中的任何一个整数整除，说明n是素数
}

int main()
{
    int n, m;
    scanf("%d,%d", &n, &m);
    for (int i = n; i <= m; i++)
    {
        if (fun(i))
            printf("%d ", i);
    }
    return 0;
}