#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <map>
#include <cmath>
#include "input.h"

using namespace std;

int menuOption();
void textToNumMenu();
int textToNumMenuOption();
string newStringInput();
string textToNumConvert(string textString);
void numStringWrite(string numString);
void numStringRead(string numString);
void baseConverterMenu();
int baseConverterMenuOption();
void baseConversionSingle(int num1);
void baseConversionAll(int num1);
void descriptiveStatsMenu();
int main()
{ 
    do
    {
        switch (menuOption())
        {
        case 0: exit(1); break;
        case 1: textToNumMenu(); break;
        case 2: baseConverterMenu(); break;
        case 3: descriptiveStatsMenu(); break;
        default: cout << "\t\tERROR - Invalid option. Please re-enter."; break;
        }
        cout << "\n";
        system("pause");
    } while (true);

    return EXIT_SUCCESS;
}

int menuOption()
{
    system("cls");
    cout << "CMPR131 Chapter 1: Software Development by Saul Merino" << endl;
    cout << string(100, char(205)) << endl;

    cout << "1. ASCII Text To ASCII Numbers" << endl;
    cout << string(100, char(196)) << endl;

    cout << "2. Base Converter" << endl;
    cout << string(100, char(196)) << endl;

    cout << "3. Descriptive Statistics" << endl;
    cout << string(100, char(196)) << endl;

    cout << "0. Quit" << endl;
    cout << string(100, char(205)) << endl;
    int option = inputInteger("Option : ", 0, 3);
    return option;
}

void textToNumMenu()
{
    string textString;
    string convertedNumString;
    do
    {
        switch (textToNumMenuOption())
        {
        case 0: return; break;
        case 1: textString = newStringInput(); break;
        case 2: convertedNumString = textToNumConvert(textString); break;
        case 3: numStringWrite(convertedNumString); break;
        case 4: numStringRead(convertedNumString); break;
        default: cout << "\t\tERROR - Invalid option. Please re-enter."; break;
        }
        cout << "\n";
        system("pause");
    } while (true);
}

int textToNumMenuOption()
{
    system("cls");
    cout << "1: ASCII Text To ASCII Numbers" << endl;
    cout << string(100, char(205)) << endl;

    cout << "1. Enter A Text String" << endl;
    cout << "2. Convert The Text String to ASCII Numbers" << endl;
    cout << "3. Save The Converted ASCII Numbers into a Binary File" << endl;
    cout << "4. Read The Binary File" << endl;
    cout << string(100, char(196)) << endl;

    cout << "0. Return" << endl;
    cout << string(100, char(205)) << endl;
    int option = inputInteger("Option : ", 0, 4);
    return option;
}

// Precondition: None
// Postcondition: Returns a string
string newStringInput()
{
    return inputString("Enter A Text Line: ", true);
}

int newIntInput()
{
    return inputInteger("Enter An Integer in Base 10: ", true);
}

// Precondition: 
// Postcondition: returns a string converted to ASCII
string textToNumConvert(string textString)
{
    if (textString.empty())
    {
        cout << "No Text Was written. Please Type 1 to enter a text string." << endl;
        return textString;
    }
    // map containing the ASCII codes for each character
    /*map<char, string> asciiTable = { {'A', "65"},{'a', "97"}, {'B', "66"}, {'b', "98"}, {'C', "67"}, {'c', "99"},
                            {'D', "68"}, {'d', "100"}, {'E', "69"}, {'e', "101"}, {'F', "70"}, {'f', "102"},
                            {'G', "71"}, {'g', "103"}, {'H', "72"}, {'h', "104"}, {'I', "73"}, {'i', "105"},
                            {'J', "74"}, {'j', "106"}, {'K', "75"}, {'k', "107"}, {'L', "76"}, {'l', "108"},
                            {'M', "77"}, {'m', "109"}, {'N', "78"}, {'n', "110"}, {'O', "79"}, {'o', "111"},
                            {'P', "80"}, {'p', "112"}, {'Q', "81"}, {'q', "113"}, {'R', "82"}, {'r', "114"},
                            {'S', "83"}, {'s', "115"}, {'T', "84"}, {'t', "116"}, {'U', "85"}, {'u', "117"},
                            {'V', "86"}, {'v', "118"}, {'W', "87"}, {'w', "119"}, {'X', "88"}, {'x', "120"},
                            {'Y', "89"}, {'y', "121"}, {'Z', "90"}, {'z', "122"}, {'`', "96"}, {'~', "126"},
                            {'!', "33"}, {'@', "64"}, {'#', "35"}, {'$', "36"}, {'%', "37"}, {'^', "94"},
                            {'&', "38"}, {'*', "42"}, {'(', "40"}, {')', "41"}, {'-', "45"}, {'_', "95"},
                            {'=', "61"}, {'+', "43"}, {'{', "123"}, {'}', "125"}, {'[', "91"}, {']', "93"},
                            {'|', "124"}, {';', "59"}, {':', "58"}, {char(39), "39"}, {',', "44"}, {'.', "46"},
                            {'<', "60"}, {'>', "62"}, {'/', "47"}, {'?', "63"}, {char(92), "92"}, {char(34), "34"}, {char(32), "32"} };
    map<char, string>::iterator iter;*/

    string newString;
    char  tempInt;
    /*
    for (int index = 0; index < textString.length(); index++)
    {
        tempChar = textString[index];       
        newString += asciiTable.at(tempChar);
        newString += " ";
    }*/

    for (int index = 0; index < textString.length(); index++)
    {
        cout << int(textString[index]) << endl;
        newString += int(textString[index]);
        newString += " ";
        cout << newString;
    }

    cout << "Converted to ASCII Numbers:" << endl;
    cout << newString;
    return newString;
}

