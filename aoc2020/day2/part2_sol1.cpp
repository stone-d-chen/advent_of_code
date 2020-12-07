#include <stdio.h>


#define print(x) printf("%d\n",x)

int main(void)
{
    FILE *fp;

    fp = fopen("input.txt","r");

    int p1 = 0, p2 = 0;
    char let = 'a';
    char pwd[25];

    int valid = 0;

    while(fscanf(fp, "%d-%d %c: %s\n", &p1, &p2, &let, pwd) > 0)
    {
        int count = 0;

        if(pwd[p1-1] == let) count++;
        if(pwd[p2-1] == let) count++;

        if (count == 1) valid++;
    
    }

    print(valid);
}