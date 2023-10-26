#include <iostream>
#include "time.h"

using namespace std;

void swap(int *p_from, int *p_to) {
    int tmp;
    tmp = *p_from;
    *p_from = *p_to;
    *p_to = tmp;
}

void insertionSort(int numbers[], int array_size)
{
    int i, j;

    for (i=1; i < array_size; i++) { //整列されていない部分の先頭を指す

        j = i; // 交換要素のためのインデックス

        // 整列済みの場合は処理しない
        while ((j > 0) && (numbers[j-1] > numbers[j])) {
            // 整列されていない隣り合う要素を交換する
            swap(&numbers[j-1], &numbers[j]);

            // 隣り合う要素のインデックスを更新
            j--;
        }
    }
}

int main()
{
    srand(time(NULL));

    int arry[5];
    int result[5] = {};

    for(int i = 0; i < 5; i++)
    {
        arry[i] = rand();
    }

    for(int i=0;i<5;i++)
    {
        cout << arry[i] << "\t";
    }
    cout << endl;

    insertionSort(arry, 5);
    
    for(int i = 0; i < 5; i++)
    {
        cout << arry[i] << "\t";
    }

    return 0;
}