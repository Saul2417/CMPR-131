#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <cstring>
#include <cctype>
#include <map>
#include <cmath>
#include "input.h"

//if (remainder  > 9)
// { 
//    char = remainder += some num
//   
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
void descriptiveStatisticsMenu();
int descriptiveStatisticsMenuOption();
void intArrayFileRead(int*& intArray, int& size);
void arrayMax(int* intArray, int size);
void arrayMin(int* intArray, int size);
void arrayRange(int* intArray, int size);
void arraySum(int* intArray, int size);
void arrayMean(int* intArray, int size);
void arrayMedian(int* intArray, int size);
void arrayFrequency(int* intArray, int size);
void arrayMode(int* intArray, int size);
void arrayStandardDeviation(int* intArray, int size);
void arrayVariance(int* intArray, int size);
void arrayMidrange(int* intArray, int size);
void arrayQuartiles(int* intArray, int size);
void arrayInterQuartileRange(int* intArray, int size);
void arrayOutliers(int* intArray, int size);
void arraySumOfSquares(int* intArray, int size);
void arrayMeanAbsDeviation(int* intArray, int size);
void arrayRootMeanSquare(int* intArray, int size);
void arrayVariationCoefficient(int* intArray, int size);
void arrayRelativeStandardDeviation(int* intArray, int size);
double arrayAverage(int* intArray, int size);
void quickSort(int arr[], int low, int high);
int partition(int arr[], int low, int high);
int* arrayAllocator(int size);
void displayArray(int* array, int size);

