#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>
using namespace std;
//THIS STACK IS USED TO CONVERT INFIX TO POSTFIX

struct Node
{
	string data;
	Node *next;
};

class Linkedstack
{
public:
	//stack functions
	Linkedstack();
	~Linkedstack();
	void push(string s);
	void pop(ofstream &outFile);
	void initializeStack();

	// evaluation functions
	void evalExpress(string s, ofstream & outFile);
	void discordExp(ofstream &outFile);

	//bool functions
	bool isEmpty();
	bool isFull();

	//variables
	stringstream ss;
	string top();
	int priority(string c);
	int temp;
	double num;
private:
	Node *stackTop = NULL;
};

