// File: A2_ALL_B_20221258_6.cpp
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

void binaryPrint(int n);
void binaryPrint(int n)
{
    if (n <= 0)
    {
        cout << "0";
        return;
    }
    

    if (n % 32 == 0)
    {
        cout << "1";
        binaryPrint(n - 32);
        return;
    }
    if (n % 16 == 0)
    {
        cout << "1";
        binaryPrint(n - 16);
        return;
    }
    if (n % 8 == 0)
    {
        cout << "1";
        binaryPrint(n - 8);
        return;
    }
    if (n % 4 == 0)
    {
        cout << "1";
        binaryPrint(n - 4);
        return;
    }
    if (n % 4 == 0)
    {
        cout << "1";
        binaryPrint(n - 4);
        return;
    }
    if (n % 2 == 0)
    {
        cout << "1";
        binaryPrint(n - 2);
        return;
    }
    cout << "0";
    return;
}
int main()
{
    binaryPrint(2);
}