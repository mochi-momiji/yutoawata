#include "stdio.h"
#include "stdlib.h"
#include "time.h"

const int DATA_INDEX = 10;

int main()
{
    int data[11];

    for(int i = 0; i <= DATA_INDEX; i++){
        data[i] = i;
    }

    srand(time(NULL));

    for(int i = 0;i <= DATA_INDEX;i++){
        int ran_index = rand() % (i+1);

        int tmp = data[i];
        data[i] = data[ran_index];
        data[ran_index] = tmp;
    }

    int result = -1;
    int target = 5;

    for(int i = 0; i <= DATA_INDEX; i++){
        int value = data[i];
        if(value == target){
            result = i;
            break;
        }
    }
    printf("target_index = ");

    printf("%d", result);

    return 0;
}