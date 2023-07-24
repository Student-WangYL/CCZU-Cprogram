#include <stdio.h>
int gcd(int a, int b);
int lcm(int a, int b);
int main()
{ 
    int a, b;
    scanf("%d%d", &a, &b);
    printf("gbs=%d,", lcm(a, b));
    printf("gys=%d", gcd(a, b));
    return 0;
}

int gcd(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    else
    {
        return gcd(b, a % b);
    }
}

int lcm(int a, int b)
{
    return a * b / gcd(a, b); // 最小公倍数等于两个数的乘积除以它们的最大公约数
}
