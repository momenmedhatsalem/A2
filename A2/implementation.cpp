// File: A2_ALL_B_20221258_implementation.cpp
// Purpose: Assignment 2 Implementaion file of BigReal
// Author: Momen Medhat
// Section: ALL-B
// ID: 20221258
// TA: ……………………
// Date: 5 NOV 2023

#include "big.h"
#include <algorithm>
bool BigReal::isValidReal(string realNumber)
{
    int counter = 0;
    bool hasDecimalPoint = false;
    bool hasSign = false;

    for (char c : realNumber)
    {
        // Check if the character is a digit
        if (isdigit(c))
        {
            continue;
        }
        // Check if the character is a decimal point
        else if (c == '.')
        {
            // If there's more than one decimal point, it's not a valid number
            if (hasDecimalPoint)
            {
                return false;
            }
            hasDecimalPoint = true;
        }
        // Check if the character is a sign
        else if (c == '+' || c == '-')
        {
            // If there's already a sign or the sign is not at the beginning, it's not a valid number
            if (hasSign || counter != 0)
            {
                return false;
            }
            hasSign = true;
        }
        // Check if the character is a space or any other invalid character
        else
        {
            return false;
        }
        counter++;
    }

    return true;
}

BigReal::BigReal(string realNumber)
{
    // Check if the string is a valid real number[^2^][2]
    if (!isValidReal(realNumber))
    {
        cout << "Not a valid number" << endl;
        return;
    }

    // Set the sign
    if (realNumber[0] == '-')
    {
        sign = '-';
        realNumber.erase(0, 1); // Remove the sign from the string
    }
    else
    {
        sign = '+';
        if (realNumber[0] == '+')
        {
            realNumber.erase(0, 1); // Remove the sign from the string
        }
    }

    // Find the position of the decimal point
    size_t decimalPoint = realNumber.find('.');
    if (decimalPoint != string::npos)
    {
        floating_point_position = decimalPoint;
        realNumber.erase(decimalPoint, 1); // Remove the decimal point from the string
    }
    else
    {
        floating_point_position = realNumber.size(); // If there's no decimal point, it's at the end of the string
    }

    // Set the size
    size = realNumber.size();

    // Stream the string into the vector of digits
    digits.clear();
    for (char c : realNumber)
    {
        digits.push_back(c - '0'); // Subtract '0' to convert from ASCII to integer
    }
}