int main()
{ 
    do
    {
        switch (menuOption())
        {
        case 0: exit(1); break;
        case 1: textToNumMenu(); break;
        case 2: baseConverterMenu(); break;
        case 3: descriptiveStatisticsMenu(); break;
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
    int num1 = -1;
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
    if (num1 == - 1)
    {
        cout << "No integer has been entered. Please Choose option 1 to enter a base 10 integer.";
        return;
    }
    int base = inputInteger("Enter the base to convert your number to (2..36): ", 2, 36);
    string binaryNumber = "";
	char hex;
    int temp1 = num1;
    do
    {
        int remainder = num1 % base;
		
        num1 /= base;

		if (remainder > 9)
		{
			hex = remainder + 55;
			string hexNum(1, hex);
			binaryNumber.insert(0, hexNum);
		}
		else
		{
			binaryNumber.insert(0, to_string(remainder));
		}
        
    } while (num1 >= base);
	if (num1 > 9)
	{
		hex = num1 + 55;
		string hexNum(1, hex);
		binaryNumber.insert(0, hexNum);
	}
	else
	{
		binaryNumber.insert(0, to_string(num1));
	}
	
	


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
		char hex;
        cout << "Your number is " << num1 << "." << endl;
        string binaryNumber = "";
        for (int base = 2; base <= 36; base++)
        {
            num1 = tempNum;
            do
            {
                int remainder = num1 % base;
                num1 /= base;
				if (remainder > 9)
				{
					hex = remainder + 55;
					string hexNum(1, hex);
					binaryNumber.insert(0, hexNum);
				}
				else
				{
					binaryNumber.insert(0, to_string(remainder));
				}
            } while (num1 >= base);
			if (num1 > 9)
			{
				hex = num1 + 55;
				string hexNum(1, hex);
				binaryNumber.insert(0, hexNum);
			}
			else
			{
				binaryNumber.insert(0, to_string(num1));
			}
            cout << binaryNumber << " (Base of " << base << ")" << endl;
            binaryNumber.clear();
        }
}


// for 3 use cmath
void descriptiveStatisticsMenu()
{
	int* intArray = nullptr;
	int size = 0;

	do
	{
		switch (descriptiveStatisticsMenuOption())
		{
		case 0: return; // exit
		case 1: intArrayFileRead(intArray, size); break;// read, store and display into sorted dynamic array
		case 2: arrayMin(intArray, size); break;
		case 3: arrayMax(intArray, size); break; // maximum
		case 4: arrayRange(intArray, size); break;
		case 5: cout << "The size of the given data set is: " << size << "."; break;// size
		case 6: arraySum(intArray, size); break; // sum
		case 7: arrayMean(intArray, size); break; // mean
		case 8: arrayMedian(intArray, size); break; // median
		case 9: arrayFrequency(intArray, size); break; // frequencies
		case 10: arrayMode(intArray, size); break;// mode
		case 11: arrayStandardDeviation(intArray, size); break;// standard deviation
		case 12: arrayVariance(intArray, size); break;// variance
		case 13: arrayMidrange(intArray, size); break;// midrange
		case 14: // quartiles
			cout << "quartiles" << endl;
			break;

		case 15: // interquartile range
			cout << "interquartile range" << endl;
			break;

		case 16: // outliers
			cout << "outliers" << endl;
			break;

		case 17: // sum of squares
			cout << "sum of squares" << endl;
			break;

		case 18: // mean absolute deviation
			cout << "mean absolute deviation" << endl;
			break;

		case 19: // root mean square
			cout << "root mean square" << endl;
			break;

		case 20: // standard error of the mean
			cout << "standard error of the mean" << endl;
			break;

		case 21: // coefficient of variation
			cout << "coefficient of varitaion" << endl;
			break;

		case 22: // relative standard deviation
			cout << "relative standard deviation" << endl;
			break;

		case 23: // display all results and write to an output text file
			cout << "display all results and write to an output text file" << endl;
			break;

		default: cout << "Invalid option. Please try again."; break; // invalid option
		}
		system("pause");
	} while (true);
	delete[] intArray;
}

int descriptiveStatisticsMenuOption()
{
	system("cls");
	cout << "3: Descriptive Statistics" << endl;
	cout << "-------------------------------------------------------------" << endl;
	cout << "1. Read, store, and display data set   13. Mid Range" << endl;
	cout << "2. Minimum                             14. Quartiles " << endl;
	cout << "3. Maximum                             15. Interquartile Range" << endl;
	cout << "4. Range                               16. Outliers" << endl;
	cout << "5. Size                                17. Sum of Squares" << endl;
	cout << "6. Sum                                 18. Mean Absolute Deviation" << endl;
	cout << "7. Mean                                19. Root Mean Square" << endl;
	cout << "8. Median                              20. Standard Error of the Mean" << endl;
	cout << "9. Frequencies                         21. Coefficient of Variation" << endl;
	cout << "10. Mode                               22. Relative Standard Deviation" << endl;
	cout << "11. Standard Deviation                 23. Display and write all results to text file" << endl;
	cout << "12. Variance                                         " << endl;
	cout << "-------------------------------------------------------------" << endl;
	cout << "0. Return" << endl;
	cout << "-------------------------------------------------------------" << endl;

	int option = inputInteger("Option : ", 0, 23);
	return option;
}

void intArrayFileRead(int*& intArray, int& size)
{
	string fileName = inputString("Enter the File Name: ", true);
	fstream infile;
	infile.open(fileName, ios::in);
	cout << "Reading File." << endl;
	if (!infile)
	{
		cout << "Cannot Open File." << endl;
		exit(1);
	}

	string temp = "";
	while (infile >> temp)
	{
		size++;
	}
	intArray = arrayAllocator(size);

	infile.close();
	infile.open(fileName, ios::in);

	int index = 0;
	while (!infile.eof() && index < size)
	{
		infile >> intArray[index];
		cout << intArray[index] << " ";
		index++;
	}
	quickSort(intArray, 0, size);

	displayArray(intArray, size);

	infile.close();
}

void quickSort(int arr[], int low, int high)
{
	if (low < high)
	{
		/* pi is partitioning index, arr[p] is now
		at right place */
		int partitionIndex = partition(arr, low, high);

		// Separately sort elements before
		// partition and after partition
		quickSort(arr, low, partitionIndex - 1);
		quickSort(arr, partitionIndex + 1, high);
	}
}

// Precondition:
// Postcondition:
int partition(int arr[], int low, int high)
{
	int pivot = arr[low];

	while (low < high)
	{
		while (low < high && arr[high] >= pivot)
		{
			--high;
		}
			
		arr[low] = arr[high];

		while (low < high && arr[low] <= pivot)
		{
			++low;
		}			
		arr[high] = arr[low];
	}
	arr[low] = pivot;
	return low;
}

void arrayMax(int* intArray, int count)
{
	int minVal = 0;

	if (count == 0)
	{
		cout << "Array is empty. Select 1 to create an array.";
		return;
	}

	int maxVal = numeric_limits<int>::min();
	for (int index = 0; index < count; ++index)
	{
		if (intArray[index] > maxVal)
		{
			maxVal = intArray[index];
		}
	}

	cout << "Maximum: " << maxVal << endl;
}

void arrayMin(int* intArray, int size) 
{
	int maxVal = 0;

	if (size == 0) 
	{
		cout << "Array is empty. Select 1 to create an array.";
		return;
	}

	int minVal = numeric_limits<int>::max();
	for (int index = 0; index < size; ++index) 
	{
		if (intArray[index] < minVal) 
		{
			minVal = intArray[index];
		}
	}
	cout << "Maximum: " << minVal << endl;
}

void arrayRange(int* intArray, int size)
{
	if (size == 0)
	{
		cout << "Array is empty. Select 1 to create an array.";
		return;
	}

	int minVal = intArray[0];
	int maxVal = intArray[0];

	for (int index = 1; index < size; ++index)
	{
		if (intArray[index] < minVal) minVal = intArray[index];
		if (intArray[index] > maxVal) maxVal = intArray[index];
	}

	cout << "Range: " << maxVal - minVal;
}

void arraySum(int* intArray, int size)
{
	if (size == 0)
	{
		cout << "Array is empty. Select 1 to create an array.";
		return;
	}

	int sum = 0;
	for (int index = 0; index < size; ++index)
	{
		sum += intArray[index];
	}

	cout << "Sum: " << sum << endl;
}

void arrayMean(int* intArray, int size)
{
	if (size == 0)
	{
		cout << "Array is empty. Select 1 to create an array.";
		return;
	}
	int mean = 0;
	cout << "Mean" << arrayAverage(intArray, size);   // You can directly use calculateAverage
}

void arrayMedian(int* intArray, int size)
{
	int median = 0;

	if (size == 0) 
	{
		cout << "Array is empty. Select 1 to create an array.";
		return;
	}

	if (size % 2 == 0)
	{
		median = (intArray[size / 2 - 1] + intArray[size / 2]) / 2.0;
	}
	else
	{
		median = intArray[size / 2];
	}

	cout << "Median: " << median << endl;
}

void arrayFrequency(int* intArray, int size)
{
	if (size == 0) 
	{
		cout << "Array is empty. Select 1 to create an array.";
		return;
	}

	cout << "Element\tFrequency\tPercentage" << endl;
	cout << "=======\t=========\t==========" << endl;

	int frequency = 1;
	for (int index = 0; index < size; ++index)
	{
		if (index < size - 1 && intArray[index] == intArray[index + 1])
		{
			++frequency;
		}
		else
		{
			double percentage = ((double)frequency / size) * 100;
			cout << intArray[index] << "\t" << frequency << "\t\t" << percentage << "%" << endl;
			frequency = 1;
		}
	}
	cout << "Frequency: " << frequency << endl;
}

void arrayMode(int* intArray, int size)
{
	if (size == 0)
	{
		cout << "Array is empty. Select 1 to create an array.";
		return;
	}

	int highestFreq = 0;
	int mode = intArray[0];
	int freq = 1;

	for (int index = 1; index < size; ++index)
	{
		if (intArray[index] == intArray[index - 1])
		{
			++freq;
		}
		else {
			freq = 1;
		}
		if (freq > highestFreq)
		{
			highestFreq = freq;
			mode = intArray[index];
		}
	}

	if (highestFreq == 1)
	{
		cout << "No mode found, all numbers appear only once." << endl;
	}
	else
	{
		cout << "Mode: " << mode << " (Frequency: " << highestFreq << ")" << endl;
	}
}

void arrayStandardDeviation(int* intArray, int size)
{

	if (size == 0) 
	{
		cout << "Array is empty. Select 1 to create an array.";
		return;
	}

	double mean = arrayAverage(intArray, size);
	double sumOfSquares = 0;

	for (int index = 0; index < size; ++index)
	{
		sumOfSquares += (intArray[index] - mean) * (intArray[index] - mean);
	}

	cout << "Standard Deviation: " << sqrt(sumOfSquares / size);
}

void arrayVariance(int* intArray, int size)
{
	if (!intArray)
	{
		cout << "Array is empty. Select 1 to create an array.";
		return;
	}
	if (size == 1) 
	{
		cout << "Varriance cannot de calculated with an array with a size of 1.";
		return;
	}

	// First calculate the mean
	int sum = 0;
	for (int index = 0; index < size; ++index)
	{
		sum += intArray[index];
	}
	double mean = static_cast<double>(sum) / size;

	// Now calculate the variance
	double variance = 0;
	for (int index = 0; index < size; ++index)
	{
		variance += pow(intArray[index] - mean, 2);
	}
	variance /= size;

	cout << "Variance: " << variance;
}

void arrayMidrange(int* intArray, int size)
{
	if (size == 0) 
	{
		cout << "Array is empty. Select 1 to create an array.";
		return;
	}

	int minVal = 0;
	int maxVal = 0;

	for (int index = 0; index < size; ++index)
	{
		if (intArray[index] < minVal)
		{
			minVal = intArray[index];
		}
		else if (intArray[index] > maxVal)
		{
			maxVal = intArray[index];
		}
	}

	cout << "Midrange: " << static_cast<double>(minVal + maxVal) / 2;
}

double arrayAverage(int* intArray, int size)
{
	if (size == 0) 
	{
		cout << "Array is empty. Select 1 to create an array.";
		exit(1);
	}

	int sum = 0;
	for (int index = 0; index < size; ++index) 
	{
		sum += intArray[index];
	}

	return static_cast<double>(sum) / size;
}

void arrayQuartiles(int* intArray, int size)
{
	if (size == 0)
	{
		cout << "Array is empty. Select 1 to create an array.";
		return;
	}
}

void arrayInterQuartileRange(int* intArray, int size)
{
	if (size == 0)
	{
		cout << "Array is empty. Select 1 to create an array.";
		return;
	}
}

void arrayOutliers(int* intArray, int size)
{
	if (size == 0)
	{
		cout << "Array is empty. Select 1 to create an array.";
		return;
	}

}

void arraySumOfSquares(int* intArray, int size)
{
	if (size == 0)
	{
		cout << "Array is empty. Select 1 to create an array.";
		return;
	}
}

void arrayMeanAbsDeviation(int* intArray, int size)
{
	if (size == 0)
	{
		cout << "Array is empty. Select 1 to create an array.";
		return;
	}
}

void arrayRootMeanSquare(int* intArray, int size)
{
	if (size == 0)
	{
		cout << "Array is empty. Select 1 to create an array.";
		return;
	}
}

void arrayVariationCoefficient(int* intArray, int size)
{
	if (size == 0)
	{
		cout << "Array is empty. Select 1 to create an array.";
		return;
	}

}

void arrayRelativeStandardDeviation(int* intArray, int size)
{
	if (size == 0)
	{
		cout << "Array is empty. Select 1 to create an array.";
		return;
	}
}

//Precondition: size cannot be negative value
//Postcondition: returns a valid pointer(address) of the newly allocated array
int* arrayAllocator(int size)
{
	int* newArray = nullptr;
	if (size <= 0)
		return nullptr;
	else
		return new int[size];
}

void displayArray(int* array, int size)
{
	cout << "Data Set With " << size << " data:" << endl;
	cout << "{ ";
	for (int index = 0; index < size; index++)
	{
		cout << array[index] <<  ", ";

		if (index != 0 && (index + 1) % 15 == 0)
		{
			cout << endl;
		}
	}
	
	cout << "}" << endl;
}