// Precondition:
// Postcondition:
void numStringWrite(string numString)
{
    // needs: use reinterpret_cast to write and read binary files
    fstream outfile;
    outfile.open("test.bin", ios::binary | ios::out);
    if (!outfile)
    {
        cout << "Cannot Open Test File, test.bin" << endl;
        exit(1);
    }
    outfile.write(reinterpret_cast<char*>(&numString), sizeof(numString));
    outfile.close();
    cout << "File, test.bin, has been written and saved.";
}

// Precondition:
// Postcondition:
void numStringRead(string numString)
{
    fstream infile;
    infile.open("test.bin", ios::binary | ios::in);
    cout << "Reading File, test.bin..." << endl;
    if (!infile)
    {
        cout << "Cannot Open Test File, test.bin" << endl;
        exit(1);
    }
    infile.read(reinterpret_cast<char*>(&numString), sizeof(numString));

    /*for (int index = 0; index < numString.length() - 1; index++)
    {
        cout << numString[index];
    }*/
    cout << endl;
    infile.close();
}

// Precondition:
// Postcondition:
void baseConverterMenu()
{
    int num1;
    do
    {
        switch (baseConverterMenuOption())
        {
        case 0: return; break;
        case 1: num1 = newIntInput(); break;
        case 2: baseConversionSingle(num1); break;
        case 3: baseConversionAll(num1); break;
        default: cout << "\t\tERROR - Invalid option. Please re-enter."; break;
        }
        cout << "\n";
        system("pause");
    } while (true);
}

int baseConverterMenuOption()
{
    system("cls");
    cout << "2: Base Converter" << endl;
    cout << string(100, char(205)) << endl;

    cout << "1. Enter an Integer Number (Base 10)" << endl;
    cout << "2. Specify the converting Base" << endl;
    cout << "3. Display All Converted Bases" << endl;
    cout << string(100, char(196)) << endl;

    cout << "0. Return" << endl;
    cout << string(100, char(205)) << endl;
    int option = inputInteger("Option : ", 0, 3);
    return option;
}

void baseConversionSingle(int num1)
{
    if (num1 == NULL)
    {
        cout << "No integer has been entered. Please Choose option 1 to enter a base 10 integer.";
        return;
    }
    int base = inputInteger("Enter the base to convert your number to (2..36): ", 2, 36);
    string binaryNumber = "";
    int temp1 = num1;
    do
    {
        int remainder = num1 % base;
        num1 /= base;
        binaryNumber.insert(0, to_string(remainder));
    } while (num1 >= base);
    binaryNumber.insert(0, to_string(num1));
    cout << temp1 << " (Base of 10) = " << binaryNumber << " (Base of " << base << ")" << endl;
}

void baseConversionAll(int num1)
{
        if (num1 == NULL)
        {   
            cout << "No integer has been entered. Please Choose option 1 to enter a base 10 integer.";
            return;
        }
        int tempNum = num1;
        cout << "Your number is " << num1 << "." << endl;
        string binaryNumber = "";
        for (int base = 2; base <= 36; base++)
        {
            num1 = tempNum;
            do
            {
                int remainder = num1 % base;
                num1 /= base;
                binaryNumber.insert(0, to_string(remainder));
            } while (num1 >= base);
            binaryNumber.insert(0, to_string(num1));
            cout << binaryNumber << " (Base of " << base << ")" << endl;
            binaryNumber.clear();
        }
}

// Precondition:
// Postcondition:
void descriptiveStatsMenu()
{

}


// for 3 use cmath
