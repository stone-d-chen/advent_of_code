#include <stdio.h>

#define MAXEL 200

int compare(const void* a, const void* b)
{
    int da = * ( (int *) a );
    int db = * ( (int *) b );

    if (da == db) return(0);
    else if (da < db) return(-1);
    else return(1);
}

int main(void)
{
    int StartCyclesCount = __rdtsc();

    FILE *fp;
    fp = fopen("input.txt","r");
    
    int expenses[MAXEL] = {0};
    int idx = 0;
    while(fscanf(fp, "%d", &expenses[idx])==1)
    {
        idx++;
    }

    qsort(expenses, idx, sizeof(int), compare);

    int pt1 = 0;
    int pt2 = 199;
    
    int low_val = expenses[pt1];
    int high_val = expenses[pt2];

    while(pt1 < pt2)
    {

        int sum = low_val + high_val;

        if(sum == 2020)
        {
            printf("%d\n", low_val*high_val);
            break;
        }
        else if (sum < 2020)
        {
            pt1 += 1;
            low_val = expenses[pt1];
        }
        else
        {
            pt2 -= 1;
            high_val = expenses[pt2];
        }
    }

    int EndCyclesCount = __rdtsc();

    printf("mCycles %d\n", (EndCyclesCount - StartCyclesCount)/1000);

}