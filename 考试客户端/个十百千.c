/*------------------------------------------------
【程序设计】
--------------------------------------------------

题目: 函数fun的功能是：将a、b中的两个两位正整数合并形成一个新的整数放在c中。
合并的方式是：将a中的十位和个位数依次放在变量c的百位和个位上，b中的十位和个位数依次放在变量c的千位和十位上。
    例如，当a=45,b=12。调用该函数后，c=1425。
    注意：部分源程序存在文件prog.c中。
    请勿改动主函数main和其他函数中的任何内容，仅在函数fun的花括号中填入你编写的若干语句。
*********Begin**********和**********  End  **********不可删除

*/

#include <conio.h>
#include <stdio.h>
#include <windows.h>
void fun(int a, int b, long *c)
{

    /**********  Begin  **********/
    *c = (a % 10) * 1000 + (a / 10) % 10 * 100 + (b % 10) * 10 + (b / 10) % 10;
    /**********   End  ***********/
}

void NONO()
{ /* 本函数用于打开文件，输入数据，调用函数，输出数据，关闭文件。 */
    FILE *rf, *wf;
    int i, a, b;
    long c;

    rf = fopen("in1.dat", "r");
    wf = fopen("bc02.dat", "w");
    for (i = 0; i < 10; i++)
    {
        fscanf(rf, "%d,%d", &a, &b);
        fun(a, b, &c);
        fprintf(wf, "a=%d,b=%d,c=%ld\n", a, b, c);
    }
    fclose(rf);
    fclose(wf);
}

int main() /*主函数*/
{
    int a, b;
    long c;
    system("cls");
    printf("Input a,b:");
    scanf("%d%d", &a, &b);
    fun(a, b, &c);
    printf("The result is: %ld\n", c);
    NONO();
}