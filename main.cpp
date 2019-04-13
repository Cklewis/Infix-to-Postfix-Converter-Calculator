#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include "Linkedstack.h"
#include "dLinkedstack.h"
#include "ArgumentManager.h"
#include <sstream>
using namespace std;


int main(int argc, char *argv[]) {
	ifstream inFile;
	ofstream outFile;
	//ArgumentManager am(argc, argv);
	//string infilename = am.get("A");
	//string outfilename = am.get("C");
	//inFile.open(infilename);
	//outFile.open(outfilename, ofstream::trunc);

	inFile.open("3.txt");
	outFile.open("output.txt");

	// check if file exist
	if (inFile.fail())
	{
		cout << "File name does not exist" << endl;
		exit(1);
	}

	// declare variables and objects
	string s;
	Linkedstack ls;
	dLinkedstack obj;

	// read from file to string s
	while (inFile >> s)
	{
		ls.evalExpress(s, outFile);
	}// end of while loop

	//  pop the remaining operators from stack
	while (!ls.isEmpty())
	{
		ls.pop(outFile);
	}

	//evaluate the number stack
	obj.evalExpress(outFile, ls);

	//print results
	obj.printResults(outFile);

	system("Pause");
	inFile.close();
	outFile.close();
	return 0;
}