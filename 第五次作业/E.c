/* T7_16
蛇形矩阵

输入行数n和列数m,（n,m<10）生成蛇形矩阵

输入输出样例：
5,6
1 2 3 4 5 6
12 11 10 9 8 7
13 14 15 16 17 18
24 23 22 21 20 19
25 26 27 28 29 30


程序的主要框架已经给出，请仅在
**********  Begin  **********

**********   End  ***********
注意:
1、注释对之间的空行中添加你的代码，任何修改该两行注释，以及修改注释外代码均将被判失败。
3、请注意必要的输入输出格式。

*/
/*样例输入
5, 6
样例输出
1 2 3 4 5 6
12 11 10 9 8 7
13 14 15 16 17 18
24 23 22 21 20 19
25 26 27 28 29 30

*/
#include <stdio.h>
#define N 10
void f()
{
    /**********  Begin  **********/
    int n, m, i, j, k, a[N][N] = {0}; // a[N][N] = {0}是为了防止出现未定义的值
    scanf("%d,%d", &n, &m);
    for (i = 0, k = 0; i < n; i++) // k是用来计数的
    {
        if (i % 2 == 0) // i是偶数时，从左到右
        {
            for (j = 0; j < m; j++) // j是列数
            {
                a[i][j] = ++k; // k是用来计数的
            }
        }
        else // i是奇数时，从右到左
        {
            for (j = m - 1; j >= 0; j--) // j是列数
            {
                a[i][j] = ++k; // k是用来计数的
            }
        }
    }
    for (i = 0; i < n; i++) // 输出
    {
        for (j = 0; j < m - 1; j++) // j是列数
        {
            printf("%d ", a[i][j]); // 输出
        }
        printf("%d\n", a[i][m - 1]); // 输出
    }
    /**********   End  ***********/
}
int main()
{
    f();
    return 0;
}
