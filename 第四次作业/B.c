/*题目描述
    输入n，在一个二维数组中形成并输出如下所示的n*n矩阵（假定n<=6)
    输入
    输入n的值（如6）
    输出
    1 1 1 1 1 1
    1 2 2 2 2 1
    1 2 3 3 2 1
    1 2 3 3 2 1
    1 2 2 2 2 1
    1 1 1 1 1 1
    样例输入
    6
    样例输出
    1 1 1 1 1 1
    1 2 2 2 2 1
    1 2 3 3 2 1
    1 2 3 3 2 1
    1 2 2 2 2 1
    1 1 1 1 1 1
*/
#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    int matrix[n][n]; // 二维数组存储矩阵

    int i, j, min;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            min = i < j ? i : j; // 计算当前位置到边界的最短距离
            min = min < n - i ? min : n - i - 1;
            min = min < n - j - 1 ? min : n - j - 1;
            matrix[i][j] = min + 1; // 根据最短距离确定数值
        }
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}
/*
解释一下代码的思路：
首先读入n，声明一个n*n的二维数组用于存储矩阵。
然后使用两个for循环遍历整个矩阵，计算每个位置到边界的最短距离。这个最短距离可以通过比较当前位置到四个边界的距离来得到。
最后根据最短距离确定当前位置的数值，并将其存入二维数组中。
最后再使用两个for循环遍历整个矩阵，输出每个位置的数值即可。*/