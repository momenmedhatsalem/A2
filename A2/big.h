// File: A2_ALL_B_20221258_header.cpp
// Purpose: Assignment 2 header file of BigReal
// Author: Momen Medhat
// Section: ALL-B
// ID: 20221258
// TA: ……………………
// Date: 5 NOV 2023

#include <iostream>
#include <vector>
using namespace std;
class BigReal
{
private:
    string sign = "+";
    vector<int> digits;
    int size;
    int floating_point_position;

    bool isValidReal(string realNumber);

public:
    BigReal(string realNumber);

    // Overload the + operator
    BigReal operator+( BigReal &other);

    // Overload the - operator
    BigReal operator-( BigReal &other);

    // Copy constructor
    BigReal(const BigReal &other)
        : sign(other.sign),
          digits(other.digits),
          floating_point_position(other.floating_point_position),
          size(other.size)
    {
    }

    bool operator==(const BigReal &other) const;

    bool operator<(const BigReal &other) const;

    bool operator>(const BigReal &other) const;

    /*
        BigReal(string realNumber);         // Initialize from string
        BigReal(const BigReal &other);      // Copy constructor
        BigReal &operator=(BigReal &other); // Assignment operator
        // Depending on how you store data, default can be enough
        void setNum(string realNumber) int size();
        int sign();
        BigReal operator+(BigReal &other);
        BigReal operator-(BigReal &other);
        bool operator<(BigReal anotherReal);
        bool operator>(BigReal anotherReal);
        bool operator==(BigReal anotherReal);
        */
    friend ostream &operator<<(ostream &out, BigReal num);
};