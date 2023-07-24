/*------------------------------------------------
【程序设计】
--------------------------------------------------

功能：统计一行字符串中单词的个数,作为函数值返回。一行字符串在主函数中输入,
规定所有单词由小写字母组成,单词之间由若干个空格隔开,一行的开始没有空格。
*********Begin**********和**********  End  **********不可删除

------------------------------------------------*/
void TestFunc();
#include <stdio.h>
#include <string.h>
#define N 80
int fun(char *s)
{
    /*********Begin**********/
    int i, count = 0;
    char *p = s;
    for (i = 0; i < strlen(s); i++)
    {
        if (s[i] == ' ')
        {
            count++;
        }
    }
    return count + 1;
    /**********  End  **********/
}

int main()
{
    char line[N];
    int num = 0;
    printf("Enter a string :\n");
    gets(line);
    num = fun(line);
    printf("The number of word is : %d\n\n", num);
    TestFunc();
}

void TestFunc()
{
    FILE *IN, *OUT;
    int i;
    char s[100];
    IN = fopen("in.dat", "r");
    if (IN == NULL)
    {
        printf("Read FILE Error");
    }
    OUT = fopen("out.dat", "w");
    if (OUT == NULL)
    {
        printf("Write FILE Error");
    }

    fgets(s, 100, IN);
    i = fun(s);
    fprintf(OUT, "%d", i);
    fclose(IN);
    fclose(OUT);
}