BigReal BigReal::operator-(BigReal &other)
{
    BigReal result2("0");

    BigReal result3(other);
    result2.digits = this->digits;
    result2.floating_point_position = this->floating_point_position;
    result2.size = this->size;
    result2.sign == this->sign;
    // + -ve
    if (this->sign == "+" && other.sign == "-")
    {
        BigReal x(other);
        x.sign = "+";
        return (*this + x);
    }
    // -ve +ve
    // -5 - 3
    else if (this->sign == "-" && other.sign == "+")
    {
        return (*this + other);
    }
    // -5 - -3
    if (this->sign == "-" && other.sign == "-")
    {
        BigReal x(other);
        x.sign = "+";
        return (x + *this);
    }

    if (result2.floating_point_position == other.floating_point_position)
    {

        if (result2.size < other.size)
        {

            for (int i = 0; i < (other.size - result2.size); i++)
            {
                result2.digits.push_back(0);
            }
        }

        int counter = other.size - 1;
        if (result2 > other)
        {
            /* code */

            for (auto it = other.digits.rbegin(); it != other.digits.rend(); ++it)
            {
                // 5.23 - 5.25
                result2.digits[counter] -= *it;
                if (result2.digits[counter] < 0 && counter != 0)
                {
                    result2.digits[counter] += 10;
                    int current = counter;
                    while (current >= 0)
                    {
                        if (result2.digits[current] != 0)
                        {
                            /* code */
                            result2.digits[current - 1] -= 1;
                            break;
                        }
                        current--;
                    }
                }

                counter--;
            }
        }
        else
        {
            for (auto it = result2.digits.rbegin(); it != result2.digits.rend(); ++it)
            {
                // 5.23 - 5.25
                result3.digits[counter] -= *it;
                if (result3.digits[counter] < 0 && counter != 0)
                {
                    result3.digits[counter] += 10;
                    int current = counter;
                    while (current >= 0)
                    {
                        if (result3.digits[current] != 0)
                        {
                            /* code */
                            result3.digits[current - 1] -= 1;
                            break;
                        }
                        current--;
                    }
                }

                counter--;
            }
            result2.digits = result3.digits;
            result2.floating_point_position = result3.floating_point_position;
            result2.size = result3.size;
            result2.sign = '-';
        }
    }

    else if (this->floating_point_position > other.floating_point_position)
    {
        int diff = this->size - this->floating_point_position;
        if (diff < (other.size - other.floating_point_position))
        {
            
            for (int i = 0; i < (other.size - other.floating_point_position - diff); i++)
            {

                result2.digits.push_back(0);
            }
        }

        int counter = max((other.digits.size() - other.floating_point_position + this->floating_point_position - 1), this->digits.size() - 1);

        for (auto it = other.digits.rbegin(); it != other.digits.rend(); ++it)
        {
            // 5.23 - 5.25

            result2.digits[counter] -= *it;
            if (result2.digits[counter] < 0 && counter != 0)
            {
                result2.digits[counter] += 10;
                int current = counter;
                while (current >= 0)
                {
                    if (result2.digits[current] != 0)
                    {
                        /* code */
                        if (result2.digits[current - 1])
                        {
                            /* code */
                            result2.digits[current - 1] -= 1;
                            break;
                        }
                        else
                        {
                            result2.digits[current - 1] = 9;
                        }
                    }
                    current--;
                }
            }

            counter--;
        }
    }
    else if (this->floating_point_position < other.floating_point_position)
    {
        
        int counter = other.size - 1;
        
        for (auto it = result2.digits.rbegin(); it != result2.digits.rend(); ++it)
        {
            // 5.23 - 5.25
            result3.digits[counter] -= *it;
            if (result3.digits[counter] < 0 && counter != 0)
            {
                result3.digits[counter] += 10;
                int current = counter;
                while (current >= 0)
                {
                    if (result3.digits[current - 1])
                    {
                        /* code */
                        result3.digits[current - 1] -= 1;
                        break;
                    }
                    else
                    {
                        result3.digits[current - 1] = 9;
                    }
                    current--;
                }
            }

            counter--;
        }
        result2.digits = result3.digits;
        result2.floating_point_position = result3.floating_point_position;
        result2.size = result3.size;
        result2.sign = '-';
    }

    return result2;
}

