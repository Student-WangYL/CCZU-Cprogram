#include <stdio.h>
int main(void)
{
    int num[100];                // 定义足够大的范围
    for (int i = 0; i <= 8; i++) // i用完丢弃
    {
        scanf("%d", &num[i]); // 定义足够大的范围
    }
    int target;              // 定义插入值
    scanf("%d", &target);    // 输入插入值
    int i;                   // i记录数组
    for (i = 0; i <= 9; i++) // 循环遍历数组
    {
        if (num[i] > target) // 当找到一个数比插入数大时,退出
        {
            break;
        }
    }
    for (int j = 8; j >= i; j--) // 逆向遍历数组
    {
        num[j + 1] = num[j]; // 将数组后移
    }
    num[i] = target;
    for (int i = 0; i <= 9; i++) // 遍历输出
    {
        printf("%d\n", num[i]);
    }
    return 0;
}