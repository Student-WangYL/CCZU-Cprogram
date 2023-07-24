/*指针应用之二维数组转置

输入方阵的阶n(n<40),并输入这n阶方阵,输出该方阵的转置.

输入输出样例：
请输入方阵的阶n(n<40):3
1 2 3
4 5 66
7 8 9
转置结果为:
1 4 7
2 5 8
3 66 9
Press any key to continue

其中所有的中文均为计算机提示用户的输入.
最后一行的Press any key to continue是计算机结束程序时的输出.

程序的主要框架已经给出，请仅在

    **********  Begin  **********

    **********   End  ***********
  注释对之间的空行中添加你的代码，任何修改该两行注释，以及修改注释外代码均将被判失败
*/

#include <stdio.h>
#define N 40
void f(int *p, int n)
{
    /**********  Begin  **********/
    int i, j, temp;
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < i; j++)
        {
            temp = *(p + i * N + j);
            *(p + i * N + j) = *(p + j * N + i);
            *(p + j * N + i) = temp;
        }
    }
    /**********   End  ***********/
}
int main()
{
    int a[N][N], n, i, j;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &a[i][j]);
    f(&a[0][0], n);
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
            printf("%d ", a[i][j]);
        printf("\n");
    }
    return 0;
}