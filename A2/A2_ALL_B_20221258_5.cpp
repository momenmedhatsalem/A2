// File: A2_ALL_B_20221258_5.cpp
// Purpose: Assignment 2
// Author: Momen Medhat
// Section: ALL-B
// ID: 20221258
// TA: ……………………
// Date: 5 NOV 2023
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Player {
    string name;
    int score;
};

class Game {
private:
    vector<Player> top;
public:
    void addPlayer(string name, int score) {
        if (top.size() < 10 || score > top.back().score) {
            if (top.size() == 10) {
                top.pop_back();
            }
            top.push_back({name, score});
            sort(top.begin(), top.end(), [](const Player &a, const Player &b) {
                return a.score > b.score;
            });
        }
    }

    void printTopScores() {
        for (const auto &player : top) {
            cout << player.name << " " << player.score << "\n";
        }
    }

    void printPlayerScore(const string &name) {
        auto it = find_if(top.begin(), top.end(), [&name](const Player &player) {
            return player.name == name;
        });
        if (it != top.end()) {
            cout << it->name << " " << it->score << "\n";
        } else {
            cout << "Player not found in top 10.\n";
        }
    }
};

int main() {
    Game game;
    // Add players and scores here
    // game.addPlayer("Bill", 100);
    // game.addPlayer("Bob", 50);
    // Print top scores
    // game.printTopScores();
    // Print a player's score
    // game.printPlayerScore("Bill");
    return 0;
}
