#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int get_rand(void);

int Panduan1(int sum);//判断输赢1

int Panduan2(int sum);//判断输赢2

void putout_result(s);//输出结果

int main()
{
    int sum;
    int s;

    sum = get_rand();

    s = Panduan1(sum);

    putout_result(s);

    return 0;
}

int get_rand(void)
{
    int die1, die2;
    int workSum;

    srand(time(NULL));

    die1 = 1 + rand() % 6;
    die2 = 1 + rand() % 6;

    workSum = die1 + die2;

    printf("die1 = %d  die2 = %d\nworkSum = %d\n\n", die1, die2, workSum);

    return(workSum);
}

int Panduan1(int sum)
{
    int s;

    if(sum == 7 ||sum == 11){
        s = 1;
    }
    else if(sum == 2 || sum == 3 || sum == 12){
        s = 0;
    }
    else{
        s = Panduan2(sum);
    }

    return(s);
}

int Panduan2(int sum)
{
    int s;
    int sum2;

    sum2 = get_rand();

    if(sum2 == 7){
        s = 0;
    }
    else if(sum == sum2){
        s = 1;
    }
    else{
        Panduan2(sum);
    }

    return(s);
}

void putout_result(s)
{
    if(s == 1){
        printf("you win.\n");
    }
    else if(s == 0){
        printf("you failed\n");
    }
}
