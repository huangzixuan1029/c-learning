//这个的技巧是先可看看恶魔数的多少，发现特别少，甚至四位数的情况都没有
//所以如果范围特别大的话，直接就不管了
//我的第一想法 利用字符串的加减来处理数据很大的情况，但是发现光是遍历都是问题

#include<stdio.h>
#include<stdbool.h>
#include<math.h>
bool lily(long long n)
{
    long long result = n;
    long long sum = 0;
    while(n!=0)
    {
        sum+=pow(n%10,3);
        n /= 10;
    }
    if(sum==result)
    {
        return false;
    }    
    else{
        return true;
    }
}
int main()
{
    long long left;
    long long right;
    scanf("%lld%lld", &left, &right);
    long long i=0;
    int count = 0;
    long long result;
    if(left>=10000)
    {
        printf("%lld", right - left+1);
        return 0;
    }
    else if(left<10000&&right>=10000)
    {
        for (i = left; i <= 10000; i++)
        {
            if (lily(i))
            {
                count++;
            }
        }
        return 0;
    }
    else{
        for (i = left; i <= right; i++)
        {
            if (lily(i))
            {
                count++;
            }
            printf("%d", count);
            return 0;
        }
    }
    
    
    return 0;
}