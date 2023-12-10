// File: main.cpp
// Purpose: Assignment 2 BigReal Application File
// Author: Momen Medhat
// Section: ALL-B
// ID: 20221258
// TA: ……………………
// Date: 5 NOV 2023

#include <iostream>
#include <vector>
#include "implementation.cpp"
using namespace std;

int main()
{
    BigReal v("515468.7");
    BigReal m("9.0589");
    BigReal x(m);

    cout << (v+m);

// Test Case 1: Adding two positive numbers
BigReal v1("515468.7");
BigReal m1("9.0589");
cout << "Test Case 1: " << (v1 + m1) << endl;  // Expected output: 515477.7589

// Test Case 2: Subtracting two positive numbers
BigReal v2("515468.7");
BigReal m2("9.0589");
cout << "Test Case 2: " << (v2 - m2) << endl;  // Expected output: 515459.6411

// Test Case 3: Adding a positive and a negative number
BigReal v3("515468.7");
BigReal m3("-9.0589");
cout << "Test Case 3: " << (v3 + m3) << endl;  // Expected output: 515459.6411

// Test Case 4: Subtracting a positive and a negative number
BigReal v4("515468.7");
BigReal m4("-9.0589");
cout << "Test Case 4: " << (v4 - m4) << endl;  // Expected output: 515477.7589

// Test Case 5: Adding two negative numbers
BigReal v5("-515468.7");
BigReal m5("-9.0589");
cout << "Test Case 5: " << (v5 + m5) << endl;  // Expected output: -515477.7589

// Test Case 6: Subtracting two negative numbers
BigReal v6("1.4142");
BigReal m6("-2.7182");
cout << "Test Case 6: " << (v6 - m6) << endl;  // Expected output: 4.1324

// Test Case 7: Subtracting two positive numbers
BigReal v7("0.5772");
BigReal m7("0.6931");
cout << "Test Case 7: " << (v7 - m7) << endl;  // Expected output: -0.1159

// Test Case 8: Adding a positive and a negative number
BigReal v8("1.6180");
BigReal m8("-1.6180");
cout << "Test Case 8: " << (v8 + m8) << endl;  // Expected output: 0.0000

// Test Case 9: Adding a small positive number to a large positive number
BigReal v9("987654321987654321.1234");
BigReal m9("0.0001");
cout << "Test Case 9: " << (v9 + m9) << endl;  // Expected output: 987654321987654321.1235

// Test Case 10: Subtracting a small positive number from a large positive number
BigReal v10("987654321987654321.1234");
BigReal m10("0.0001");
cout << "Test Case 10: " << (v10 - m10) << endl;  // Expected output: 987654321987654321.1233

// Test Case 11: Adding a small negative number to a large negative number
BigReal v11("-987654321987654321.1234");
BigReal m11("-0.0001");
cout << "Test Case 11: " << (v11 + m11) << endl;  // Expected output: -987654321987654321.1235

// Test Case 12: Subtracting a small negative number from a large negative number
BigReal v12("-987654321987654321.1234");
BigReal m12("-0.0001");
cout << "Test Case 12: " << (v12 - m12) << endl;  // Expected output: -987654321987654321.1233


    return 0;
}