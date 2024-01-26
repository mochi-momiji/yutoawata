#include <iostream>
#include <vector>
#include "time.h"

using namespace std;

const int ARRY_INDEX = 10;
const int null = -1;

int arr[ARRY_INDEX] = {1, 9, 3, 2, 5, 7, 4, 6, 8, 0};
int result[ARRY_INDEX] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1};

int* sort(int target){
    int big_array[ARRY_INDEX]= {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1};
    int same_array[ARRY_INDEX]= {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1};
    int small_array[ARRY_INDEX] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1};
    int small_index = 0;
    int same_index = 0;
    int big_index = 0;
    int index = 0;
    do{
        cout << target<<";";
        if(target < result[index]){
            small_array[small_index] = target;
            small_index++;
        }
        else if(target > result[index]){
            big_array[big_index] = target;
            big_index++;
        }
        else{
            same_array[same_index] = target;
            same_index++;
        }
        index++;
    }while(result[index] == null);
    for(int i = 0;i < ARRY_INDEX; i++){
        for(int j = 0; j < small_index; j++){
            if(small_array[j] != null){
                result[i] = small_array[j];
            }
        }
        for(int j = 0; j < same_index; j++){
            if(same_array[j] != null){
                result[i] = same_array[j];
            }
        }
        for(int j = 0; j < big_index; j++){
            if(big_array[j] != null){
                result[i] = big_array[j];
            }
        }
    }

    return result;
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
        sort(value);
    }
    
    for(int i = 0; i < ARRY_INDEX; i++)
    {
        cout << result[i] << ", ";
    }

    return 0;
}