/* 
Brute force solution
O(n!)?
*/

#include <stdio.h>

#define MAXEL 200
#define PRINT(x) printf("%d\n", x)

int main(void)
{
    int StartCyclesCount = __rdtsc();

    FILE *fp;
    fp = fopen("input.txt", "r");

    int expenses[MAXEL] = {0};
    int idx = 0;

    while(fscanf(fp, "%d", &expenses[idx])==1)
    {
        idx++;
    }

    for (int i = 0; i < MAXEL; i++)
    {
        for (int j = i + 1; j < MAXEL; j++)
        {
            for (int k = j + 1; k < MAXEL; k++)
            {
                int sum = expenses[i] + expenses[j] + expenses[k];
                if (sum == 2020)
                {
                    PRINT(expenses[i] * expenses[j] * expenses[k]);
                }
            }

        }
    }

    int EndCyclesCount = __rdtsc();

    printf("mCycles %d\n", (EndCyclesCount - StartCyclesCount)/1000);

}