#include <stdio.h>


#define print(x) printf("%d\n",x)

int main(void)
{
    FILE *fp;

    fp = fopen("input.txt","r");

    int min = 0, max = 0;
    char let = 'a';
    char pwd[80];

    int valid = 0;

    while(fscanf(fp, "%d-%d %c: %s\n", &min, &max, &let, pwd) > 0)
    {
        // print(min);
        // print(max);
        //printf("%c\n", let);
        // printf(pwd);

        int i = 0, count = 0;
        while (pwd[i] != '\0')
        {
            if(pwd[i] == let) count++;
            i++;
        }

        printf("%d\n", count);

        if (count <= max && count >= min)
        {
            valid++;
        }
    }

    print(valid);
    //print(10);

}