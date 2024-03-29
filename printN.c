#include<stdio.h>

// 迭代方法
void PrintN(int N)
{
    for(int i = 1; i <= N; i ++)
    {
        printf("%d\n", i);
    }
}

// 递归方法
void printN(int N)
{
    // 占用空间的大小跟 N 呈线性相关
    if(N)
    {
        printN(N - 1);
        printf("%d\n", N);
    }
}

int main()
{
    PrintN(10);
    puts("");
    printN(12);
    return 0;
}