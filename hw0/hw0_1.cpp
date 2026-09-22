#include <cstdio>
int main()
{
    double income;
    double sum = 0.0;
    for (int i = 0; i < 12; ++i)
    {
        scanf("%lf", &income);
        sum += income;
    }
    printf("\xC2\xA5%.2f\n", sum / 12.0);
    return 0;
}