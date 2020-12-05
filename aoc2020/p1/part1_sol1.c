#include <stdio.h>
#include <Windows.h>
#define MAXEL 200


int main(void)
{
    typedef unsigned long u64;
    u64 StartCycleCount = __rdtsc();

    FILE *fp;
    fp = fopen("input.txt","r");

    int expenses[MAXEL]= {0};
    int idx = 0;

    while(fscanf(fp, "%d", &expenses[idx]) == 1)
    {
        idx++;
    }
    
    for (int i = 0; i < MAXEL; i++)
    {
        for(int j = i + 1; j < MAXEL; j++)
        {
            if(expenses[i] + expenses[j] == 2020){
                printf("%d\n",expenses[i]+expenses[j]);
                printf("%d\n",expenses[i]*expenses[j]);
            } 

        }
    }

    u64 EndCycleCount = __rdtsc();

    printf("megaCycles %d\n", (EndCycleCount - StartCycleCount)/1000);



}