#include "stdio.h"
#include "stdlib.h"
#include "time.h"

const int DATA_INDEX = 100;

int data[100];

int main()
{
    srand(time(NULL));

    for(int i = 0;i < DATA_INDEX; i++){
        data[i] = rand();
    }
    
    for(int i = 0; i < DATA_INDEX; i++){
        for(int j = DATA_INDEX - 1; j >=i + 1;--j){
            int valueA = data[i];
            int valueB = data[j];

            if(valueA > valueB){
                int max = valueA;
                int min = valueB;

                data[i] = min;
                data[j] = max;
            }
        }
    }
    
    for(int i = 0; i < DATA_INDEX; i++){
        printf("%d\t", data[i]);
        if((i + 1) % 10 == 0){
            printf("\n");
        }
    }

    return 0;
}