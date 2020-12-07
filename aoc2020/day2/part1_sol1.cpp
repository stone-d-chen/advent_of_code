#include <stdio.h>
#include <Windows.h>

#define print(x) printf("%d\n",x)

int main(void)
{
    int BeginCycleCount = __rdtsc();
    FILE *fp;

    fp = fopen("input.txt","r");

    int min = 0, max = 0;
    char let = 'a';
    char pwd[25];

    int valid = 0;

    while(fscanf(fp, "%d-%d %c: %s\n", &min, &max, &let, pwd) > 1)
    {
   
         int i = 0, count = 0;
        while (pwd[i] != '\0')
        {
            if(pwd[i] == let) count++;
            i++;
        }

        if (count >= min && count <= max)
        {
            valid++;
        }
    }
    int mC = __rdtsc() - BeginCycleCount;

    print(valid);
    print(mC/1000);
}