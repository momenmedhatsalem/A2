#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <string>
#include <bitset>
using namespace std;

#include <vector>
#include <string>

#include <map>
#include <iomanip>
#include <map>


string intToHex(int num) {
    stringstream ss;
    ss << setfill('0') << setw(2) << hex << num;
    return ss.str();
}


class Memory {
protected:
    map<int, int> mem;

public:
    // Default constructor
    Memory(int size) {
        for(int i = 0; i < size; i++) {
            mem[i] = 0;
        }
    }

    // Function to set memory
    void setMemory(map<int, int> value) {
        mem = value;
    }

    // Function to clear a specific cell in memory
    void clearCell(int index) {
        if(mem.find(index) != mem.end()) {
            mem[index] = 0;
        }
    }

    // Function to clear all memory
    void clearMemory() {
        for(auto& it : mem) {
            it.second = 0;
        }
    }

    // Function to get the value of memory
    map<int, int> getMemory() {
        return mem;
    }
    int getcell(int key)
    {
        return mem[key];
    }
    void setCell(int key, int value) {
    mem[key] = value;
}

};

class Registers : public Memory {
public:
    // Default constructor
    Registers() : Memory(16) {}
};

class MainMemory : public Memory {
public:
    // Default constructor
    MainMemory() : Memory(256) {}
};




class Instructions {
    vector<string> instruct;

public:
    // Default constructor
    Instructions() {

    }

    // Function to read instructions from a file
    void readFromFile(string filename) {
        ifstream file(filename);
        string line;
        while (getline(file, line)) {
            instruct.push_back(line);
        }
        file.close();
    }

    // Function to decode instructions
    void decode() {
        // decoding logic here
    }

    // Function to get the value of instructions
    vector<string> getInstructions() {
        return instruct;
    }
    int size ()
    {
        return instruct.size();
    }
    void append(string x)
        {
            instruct.push_back(x);
        }
    void clear()
    {

        instruct.clear();
        return;
    }
    
};


class Machine {
private:
    int PC = 0; // Program Counter
    int IR; // Instruction Register

public:
    Instructions instructions; // Change this line
    MainMemory m;
    Registers R;
    Machine() : PC(0), IR(0) {}

    void loadProgram(const string& filename) {
        instructions.readFromFile(filename); // Change this line
    }



    void Rad_append(string x)
    {
        instructions.append(x);

    }

    void fetchInstruction(const string& filename) {
        ifstream file(filename);
        vector<string> instructions;

        if (file.is_open()) {
            string line;
            while (getline(file, line)) {
                // Validate the instruction here
                // For simplicity, let's assume all lines in the file are valid instructions
                instructions.push_back(line);
            }
            file.close();
        } else {
            cout << "Unable to open file: " << filename << '\n';
        }

        // Now the 'instructions' vector contains all the instructions from the file
        for (const auto& instruction : instructions) {
            cout << "Fetched instruction: " << instruction << '\n';
        }
    }

void run_all()
{
    // Instructions size
    int n = instructions.size();
    for (int i = 0; i < n; i++)
    {
        if (PC >= n)
        {
            return;
        }
        
        executeInstruction(instructions.getInstructions()[PC]);

    }
    
    //     for(auto x : instructions.getInstructions())
    // {
    //     executeInstruction(x);
    // }
}
void executeNextInstruction()
{
    executeInstruction(instructions.getInstructions()[PC]);
}

void executeInstruction(const string& instruction) {
    if (instruction.empty()) {
        cout << "Program Has Ended"<< endl;
        return;
    }

    char firstChar = instruction[0];
    char secondChar = instruction[1];
    PC++;
     
    string thirdChar(1, instruction[2]);
    string fourthchar(1, instruction[3]);
    string str(1, secondChar);
            int memory_pos = stoi(instruction.substr(2), nullptr, 16);
            int value = m.getcell(memory_pos);
            int R_pos = stoi(str, nullptr, 16);
            

    switch(firstChar) {
        case '1':
            // logic for case '1' here

            R.setCell(R_pos, value);
            break;
        case '2':
            // logic for case '2' here
            R.setCell(R_pos, memory_pos);

            break;
        case '3':
            // logic for case '3' here
            if (memory_pos == 0)
            {
                cout << R.getcell(R_pos);
            }
            else
            {
                
            m.setCell(memory_pos, R.getcell(R_pos));
            }
            
            break;
        case '4':
            // logic for case '4' here

            R.setCell(stoi(fourthchar, nullptr, 16), R.getcell(stoi(thirdChar, nullptr, 16)));
            
            break;
        case '5':
            R.setCell(stoi(str, nullptr, 16),addTwosComplementStrings(R.getcell(stoi(thirdChar, nullptr, 16)),R.getcell(stoi(fourthchar, nullptr, 16))));
            
            // logic for case '5' here
            break;
        case '6':
            // logic for case '6' here
            break;
        case 'B':
            // logic for case '7' here
            if (R.getcell(R_pos) == R.getcell(0))
            {
                PC = memory_pos - 1;
            }

            
            
            break;
        case 'C':
        return;
            // logic for case '7' here

        default:
            // logic for the default case here
            break;
    }
}

int addTwosComplementStrings(int num1, int num2) {
    // Convert hexadecimal strings to integers




    // Add the numbers
    int sum = num1 + num2;

    return sum;
}

int addHexTwosComplement(string hex1, string hex2) {
    // Convert hexadecimal to binary
    bitset<8> bin1(stoul(hex1, nullptr, 16));
    bitset<8> bin2(stoul(hex2, nullptr, 16));

    // Compute two's complement

    unsigned long ul1 = bin1.to_ulong(); // Convert to unsigned long
    unsigned long ul2 = bin2.to_ulong(); // Convert to unsigned long

    cout << bin1 <<endl;
    cout << bin2 <<endl;

    // Add the two numbers
    unsigned long sum = bin1.to_ulong() + bin2.to_ulong();

    return sum;
}





    void displayMachine() {
        cout << "Program Counter: " << this->PC << endl;
        cout << "Instruction Rgeister: " << this->IR << endl;

        // Display MainMemory
        cout << "MainMemory:" << endl;
        for (const auto& pair : m.getMemory()) {
            cout << "Address: " << pair.first << ", Value: " << intToHex(pair.second) << endl;
        }

        // Display Registers
        cout << "Registers:" << endl;
        for (const auto& pair : R.getMemory()) {
            cout << "Register: " << pair.first << ", Value: " << intToHex(pair.second) << endl;
        }
    }

   


    void run() {
        while (true) {
            cout << "1. Load a new program\n";
            cout << "2. Execute next instruction\n";
            cout << "3. Display machine status\n";
            cout << "4. Run All\n";

            cout << "5. Exit\n";
            cout << "Enter your choice: ";
            int choice;
            string filename;
            cin >> choice;
            switch (choice) {
                case 1:
                    cout << "Enter filename: ";
                    cin >> filename;
                    loadProgram(filename);
                    break;
                case 2:
                    executeNextInstruction();
                    break;
                case 3:
                    displayMachine();
                    break;
                case 4:
                    run_all();
                    break;               
                case 5:
                    return;
                default:
                    cout << "Invalid choice\n";
            }
        }
    }
};

int main() {
    Machine machine;
    machine.run();
    //machine.loadProgram("int.txt");
    //machine.run_all();
    //cout << machine.addHexTwosComplement("8F", "00");
    //machine.executeNextInstruction();

    //machine.run_all();


    //machine.displayMachine();
    return 0;
}
