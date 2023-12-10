
// File: A2_ALL_B_20221258_4.cpp
// Purpose: Assignment 2
// Author: Momen Medhat
// Section: ALL-B
// ID: 20221258
// TA: ……………………
// Date: 5 NOV 2023

#include <iostream>
#include <vector>
using namespace std;

void sieveOfEratosthenes(int n) {
    vector<bool> prime(n+1, true);
    prime[0] = prime[1] = false;
    for (int p=2; p*p<=n; p++) {
        if (prime[p] == true) {
            for (int i=p*p; i<=n; i += p)
                prime[i] = false;
        }
    }

    for (int p=2; p<=n; p++) {
       if (prime[p])
          cout << "[" << p << "] ";
       else
          cout << " " << p << "  ";
    }
}

int main() {
    int n;
    cout << "Enter the number n: ";
    cin >> n;
    cout << "Numbers up to " << n << " are: ";
    sieveOfEratosthenes(n);
    return 0;
}
