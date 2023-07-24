#include <stdio.h>
#include <ctype.h>

int main()
{
    char c;
    int letter = 0, space = 0, digit = 0, other = 0;
    //printf("请输入一行字符：\n");
    while ((c = getchar()) != EOF)
    { // 读取输入的每个字符
        if (isalpha(c))
        { // 判断是否为英文字母
            letter++;
        }
        else if (isspace(c))
        { // 判断是否为空格
            space++;
        }
        else if (isdigit(c))
        { // 判断是否为数字
            digit++;
        }
        else
        { // 其他情况则视为其他字符
            other++;
        }
    }
    printf("%d ", letter);
    printf("%d ", space);
    printf("%d ", digit);
    printf("%d\n", other);
    return 0;
}