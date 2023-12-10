// File: A2_ALL_B_20221258_7.cpp
// Purpose: Assignment 2
// Author: Momen Medhat
// Section: ALL-B
// ID: 20221258
// TA: ……………………
// Date: 5 NOV 2023

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct dominoT {
    int leftDots;
    int rightDots;
};

bool FormsDominoChain(vector<dominoT> & dominos, int index = 0) {
    if (index == dominos.size()) {
        for (int i = 1; i < dominos.size(); i++) {
            if (dominos[i - 1].rightDots != dominos[i].leftDots) {
                return false;
            }
        }
        return true;
    }
    for (int i = index; i < dominos.size(); i++) {
        swap(dominos[index], dominos[i]);
        if (FormsDominoChain(dominos, index + 1)) {
            return true;
        }
        swap(dominos[index], dominos[i]);
    }
    return false;
}

void PrintDominoChain(const vector<dominoT> & dominos) {
    for (const auto &domino : dominos) {
        cout << domino.leftDots << "|" << domino.rightDots << " ";
    }
    cout << "\n";
}

int main() {
    vector<dominoT> dominos = {{2, 6}, {6, 1}, {1, 4}, {4, 4}, {4, 3}};
    if (FormsDominoChain(dominos)) {
        PrintDominoChain(dominos);
    } else {
        cout << "No valid domino chain can be formed.\n";
    }
    return 0;
}
