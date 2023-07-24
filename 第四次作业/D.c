/*
    题目描述
        小李在农村长大，那时候大家喜欢晚饭过后在院子里纳凉，听不懂大人在说什么的小李喜欢抬头看天空，尤其是夏天的夜晚，天上的星星又多又亮。
        长大后小李进城打工，每当想家的时他还是喜欢抬头看看天，寻找另一边故乡的记忆。
        可是大城市里空气质量太差了，雾霾天气横行，天上能看到的星星也越来越少了。
        小李每次用一个正方形去覆盖自己所能看到的星星，随着日子的推移，这个正方形越来越小了，悲伤的小李希望你能告诉他这个正方形的面积。为了让问题变得简单，小李每次只会使用水平放置的正方形来覆盖（不会旋转），具体参照样例解释。
    输入
    第一行一个整数n，表示星星的数量。
    接下来共n行，每行2个正整数(a,b)，表示该星星到X轴距离为b，到Y轴距离为a，这些星星只会位于X轴的上方，Y轴的右方。
    输入数据保证存在一个合法的正方形（面积非零）去覆盖这些星星

    3<=n<=20, 1<=x<=100, 1<=y<=100


    输出
    一个整数，表示能覆盖所有星星的最小正方形的面积。
    样例输入
    3
    1 1
    2 1
    2 2
    样例输出
    1
*/
#include <stdio.h>
#include <stdlib.h>

#define MAX_N 20
#define MAX_X 100
#define MAX_Y 100

typedef struct
{
    int x;
    int y;
} Star;

// 比较函数，用于排序
int cmp(const void *a, const void *b)
{
    Star *s1 = (Star *)a;
    Star *s2 = (Star *)b;
    if (s1->x < s2->x)
    {
        return -1;
    }
    else if (s1->x > s2->x)
    {
        return 1;
    }
    else
    {
        return s1->y - s2->y;
    }
}

int main()
{
    int n;
    Star stars[MAX_N];
    int i, j;
    int max_dist = 0;
    int dist;

    // 读入数据
    scanf("%d", &n);
    for (i = 0; i < n; ++i)
    {
        scanf("%d%d", &stars[i].y, &stars[i].x);
    }

    // 按照 x 坐标升序排序，如果 x 坐标相同则按照 y 坐标升序排序
    qsort(stars, n, sizeof(Star), cmp);

    // 计算相邻两个星星之间的距离，并更新最大距离
    for (i = 1; i < n; ++i)
    {
        dist = stars[i].x - stars[i - 1].x;
        if (dist > max_dist)
        {
            max_dist = dist;
        }
        dist = stars[i].y - stars[i - 1].y;
        if (dist > max_dist)
        {
            max_dist = dist;
        }
    }

    // 输出最小正方形的面积
    printf("%d\n", max_dist * max_dist);

    return 0;
}
/*
代码的思路如下：
定义结构体 Star 表示星星的坐标，包括 x 和 y 两个坐标值；
读取输入数据，存储在 stars 数组中；
按照 x 坐标升序排序，如果 x 坐标相同则按照 y 坐标升序排序；
计算相邻两个星星之间的距离，并更新最大距离；
最小正方形的边长等于最大距离，因此最小正方形的面积等于最大距离的平方，输出结果。
*/