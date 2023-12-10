// File: A2_ALL_B_20221258_11.cpp
// Purpose: Assignment 2
// Author: Momen Medhat
// Section: ALL-B
// ID: 20221258
// TA: ……………………
// Date: 5 NOV 2023


#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

void compareCharByChar(const string &filename1, const string &filename2) {
    ifstream file1(filename1), file2(filename2);
    string line1, line2;
    int lineNum = 1;
    while (getline(file1, line1) && getline(file2, line2)) {
        if (line1 != line2) {
            cout << "Files differ at line " << lineNum << ":\n";
            cout << filename1 << ": " << line1 << "\n";
            cout << filename2 << ": " << line2 << "\n";
            return;
        }
        lineNum++;
    }
    if (file1.eof() != file2.eof()) {
        cout << "Files differ at line " << lineNum << "\n";
    } else {
        cout << "Files are identical\n";
    }
}

void compareWordByWord(const string &filename1, const string &filename2) {
    ifstream file1(filename1), file2(filename2);
    string word1, word2;
    int lineNum = 1;
    while (file1 >> word1 && file2 >> word2) {
        if (word1 != word2) {
            cout << "Files differ at line " << lineNum << ":\n";
            cout << filename1 << ": " << word1 << "\n";
            cout << filename2 << ": " << word2 << "\n";
            return;
        }
        if (file1.peek() == '\n' && file2.peek() == '\n') {
            lineNum++;
        }
    }
    if (file1.eof() != file2.eof()) {
        cout << "Files differ at line " << lineNum << "\n";
    } else {
        cout << "Files are identical\n";
    }
}

int main() {
    string filename1, filename2, mode;
    cout << "Enter the first filename: ";
    cin >> filename1;
    cout << "Enter the second filename: ";
    cin >> filename2;
    cout << "Enter the comparison mode (char/word): ";
    cin >> mode;
    if (mode == "char") {
        compareCharByChar(filename1, filename2);
    } else if (mode == "word") {
        compareWordByWord(filename1, filename2);
    } else {
        cout << "Invalid comparison mode\n";
    }
    return 0;
}
