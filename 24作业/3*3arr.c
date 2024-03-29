#include <stdio.h>
#include <stdlib.h>
#include <time.h>

float GetAvg(int a[][6], int m, int n)
{
    int i, j, sum = 0;
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (i == 0 || i == m - 1 || j == 0 || j == n - 1)
            {
                sum += a[i][j];
            }
        }
    }
    return sum / (m * n);
}

int main()
{
    int m, n, i, j;
    scanf("%d %d", &m, &n);

    int a[6][6];

    // 设置随机种子
    srand(824);

    // 生成并打印M*N矩阵
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            a[i][j] = rand() % 10;
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }

    // 计算并输出周边元素的平均值
    float avg = GetAvg(a, m, n);
    printf("%.2f\n", avg);

    return 0;
}
