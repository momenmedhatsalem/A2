// File: A2_ALL_B_20221258_12.cpp
// Purpose: Assignment 2
// Author: Momen Medhat
// Section: ALL-B
// ID: 20221258
// TA: ……………………
// Date: 5 NOV 2023

using namespace std;
#include <sstream>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

class Phrase
{
public:
    string text;
    int point;
    int total = 0;
    static int Ultimate;
    Phrase(string t, int point1)
    {
        text = t;
        point = point1;
    }

void isEqual(string &otherText)
{
    size_t pos = 0;
    int count = 0;

    while ((pos = otherText.find(text, pos)) != string::npos) {
        ++count;
        pos += text.length();
    }

    total += count * point;
    Ultimate += total;
}

};

int Phrase::Ultimate = 0;

int main()
{

    ifstream file("txt.txt");
    if (!file)
    {
        cerr << "Unable to open file";
        return 1; // call system to stop
    }

    // Create a vector of MyClass objects
    vector<Phrase> myObjects = {Phrase("Verify your account", 3),
                                Phrase("If you don't respond within 48 hours, your account will be closed", 3),
                                Phrase("Dear valued customer", 2),
                                Phrase("Click the link below to gain access to your account", 3),
                                Phrase("Update your account information", 3),
                                Phrase("You have won the lottery", 1),
                                Phrase("Confirm your identity", 3),
                                Phrase("Your account has been compromised", 3),
                                Phrase("You're eligible to register for a refund", 2),
                                Phrase("We're unable to verify your information; click here to update your account", 3),

                                Phrase("Congratulations, you're a winner", 1),
                                Phrase("Your password has expired", 2),
                                Phrase("Suspicious activity detected", 3),
                                Phrase("You've received a secure message", 2),
                                Phrase("Payment declined", 3),
                                Phrase("Please re-enter your password", 3),
                                Phrase("Your order is ready", 1),
                                Phrase("Action required", 2),
                                Phrase("Account deactivation imminent", 3),
                                Phrase("Unusual sign-in activity", 3),

                                Phrase("Your credit card has been charged", 3),
                                Phrase("Your account will be suspended", 3),
                                Phrase("You have a new voicemail", 1),
                                Phrase("Your mailbox is full", 2),
                                Phrase("Free gift card", 1),
                                Phrase("You have a tax refund", 2),
                                Phrase("Your bank account has been locked", 3),
                                Phrase("You have a new payment", 2),
                                Phrase("Security alert", 3),
                                Phrase("You have a new friend request", 1)};

    stringstream buffer;
    buffer << file.rdbuf();
    string text = buffer.str();

    // Check the entire text against each object's text
    for (auto &obj : myObjects)
    {
        obj.isEqual(text);
    }

    file.close();
    for (auto &obj : myObjects)
    {
        cout << "Phrase " << obj.text << " | Points "<< obj.total <<endl;
    }
    cout << "Total Points: " << myObjects[0].Ultimate;
    return 0;
}
