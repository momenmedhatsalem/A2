// File: A2_ALL_B_20221258_3.cpp
// Purpose: Assignment 2
// Author: Momen Medhat
// Section: ALL-B
// ID: 20221258
// TA: ……………………
// Date: 5 NOV 2023


#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

// Define the split function
vector<string> split(string target, string delimiter) {
    // Create a vector to store the words
    vector<string> words;
    // Create a stringstream object to read the target string
    stringstream ss(target);
    // Create a string variable to store each word
    string word;
    // Loop until the end of the stream
    while (getline(ss, word, delimiter[0])) {
        // Add the word to the vector
        words.push_back(word);
    }
    // Return the vector of words
    return words;
}

// Test the split function
int main() {
    // Define the target string and the delimiter
    string target = "do re mi fa so la ti do";
    string delimiter = " ";
    // Call the split function and store the result
    vector<string> result = split(target, delimiter);
    // Print the result
    for (string s : result) {
        cout << s << endl;
    }
    return 0;
}
