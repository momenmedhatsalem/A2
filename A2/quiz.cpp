#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Stack
{
protected:
    int sz = 0;
    int data[100];

public:
    virtual void push(int item)
    {
        data[sz++] = item;
    }
    virtual int pop() { return data[--sz]; }

};
class LimitedStack : public Stack
{
public:
    void push(int item)
    {
        if (sz < 100)
            cout << " ";
    }
    int pop()
    {
        if (sz < 0)
            cout << " ";

        return -1;
    }
};
int main()
{

}
