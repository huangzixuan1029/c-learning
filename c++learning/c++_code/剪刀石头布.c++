
#include <stdio.h>

int min(int a, int b)
{
    return a > b ? b : a;
}
int notwin(int a, int b, int c, int A, int B, int C)
{
    int lose = min(a, C) + min(b, A) + min(c, B);
    a = a - min(a, C);
    C = C - min(a, C);
    b = b - min(b, A);
    A = A - min(b, A);
    c = c - min(c, B);
    B = B - min(c, B);
    int ping = min(a, A) + min(b, B) + min(c, C);
    return lose + ping;
}
int main()
{
    int N;
    scanf("%d", &N);

    int A1, B1, C1; // 老营长出石头、剪刀、布的次数
    scanf("%d %d %d", &A1, &B1, &C1);

    int A2, B2, C2; // 小胖肚出石头、剪刀、布的次数
    scanf("%d %d %d", &A2, &B2, &C2);

    // 计算最多能赢的轮数
    int max_wins = 0;
    max_wins += min(A2, B1); // 小胖肚出石头 vs 老营长出剪刀
    max_wins += min(B2, C1); // 小胖肚出剪刀 vs 老营长出布
    max_wins += min(C2, A1); // 小胖肚出布 vs 老营长出石头

    int min_wins = 0;
    min_wins = N - notwin(A2, B2, C2, A1, B1, C1);
    // 输出结果
    printf("%d %d\n", min_wins, max_wins);

    return 0;
}