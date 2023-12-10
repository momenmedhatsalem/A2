// File: A2_ALL_B_20221258_10.cpp
// Purpose: Assignment 2
// Author: Momen Medhat
// Section: ALL-B
// ID: 20221258
// TA: ……………………
// Date: 5 NOV 2023

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <sstream>
#include <ctime>
#include <cstdlib>

using namespace std;

map<string, vector<string>> loadCensoredWords(const string &filename) {
    ifstream file(filename);
    map<string, vector<string>> censoredWords;
    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string word, alternative;
        ss >> word;
        while (ss >> alternative) {
            censoredWords[word].push_back(alternative);
        }
    }
    return censoredWords;
}

string modifyWord(const string &word, const map<string, vector<string>> &censoredWords) {
    auto it = censoredWords.find(word);
    if (it != censoredWords.end()) {
        const vector<string> &alternatives = it->second;
        return alternatives[rand() % alternatives.size()];
    } else {
        return word;
    }
}

void modifyMessage(const string &inputFilename, const string &outputFilename, const map<string, vector<string>> &censoredWords) {
    ifstream inputFile(inputFilename);
    ofstream outputFile(outputFilename);
    string line;
    while (getline(inputFile, line)) {
        stringstream ss(line);
        string word;
        while (ss >> word) {
            outputFile << modifyWord(word, censoredWords) << " ";
        }
        outputFile << "\n";
    }
}

int main() {
    srand(time(0));
    map<string, vector<string>> censoredWords = loadCensoredWords("censored_words.txt");
    modifyMessage("message.txt", "modified_message.txt", censoredWords);
    return 0;
}
