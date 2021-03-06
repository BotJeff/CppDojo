// CppDojo.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

// Add a number to an int using pointers.
void addOne(int* num) {
	*num = *num + 1;
}

// Add a number to an int using pointers.
void addOneRef(int& num) {
	num = num + 1;
}

void writeToIOStream() {
	string quote = "this is my quote";
	string fileName = "quote.txt";
	ofstream writer(fileName);

	if (writer)
	{
		cout << "writing to file" << endl;
		writer << quote << endl;

		writer.close();
	}
	else {
		cout << "writer is null" << endl;
	}

	ofstream writer2(fileName, ios::app);

	if (writer2) {
		writer2 << "appended text" << endl;
		writer2.close();
	}
	else {
		cout << "Error opening file" << endl;
	}

	ifstream reader(fileName);

	if (reader) {
		
		string output;
		char letter;

		while (! reader.eof())
		{
			reader.get(letter);

			output += letter;
		}

		cout << output << endl;

		reader.close();
	}
	else {
		cout << "Error opening file" << endl;
	}

}

void halt() {
	cout << endl << "press any key to continue..." << endl;

	string input;
	getline(cin, input);
}

int main()
{
	string helloWorld = "Hello World";
	cout << helloWorld << endl;

	int num = 5;
	cout << num << endl;
	addOne(&num);
	cout << num << endl;
	addOneRef(num);
	cout << num << endl;
	
	

	writeToIOStream();

	halt();


    return 0;
}



