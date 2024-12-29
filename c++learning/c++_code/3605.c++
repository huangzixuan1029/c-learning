#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MOD 3605

long long countPairs(int *A, int N)
{
    int modCount[MOD] = {0}; // 用于统计每个 mod 值的出现次数
    long long count = 0;

    // 计算每个数对 3605 取模的结果，并统计出现次数
    for (int i = 0; i < N; i++)
    {
        int modValue = A[i] % MOD;
        modCount[modValue]++;
    }

    // 根据组合公式计算满足条件的对数
    for (int i = 0; i < MOD; i++)
    {
        if (modCount[i] > 1)
        {
            count += (long long)modCount[i] * (modCount[i] - 1) / 2;
        }
    }

    return count;
}

int main()
{
    int N;
    scanf("%d", &N);

    int *A = (int *)malloc(N * sizeof(int));
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &A[i]);
    }

    long long result = countPairs(A, N);
    printf("%lld\n", result);

    free(A);
    return 0;
}
