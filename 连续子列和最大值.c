#include<stdio.h>

// 暴力做法
int MaxSubseqSum1(int A[], int N)
{
    int ThisSum, MaxSum = 0;
    for(int i = 0; i < N; i ++) // 子列左端位置
    {
        for(int j = i; j < N; j ++) // 子列右端位置
        {
            ThisSum = 0;
            for(int k = i; k <= j; k ++)
            {
                ThisSum += A[k];
                if(ThisSum > MaxSum)
                    MaxSum = ThisSum;
            }
        }
    }
    return MaxSum;
}

int main()
{
    
}