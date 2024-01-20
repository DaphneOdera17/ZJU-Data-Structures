#include<stdio.h>
#include<time.h>
#include<math.h>

#define MAXN 100
#define MAXK 1e6

clock_t start, stop;
double duration;

double f1(int n, double a[], double x)
{
    double p = a[0];
    for(int i = 1; i <= MAXN; i ++)
    {
        p += a[i] * pow(x, i);
    }
    return p;
}

double f2(int n, double a[], double x)
{
    double p = a[n - 1];
    for(int i = n; i > 0; i --)
    {
        p = a[i - 1] + x * p;
    }
    return p;
}

int main()
{
    double a[MAXN];
    for(int i = 0; i < MAXN; i ++)
    {
        a[i] = 1 / (i + 1);
    }

    start = clock();
    for(int i = 1; i <= MAXK; i ++)
        f1(MAXN, a, 1.1);
    stop = clock();
    duration = ((double)(stop - start)) / CLK_TCK / MAXK;
    printf("ticks1 = %f\n", (double)(stop - start));
    printf("duration1 = %6.2e\n", duration);
    printf("%.6lf\n", f1(MAXN, a, 1.1));

    start = clock();
    for(int i = 1; i <= MAXK; i ++)
        f2(MAXN, a, 1.1);
    stop = clock();
    duration = ((double)(stop - start)) / CLK_TCK / MAXK;
    printf("ticks2 = %f\n", (double)(stop - start));
    printf("duration2 = %6.2e\n", duration);
    printf("%.6lf\n", f2(MAXN, a, 1.1));

    return 0;
}