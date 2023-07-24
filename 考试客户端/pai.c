/*------------------------------------------------
【程序设计】
--------------------------------------------------

功能：
 用下面的公式求π的近似值，直到最后一项的绝对值小于指定的数（参数num）为止：
 例如：num为0.0001，则程序输出3.141393
π/4≈1-1/3+1/5-1/7+……
*********Begin**********和**********  End  **********不可删除

------------------------------------------------*/
void TestFunc();
#include <math.h>
#include <stdio.h>
double fun(double num)
{
    /*********Begin**********/
    int flag = 1;
    double pi = 0, i = 1;
    while (fabs(1 / i) >= num)
    {
        pi += flag * (1 / i);
        i += 2;
        flag *= -1;
    }
    return pi * 4;
    /**********  End  **********/
}

main()
{
    double n1, n2;
    printf("Enter a double number: ");
    scanf("%lf", &n1);
    n2 = fun(n1);
    printf("%f\n", n2);
    TestFunc();
}

void TestFunc()
{
    FILE *IN, *OUT;
    double s, i;
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
    fscanf(IN, "%lf", &i);
    s = fun(i);
    fprintf(OUT, "%f", s);
    fclose(IN);
    fclose(OUT);
}
