#include <stdio.h>
#include <math.h>

int main()
{
    double a, xn, xn_1 = 1.0; // xn_1初始值可以为任意正数
    //printf("请输入一个正数：");
    scanf("%lf", &a);
    do
    {
        xn = xn_1;                        // 更新xn的值
        xn_1 = 0.5 * (xn + a / xn);       // 计算下一项
    } while (fabs(xn_1 - xn) >= 0.00001); // 判断两次结果的差的绝对值是否小于0.00001
    printf("%.3lf\n", xn_1);
    return 0;
}