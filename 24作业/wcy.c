#include <stdio.h>

// 声明 GetSum 函数
int GetSum(int a[][3], int m, int n, int b[]);

int main()
{
    int arr[3][3]; // 定义一个3行3列的二维数组
    int i, j;
    int sums[6]; // 用于存储各行和各列之和的一维数组

    // 循环输入3行3列的整型数据
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }

    // 调用 GetSum 函数并存储结果
    int count = GetSum(arr, 3, 3, sums);

    // 输出各行之和
    printf("各行之和： ");
    for (i = 0; i < count; i++)
    {
        printf("%d ", sums[i]);
    }
    printf("\n");

    // 输出各列之和
    printf("各列之和： ");
    for (i = count; i < 2 * count; i++)
    {
        printf("%d ", sums[i]);
    }
    printf("\n");

    return 0;
}

// 定义 GetSum 函数
int GetSum(int a[][3], int m, int n, int b[])
{
    int i, j;
    int sumRow = 0, sumCol = 0;
    int k = 0;

    // 计算各行之和
    for (i = 0; i < m; i++)
    {
        sumRow = 0;
        for (j = 0; j < n; j++)
        {
            sumRow += a[i][j];
        }
        b[k++] = sumRow;
    }

    // 计算各列之和
    for (j = 0; j < n; j++)
    {
        sumCol = 0;
        for (i = 0; i < m; i++)
        {
            sumCol += a[i][j];
        }
        b[k++] = sumCol;
    }

    // 返回和的个数
    return k;
}
