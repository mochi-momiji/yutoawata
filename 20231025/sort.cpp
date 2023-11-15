#include <iostream>
#include "time.h"

#define ARRY_INDEX 5

using namespace std;

int main()
{
    srand(time(NULL));

    int arry[ARRY_INDEX];
    int result[ARRY_INDEX];

    for(int i = 0; i < ARRY_INDEX; i++)
    {
        arry[i] = rand();
    }

    for(int i = 0; i < ARRY_INDEX; i++)
    {
        cout << arry[i] << "\t";
    }
    cout << endl;

    int j;
    rezult[0] = arry[0];

    for(int i = 1;i < ARRY_INDEX; i++)
    {
        int tmp[i];

        if(arry[i] < result[i-1])
        {

        }
    }
    
    for(int i = 0; i < ARRY_INDEX; i++)
    {
        cout << result[i] << "\t";
    }

    return 0;
}