BigReal BigReal::operator+(BigReal &other)
{

    BigReal result2("0");

    result2.digits = this->digits;
    if (this->sign == "-" && other.sign == "-")
    {
        result2.sign = "-";
    }
    else if (this->sign == "+" && other.sign == "-")
    {
        BigReal x(other);
        x.sign = "+";

        return (*this - x);
    }
    else if (this->sign == "-" && other.sign == "+")
    {
        BigReal x(*this);
        x.sign = "+";

        return (other - x);
    }
    result2.floating_point_position = this->floating_point_position;
    result2.size = this->size;
    if (this->floating_point_position == other.floating_point_position)
    {

        if (this->size < other.size)
        {
            for (int i = 0; i < (other.size - this->size); i++)
            {
                result2.digits.push_back(0);
            }
        }

        int counter = other.size - 1;
        for (auto it = other.digits.rbegin(); it != other.digits.rend(); ++it)
        {

            result2.digits[counter] += *it;
            if (result2.digits[counter] >= 10 && counter != 0)
            {
                result2.digits[counter] -= 10;
                result2.digits[counter - 1] += 1;
            }

            counter--;
        }
    }
    // Rest of your code...

    // 50.2 0.233569
    else if (this->floating_point_position > other.floating_point_position)
    {
        
        int diff = this->size - this->floating_point_position;

//mmm
        if (diff < (other.size - other.floating_point_position))
        {

            for (int i = 0; i < (other.size - other.floating_point_position - diff); i++)
            {

                result2.digits.push_back(0);
            }
        }


        int counter = max((other.digits.size() - other.floating_point_position + this->floating_point_position - 1), this->digits.size() - 1);
        for (auto it = other.digits.rbegin(); it != other.digits.rend(); ++it)
        {

            result2.digits[counter] += *it;
            if (result2.digits[counter] >= 10 && counter != 0)
            {
                result2.digits[counter] -= 10;
                result2.digits[counter - 1] += 1;
            }

            counter--;
        }
    }
    // 0.1  500.2
    else if (this->floating_point_position < other.floating_point_position)
    {
        BigReal real(other);
        int diff = real.size - real.floating_point_position;

        if (real.size < this->size)
        {
            for (int i = 0; i < (this->size - this->floating_point_position - diff); i++)
            {

                real.digits.push_back(0);
            }
        }

        int counter = min((this->digits.size() - this->floating_point_position + real.floating_point_position - 1), real.digits.size() - 1);
        for (auto it = this->digits.rbegin(); it != this->digits.rend(); ++it)
        {

            real.digits[counter] += *it;
            if (real.digits[counter] >= 10 && counter != 0)
            {
                real.digits[counter] -= 10;
                real.digits[counter - 1] += 1;
            }

            counter--;
        }

        return real;
    }

    return result2;
}

bool BigReal::operator==(const BigReal &other) const
{
    if (size != other.size || floating_point_position != other.floating_point_position || sign != other.sign)
    {
        return false;
    }
    else
    {
        for (int i = 0; i < size; i++)
        {
            if (digits[i] != other.digits[i])
            {
                return false;
            }
        }
    }
    return true; // They are equal
}

bool BigReal::operator<(const BigReal &other) const
{
    {
        if (sign != other.sign)
        {
            return sign > other.sign;
        }
        else if (size != other.size)
        {
            return size < other.size;
        }
        else if (floating_point_position != other.floating_point_position)
        {
            return floating_point_position < other.floating_point_position;
        }
        else
        {
            for (int i = 0; i < size; i++)
            {
                if (digits[i] != other.digits[i])
                {
                    return digits[i] < other.digits[i];
                }
            }
        }
        return false; // They are equal
    }
}

bool BigReal::operator>(const BigReal &other) const
{
    return !(*this < other) && !(*this == other);
}

ostream &operator<<(ostream &out, BigReal num)
{
// Assuming num is an object of some class with a member vector<int> digits

// Check if all elements in num.digits are zero using all_of
    bool allZeros = all_of(num.digits.begin(), num.digits.end(), [](int digit) {
        return digit == 0;
    });

    if (allZeros) {

        num.sign == "+";
    }
    
    else if (num.sign == "-")
    {
        out << "-";
    }

    int counter = 0;
bool nonZeroEncountered = false;

for (int i : num.digits) {
    if (counter == num.floating_point_position) {
        out << ".";
    }

    if (i != 0 || nonZeroEncountered || counter == num.floating_point_position - 1) {
        out << i;
        nonZeroEncountered = true;
    }

    counter++;
}

    return out;
}
// BigReal BigReal::operator-(const BigReal &other) const
// {
//     BigReal result("0");
//     int borrow = 0;
//     for (int i = 0; i < size || borrow; ++i)
//     {
//         int digitDiff = digits[size - 1 - i] - borrow;
//         if (i < other.size)
//             digitDiff -= other.digits[other.size - 1 - i];
//         borrow = digitDiff < 0 ? 1 : 0;
//         if (borrow)
//             digitDiff += 10;
//         result.digits[result.size - 1 - i] = digitDiff;
//     }
//     while (result.size > 1 && result.digits.back() == 0)
//         result.digits.pop_back();
//     return result;
// }