#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    unsigned long n, i, a, b, c, cycle, max;
    while (scanf("%ld%ld", &a, &b) == 2)
    {
        /* 一次資料輸入筆數為 2 */
        printf("%ld %ld", a, b);

        /* 若 a 比 b 大則交換兩數值 */
        if (a > b)
        {
            c = a;
            a = b;
            b = c;
        }

        max = 0;
        for (i = a; i <= b; i++)
        {
            n = i;
            cycle = 1;
            while(n != 1)
            {
                n = n % 2 ? 3 * n + 1 : n / 2;

                /* 每循環一次週期 + 1 */
                cycle++;
            }

            /* 求出最大值 */
            max = cycle > max ? cycle : max;
        }

        printf(" %ld\n", max);
    }
    return 0;
}
