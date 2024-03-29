#include <stdio.h>
#define N 6

void AnDian(int a[][N], int m, int n)
{
    int i, j, k, max, flag;
    int saddle_points = 0;
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            max = a[i][j];
            flag = 1;
            // 检查当前元素是否是其行中最大的
            for (k = 0; k < n; k++)
            {
                if (a[i][k] > max)
                {
                    flag = 0;
                    break;
                }
            }
            // 检查当前元素是否是其列中最小的
            if (flag)
            {
                for (k = 0; k < m; k++)
                {
                    if (a[k][j] < max)
                    {
                        flag = 0;
                        break;
                    }
                }
            }
            // 如果是马鞍点，请打印出来
            if (flag)
            {
                printf("AnDdian %d: value=%d, (%d,%d)\n\n", ++saddle_points, max, i + 1, j + 1);
            }
        }
    }
    if (saddle_points == 0)
    {
        printf("NO\n");
    }
}

int main()
{
    int m, n;
    int matrix[N][N];
    scanf("%d,%d", &m, &n);
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }
    AnDian(matrix, m, n);
    return 0;
}