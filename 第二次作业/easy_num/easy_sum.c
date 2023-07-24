#include <stdio.h>
int main(void)
{
    int n, i, j, sum = 0, num; // 初始化和为0
    scanf("%d", &n);           // 输入正整数
    for (i = 1; i < 10; i++)
    { // 第一位数的范围是0~9
        for (j = 0; j < 10; j++)
        { // 第二位数的范围也是0~9
            if (i + j == n)
            {                     // 如果两位数的和为n
                num = i * 10 + j; // 计算这个两位数
                sum += num;       // 将这个两位数累加到和中
            }
        }
    }
    printf("%d", sum); // 输出和
    return 0;
}
