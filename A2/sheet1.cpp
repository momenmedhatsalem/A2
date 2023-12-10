#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string> split(string target, string delimiter);
int main()
{
    
    for(string s: split("a,bn.d,vvf", ","))
    {
        cout << s <<endl;
    }
}

vector<string> split(string target, string delimiter)
{
    vector <string> v;
    int pos = 0;
    string token;
    while ((pos = target.find(delimiter)) != string::npos) {
        token = target.substr(0, pos);
        v.push_back(token);
        target.erase(0, pos + delimiter.length());
    }
    v.push_back(target); // Get the last substring
    return v;
    
}