// 从键盘上输入积分的下限a与积分的上限b，利用矩形法计算如图所示的3个积分值。
//     积分时n的取值为1000，输出时保留2位小数。
//         例：
// （1）输入：0,
//     1 输出：0 .46, 0.84, 1.72
// （2）输入：0, 2 输出：1 .42, 0.91, 6.38
#include <stdio.h>
#include <math.h>
#define N 1000
double function(double a, double b, double (*fu)(double))
{
    double ave = (b - a) / N;
    double sum = 0;
    int i;
    for (i = 0; i < 1000; i++)
    {
        double x = a + ave * i;
        sum += (*fu)(x)*ave;
    }
    return sum;
}
int main()
{
    double (*fu[3])(double) = {sin, cos, exp};
    double a, b;
    scanf("%lf%lf", &a, &b);
    printf("%.2lf %.2lf %.2lf\n",
           function(a, b, fu[0]),  // ?? sin(x) ???
           function(a, b, fu[1]),  // ?? cos(x) ???
           function(a, b, fu[2])); // ?? exp(x) ???
    return 0;
}