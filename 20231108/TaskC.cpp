#include "stdio.h"
#include "stdlib.h"
#include "time.h"

const int ARRY_INDEX = 10;

int data[ARRY_INDEX];

int main()
{

    srand(time(NULL));
    for(int i = 0; i < ARRY_INDEX; ++i)
    {
        data[i] = rand();
    }

    for(int i = 0; i < ARRY_INDEX; ++i)
    {
        printf("%d\n", data[i]);
    }

    return 0;
}