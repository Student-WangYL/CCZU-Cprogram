/*------------------------------------------------
【程序设计】
--------------------------------------------------

功能：编写程序求无理数e的值并输出。计算公式为：
      e=1+1/1!+1/2!+1/3!+......+1/n!
要求：根据精度变量eps的值，当1/n!<eps时，结束循环。



*********Begin**********和**********  End  **********不可删除



------------------------------------------------*/

#include "stdio.h"

main()
{
    float fun(float);
    void TestFunc();
    float eps;
    scanf("%f", &eps);
    printf("无理数e的值是:%f\n", fun(eps));
    TestFunc();
}

float fun(float eps)
{
    /*********Begin**********/
    float sum = 1;
    int i = 1;
    float item = 1;
    while (item >= eps)
    {
        item = item / i;
        sum = sum + item;
        i++;
    }
    return sum;
    /**********  End  **********/
}

void TestFunc()
{
    FILE *IN, *OUT;
    float o;
    int i;
    float eps;
    IN = fopen("in.dat", "r");
    if (IN == NULL)
    {
        printf("Read File Error");
    }
    OUT = fopen("out.dat", "w");
    if (OUT == NULL)
    {
        printf("Write File Error");
    }
    for (i = 1; i <= 3; i++)
    {
        fscanf(IN, "%f", &eps);
        o = fun(eps);
        fprintf(OUT, "%f\n", o);
    }
    fclose(IN);
    fclose(OUT);
}