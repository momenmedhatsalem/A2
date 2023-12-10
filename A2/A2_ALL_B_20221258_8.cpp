// File: A2_ALL_B_20221258_8.cpp
// Purpose: Assignment 2
// Author: Momen Medhat
// Section: ALL-B
// ID: 20221258
// TA: ……………………
// Date: 5 NOV 2023

#include <iostream>
#include <string>

using namespace std;

void printPattern(int n, int i) {
    if (n == 0) {
        return;
    }
    printPattern(n / 2, i);
    cout << string(i, ' ') << string(n, '*') << "\n";
    printPattern(n / 2, i + n / 2);
}

int main() {
    printPattern(8, 0);
    return 0;
}
