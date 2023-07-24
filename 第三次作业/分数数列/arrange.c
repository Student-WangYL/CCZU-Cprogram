#include <stdio.h>
int main()
{
    int n;
    double a = 2.0, b = 1.0, sum = 0.0, temp;
    //printf("请输入需要求和的项数N：");
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        sum += a / b; // 累加当前项
        temp = a;     // 记录a的值，用于后续计算下一项
        a = a + b;    // 计算下一项的分子
        b = temp;     // 计算下一项的分母
    }
    printf("%.2lf\n", sum);
    return 0;
}