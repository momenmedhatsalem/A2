// File: A2_ALL_B_20221258_2.cpp
// Purpose: Assignment 2
// Author: Momen Medhat
// Section: ALL-B
// ID: 20221258
// TA: ……………………
// Date: 5 NOV 2023


#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main()
{
    string sentence;
    cout << "Enter the input to be inclusive" << endl;
    getline(cin, sentence);
    istringstream iss(sentence);
    string word;
    while (iss >> word) {
        if (word == "him")
        {
            cout << "him or her ";
        }
        else if (word == "He")
        {
           cout << "He or She ";
        }
        else
        {
            cout << word << " ";
        }
    }
    cout << endl;
    return 0;
}
