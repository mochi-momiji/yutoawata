#include "stdio.h"
#include "stdlib.h"
#include "time.h"

const int DATA_INDEX = 100; 

int data[100];

void SortData()
{
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
}

int main()
{

    srand(time(NULL));
    for(int i=0;i<DATA_INDEX;i++){
        data[i] = rand()%(100 + 1);
    }

    SortData();

    int target = 50;
    int result = -1;
    int left = 0;
    int right = DATA_INDEX - 1;

    while(left < right){
        int mid = (left+right) / 2;
        int value = data[mid];

        if(value == target){
            result = mid;
            break;
        }
        if(value < target){
            left=mid + 1;
        }
        else{
            right = mid;
        }
    }

    if(result >= 0){
        printf("target_index = %d", result);
    }
    else{
        printf("target = null");
    }

    return 0;
}