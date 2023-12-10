// File: A2_ALL_B_20221258_1.cpp
// Purpose: Assignment 2
// Author: Momen Medhat
// Section: ALL-B
// ID: 20221258
// TA: ……………………
// Date: 5 NOV 2023


#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str;
    cout << "Enter a Text: ";
    getline(cin, str);

    bool space = false;
    for(int i = 0; i < str.size(); i++)
    {
        char c = str[i];
        // Convert the first character to uppercase
        if(i == 0 && c >= 97 && c <= 122)
        {
            cout << char(c - 32);
            continue;
        }
        // Convert the rest to lowercase
        if (c >= 65 && c <= 90)
        {
            cout << char(c + 32);
            continue;
        }
        // Handle multiple spaces
        if (c == ' ')
        {
            if (!space)
            {
                space = true;
                cout << c;
            }
            continue;
        }
        space = false;
        cout << c;
    }
    return 0;
}
