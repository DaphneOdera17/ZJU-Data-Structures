#include<stdio.h>
#include<math.h>
#include<time.h>

#define MAXK 1e7

clock_t start, stop;

double duration; // 单位 s

// f(x) = a0 + a1*x + ... + a(n-1)*x*pow(n - 1) + an*x*pow(n)
double f(int n, double a[], double x)
{
    double p = a[0];
    for(int i = 1; i <= n; i ++)
    {
        // 每次执行 i 次乘法
        // 一共执行了 (1 + 2 + ... + n) = (n^2 + n) / 2 次乘法
        p += (a[i] * pow(x, i));
    }
    return p;
}

// f(x) = a0 + x(a1 + x(...(a(n-1) + x(an))...))
double f_Plus(int n, double a[], double x)
{
    double p = a[n];
    for(int i = n; i > 0; i --)
    {
        // 每次只执行 1 次乘法
        // 一共执行了 n 次乘法
        p = a[i - 1] + x * p;
    }
    return p;
}

int main()
{
    double a[10];
    for(int i = 0; i < 10; i ++)
    {
        a[i] = (double)i;
    }
    start = clock(); // 开始计时
    for(int i = 0; i < MAXK; i ++)
        f(9, a, 1.1); // 被测函数
    stop = clock(); // 停止计时
    duration = ((double)(stop - start)) / CLK_TCK / MAXK;
    printf("ticks1 = %f\n", (double)(stop - start));
    printf("duration1 = %6.2e\n", duration);

    start = clock(); // 开始计时
    for(int i = 0; i < MAXK; i ++)
        f_Plus(9, a, 1.1); // 被测函数
    stop = clock(); // 停止计时
    duration = ((double)(stop - start)) / CLK_TCK / MAXK;
    printf("ticks2 = %f\n", (double)(stop - start));
    printf("duration2 = %6.2e\n", duration);
    return 0;
}