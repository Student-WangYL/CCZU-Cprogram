#include <stdio.h>
#include <math.h>

#define EPS 1e-6 // 设置精度

int is_equal(double a, double b)
{
    return fabs(a - b) < EPS;
}

int is_triangle(double a, double b, double c)
{
    return a + b > c && b + c > a && a + c > b;
}

int is_right_triangle(double a, double b, double c)
{
    double max = fmax(fmax(a, b), c);
    double min1 = fmin(a, b);
    double min2 = fmin(min1, c);
    double mid = a + b + c - max - min2;
    return is_equal(max * max, mid * mid + min2 * min2);
}

int is_isosceles_triangle(double a, double b, double c)
{
    return is_equal(a, b) || is_equal(b, c) || is_equal(a, c);
}

int is_equilateral_triangle(double a, double b, double c)
{
    return is_equal(a, b) && is_equal(b, c);
}

int main()
{
    double a, b, c;
    scanf("%lf %lf %lf", &a, &b, &c);

    if (!is_triangle(a, b, c))
    {
        printf("不是三角形\n");
        return 0;
    }

    if (is_equilateral_triangle(a, b, c))
    {
        printf("等边三角形\n");
    }
    else if (is_isosceles_triangle(a, b, c) && is_right_triangle(a, b, c))
    {
        printf("等腰直角三角形\n");
    }
    else if (is_isosceles_triangle(a, b, c))
    {
        printf("等腰三角形\n");
    }
    else if (is_right_triangle(a, b, c))
    {
        printf("直角三角形\n");
    }
    else
    {
        printf("一般三角形\n");
    }

    return 0;
}