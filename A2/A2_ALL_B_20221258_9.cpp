// File: A2_ALL_B_20221258_9.cpp
// Purpose: Assignment 2
// Author: Momen Medhat
// Section: ALL-B
// ID: 20221258
// TA: ……………………
// Date: 5 NOV 2023

#include <iostream>
#include <vector>
#include <string>
using namespace std;
static bool bears(int n);
int main()
{
    int bears_count;
    cout << "Give me the bears\n";
    cin >> bears_count;
    if (bears(bears_count))
    {
        /* code */
    cout<< "True";
    return 0;
    }
    cout<< "False";
    
    
}

static bool bears(int n)
{
    if (n==42)
    {
        return true;
    }
    if (n<42)
    {
        return false;
    }


    if (n % 2 ==0 )    
    {

        return ( n - (n / 2));
    }

    if ( ((n % 3) == 0 || (n % 4) == 0) )    
    {

        return ( n - ((n % 10) * (n % 100 / 10)));
    }
    if (n % 5 == 0)
    {
        return (n -= 42);
    }
    
    return false;
}
