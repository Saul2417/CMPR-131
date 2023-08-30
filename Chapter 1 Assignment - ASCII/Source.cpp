// Erik Santana
// 8/22/23
// CPMR 131 - Professor Q

#include <iostream>
#include <string>
#include <fstream>
#include "input.h"

using namespace std;

int mainMenu();
int option1();
void option2();
void option3();

int main()
{
    mainMenu();


	return 0;
}

// Pre - Conditon
//Post-Condition
int mainMenu()
{

    cout << endl;
    cout << "\tCMPR131 - Chapter 1 Software Development by Erik Santana(8 / 22 / 23)";
    cout << "\n\t" << string(80, char(205)) << endl;
    cout << "\t1 > ASCII Text To ASCII Numbers" << endl;
    cout << "\t2 > Base Converter" << endl;
    cout << "\t3 > Descriptive Statistics" << endl;
    cout << "\n\t" << string(80, char(169));
    cout << "\n\t0 > exit" << endl;
    cout << "\n\t" << string(80, char(205)) << endl;

    int option = inputInteger("\n\tOption: ", 0, 3);

    do
    {
        switch (option)
        {
        case 0: exit(1); break;
        case 1: option1(); break;
        case 2: option2(); break;
        case 3: option3(); break;

        default: cout << "\t\tERROR - Invalid option. Please re-enter."; break;
        }
        cout << "\n";
        system("pause");
    } while (true);

}

//Pre-Conditon
//Post-Condition
int option1()
{
    string textLine;
    string textFile;

    do{

    cout << "\n\t1 > ASCII Text To ASCII Numbers";
    cout << "\n\t" << string(80, char(205)) << endl;
    cout << "\n\t1 > Enter a text string";
    cout << "\n\t2 > Convert the text string to ASCII numbers";
    cout << "\n\t3 > Save the converted ASCII numbers into a binary file";
    cout << "\n\t4 > Read the binary file";
    cout << "\n\t" << string(80, char(169));
    cout << "\n\t0 > return";
    cout << "\n\t" << string(80, char(205)) << endl;

    int option = inputInteger("\n\tOption: ", 0, 4);

        switch (option)
        {
        case 0: exit(1); break;
        case 1: 
        {
            textLine = inputString("\n\tEnter a text line: ", true);
        }
            break;
        case 2: 
        {

            cout << endl;
            for (int i = 0; i < textLine.size(); i++)
            {
                cout << "\t" << static_cast<int>(textLine[i]) << " ";
            }
            cout << endl;
        }
        break;
        case 3: 
        {
            textFile = inputString("Enter the name of the binary file: ", true);
            ofstream outputFile(textFile, ios::binary);

            if (!outputFile) {
                cout << "Error opening file for writing!" << endl;
                return 1;
            }

            // Writing data to the binary file
            outputFile.write(textLine.c_str(), textLine.size());

            outputFile.close();

            cout << "Data has been written to " << textFile << endl;
        }
        break;
        case 4: 
        {
            ifstream inputFile(textFile, ios::binary);

            if (!inputFile) {
                cout << "Error opening file for reading!" << endl;
                return 1;
            }

            // Seek to the end of the file to get the file size
            inputFile.seekg(0, ios::end);
            streampos fileSize = inputFile.tellg();
            inputFile.seekg(0, ios::beg);

            // Read the entire file content into a buffer
            string fileContent(fileSize, ' ');
            inputFile.read(&fileContent[0], fileSize);

            inputFile.close();

            cout << "Data read from " << textFile << ":" << endl;
            for (int i = 0; i < textLine.size(); i++)
            {
                cout << "\t" << static_cast<int>(fileContent[i]) << " ";
            }
            
        }
              break;

        default: cout << "\t\tERROR - Invalid option. Please re-enter."; break;
        }
        cout << "\n";
        system("pause");
    } while (true);

}

//Pre-Conditon
//Post-Condition
void option2()
{
    int decimalNumber = 0;

    do {

        cout << "\n\t2> Base Converter";
        cout << "\n\t" << string(80, char(205)) << endl;
        cout << "\n\t1 > Enter an integer number (base 10)";
        cout << "\n\t2 > Specify and convert base";
        cout << "\n\t3 > Display all converted bases (2..36)";
        cout << "\n\t" << string(80, char(169));
        cout << "\n\t0 > return to Main Menu";
        cout << "\n\t" << string(80, char(205)) << endl;

        int option = inputInteger("\n\tOption: ", 0, 3);

        switch (option)
        {

        case 0: system("cls"); mainMenu(); break;
        case 1: 
        {
            decimalNumber = inputInteger("Enter an integer number of base 10: ", true);

        }break;
        case 2: 
        {
            cout << "Your number is " << decimalNumber << "." << endl;

            int base = inputInteger("Enter the base to convert your number to (2..36): ", 2, 36);
            string binaryNumber = "";

            if (base == 2)
            {
                while (decimalNumber > 0)
                {
                    int remainder = decimalNumber % base;
                    binaryNumber = to_string(remainder) + binaryNumber;
                    decimalNumber /= base;
                }

                
            }

            cout << binaryNumber << endl;


            //string binaryNumber = "";

            //while (decimalNumber > 0) {
            //    int remainder = decimalNumber % 2;
            //    binaryNumber = to_string(remainder) + binaryNumber;
            //    decimalNumber /= 2;
            //    
            //}

            //cout << binaryNumber << endl;

            //int digit = 0;

            // While the decimal(base 10) number is greater than 0
            // update digit and baseNum
            // digit = digit * 10 + the remainder of baseNum / decimalNumber
            // baseNum = the quotient of baseNum / decimalNumber
            // Then baseNum is updated in the condition in the while statement.
            //while (baseNum > 0) {
            //    digit = digit * 10 + (baseNum % decimalNumber);
            //    baseNum /= decimalNumber;
            //}

            //cout << digit << endl;


        }break;
        case 3:  break;

        }

    } while (true);

}

//Pre-Conditon
//Post-Condition
void option3()
{


}
