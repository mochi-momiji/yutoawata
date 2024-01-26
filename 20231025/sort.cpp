#include <iostream>
#include <vector>
#include "time.h"

using namespace std;

const int ARRY_INDEX = 10;
const int null = -1;

int arr[ARRY_INDEX] = {1, 9, 3, 2, 5, 7, 4, 6, 8, 0};
int result[ARRY_INDEX] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1};

void sort(int target){
    int big_array[ARRY_INDEX]= {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1};
    int same_array[ARRY_INDEX]= {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1};
    int small_array[ARRY_INDEX] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1};
    int small_index = 0;
    int same_index = 0;
    int big_index = 0;
    int index = 0;
    while(result[index] != null){
        int value = result[index];
        if(index == 0){
            same_array[same_index] = target;
            same_index++;
        }
        if(target < value){
            big_array[big_index] = value;
            big_index++;
        }
        else if(target > value){
           small_array[small_index] = value;
            small_index++;
        }
        else{
            same_array[same_index] = value;
            same_index++;
        }
        index++;
    }

    int i = 0;
    while(i < index){
        for(int j = 0; j < small_index; j++){
            if(small_array[j] != null){
                result[i] = small_array[j];
                i++;
            }
        }
        for(int j = 0; j < same_index; j++){
            if(same_array[j] != null){
                result[i] = same_array[j];
                i++;
            }
        }
        for(int j = 0; j < big_index; j++){
            if(big_array[j] != null){
                result[i] = big_array[j];
                i++;
            }
        }
        break;
    }
}

int main()
{
    srand(time(NULL));

    for(int i = 0; i < ARRY_INDEX; i++)
    {
        cout << arr[i] << ", ";
    }
    cout << endl;

    for(int i = 0; i < ARRY_INDEX; i++){
        int value = arr[i];
        if(i == 0){
            result[i] =value;
            continue;
        }
        sort(value);
    }
    
    for(int i = 0; i < ARRY_INDEX; i++)
    {
        cout << result[i] << ", ";
    }

    return 0;
}