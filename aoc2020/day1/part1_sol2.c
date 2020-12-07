// insertion into array

#include <stdio.h>
#include <stdbool.h>
#include <Windows.h>

#define MAXEL 2020
#define PRINT(x) printf("%d\n", x)

int main(void)
{
    LARGE_INTEGER FirstCounter;
    QueryPerformanceCounter(&FirstCounter);
    LARGE_INTEGER PerfCountFrequencyResult;
    QueryPerformanceFrequency(&PerfCountFrequencyResult);
    int PerfCountFrequency = PerfCountFrequencyResult.QuadPart;
    typedef unsigned long u64;

    u64 StartCycleCount = __rdtsc();

    FILE *fp;
    fp = fopen("input.txt","r");

    bool expenses[MAXEL]= {0};

    int current_val = 0;

    while(fscanf(fp, "%d", &current_val) == 1)
    {
        int check = 2020 - current_val;
        if(expenses[check] == 1)
        {
            PRINT(current_val*check);
        } else {
            expenses[current_val] = 1;
        }
    }

    u64 EndCycleCount = __rdtsc();
    printf("mCycles %d\n", (EndCycleCount - StartCycleCount)/1000);

    LARGE_INTEGER EndCounter;
    QueryPerformanceCounter(&EndCounter);

    // TODO(casey): Display the value here
    int CounterElapsed = EndCounter.QuadPart - FirstCounter.QuadPart;
    float MS = (float)((100000*CounterElapsed) / PerfCountFrequency);
    printf("%2.1f e-5 secs \n", MS);
}