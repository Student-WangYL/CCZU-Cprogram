#include <stdio.h>
int main()
{
    char ch;     // 顶行字符
    int height;  // 图形的高
    int i, j, k; // 循环变量
    // 输入顶行字符和图形的高
    scanf("%c%d", &ch, &height);
    // 输出图形的上半部分
    height = height / 2; //一半的高
    for (i = 0; i <= height - i + 1; i++)
    {
        // 输出空格
        for (j = 0; j < height - i + 1; j++)
        {
            printf(" ");
        }
        // 输出顶行字符
        printf("%c", ch + i);
        // 输出空格
        for (j = 0; j < i * 2 - 1; j++)
        {
            printf(" ");
        }
        // 输出顶行字符（除了最顶上的行）
        if (i > 0)
        {
            printf("%c", ch++);
        }
        printf("\n");
    }

    // 输出图形的下半部分
    for (i = ((height - 1) / 2); i >= 0; i--)
    {
        // 输出空格
        for (j = 0; j < height - i - 4; j++)
        {
            printf(" ");
        }
        // 输出顶行字符
        printf("%c", ch + i);
        // 输出空格
        for (j = 0; j < i * 2 - 1; j++)
        {
            printf(" ");
        }
        // 输出顶行字符（除了最底下的行）
        if (i > 0)
        {
            printf("%c", ch + i);
        }
        printf("\n");

    }

    return 0;
}
