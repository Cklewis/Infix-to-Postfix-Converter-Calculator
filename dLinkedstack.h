#pragma once
#include "Linkedstack.h"
//NOTE: THIS STACK IS USED TO CALCULATE THE RESULTS
struct Node2
{
	double data;
	Node2 *next;
};
class dLinkedstack :
	public Linkedstack
{
public:
	dLinkedstack();
	~dLinkedstack();
	void push(double d);
	void pop();
	void initializeStack();
	void evalExpress(ofstream & outFile, Linkedstack &ls);
	void evalOpr(ofstream &outFile);
	void printResults(ofstream &outFile);

	bool isEmpty();
	bool isFull();

	double result;
	double top();
	string line;
private:
	Node2* stackTop = NULL;
};