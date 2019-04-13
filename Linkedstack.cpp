#include "Linkedstack.h"
#include <iostream>
#include <sstream>
#include <fstream>
//default constructor
Linkedstack::Linkedstack()
{
	stackTop = NULL;
}

//deconstructor call to reset stack
Linkedstack::~Linkedstack()
{
	initializeStack();
}

//push into the string stack
void Linkedstack::push(string s)
{
	Node *newNode = new Node;
	newNode->data = s;
	newNode->next = stackTop;
	stackTop = newNode;
}

//pop operators from top of the stack and write to file the operator being popped.
void Linkedstack::pop(ofstream &outFile)
{
	Node *temp;
	if (top() == "C") {
		pop(outFile); //pop out c
		pop(outFile); // pop out the next operator
	}
	if (stackTop != NULL)
	{
		temp = stackTop;
		stackTop = stackTop->next;
		if ((temp->data != "(") && (temp->data != "["))    // does not print the "(" nor "[" to the file
		{
			outFile << temp->data << " ";
			ss << temp->data << " ";
		}
		delete temp;
	}
}

//reset the stack
void Linkedstack::initializeStack()
{
	Node *temp;
	while (stackTop != NULL)
	{
		temp = stackTop;
		stackTop = stackTop->next;
		delete temp;
	}
}

//evaluate the infix to postfix expression
void Linkedstack::evalExpress(string s, ofstream&outFile)
{
	if (s == "(")
	{
		push(s);
	}
	else if (s == ")")
	{
		while (top() != "(")
		{
			//If operators are between parenthesis pop from stack
			if (top() == "+" || top() == "-" || top() == "*" || top() =="/")
			{
				pop(outFile);
			}
			else { discordExp(outFile); exit(1); } //if no operator then discord entire expression and terminate program
		}
		pop(outFile); // Pop the "(" from stack
	}
	else if (s == "[") { push(s); }
	else if (s == "]")
	{
		while (top() != "[")
		{
			//If operators are between brackets pop from stack
			if (top() == "+" || top() == "-" || top() == "*" || top() == "/")
			{
				pop(outFile);
			}
			else { discordExp(outFile); exit(1); } // else discord the expression and terminate program
		}
		pop(outFile); // Pop the "["
	}

	else if (s == "+" || s == "-" || s == "*" || s == "/")
	{

		while (!isEmpty() && priority(top()) > priority(s)) 
		{
			pop(outFile);
		}
		push(s);
	}

	else if (s == "CE")
	{
		initializeStack();
		while (!isEmpty())
		{
			//cout << "In the stack" << top() << endl;
			pop(outFile);
		}
		discordExp(outFile);
	}
	else if (s == "C")
	{
		s.pop_back();
	}
	else
	{
		outFile << s << " ";
		ss << s << " ";
	}
}

// discord entire expression from file
void Linkedstack::discordExp(ofstream & outFile)
{
	outFile.close();
	outFile.open("output.txt", ofstream::trunc);
	//outFile.open(outfilename, ofstream::trunc);
	//outFile.open("C", ofstream::trunc);
}

// return if stack is empty
bool Linkedstack::isEmpty()
{
	return (stackTop == NULL);
}

// return if stack is full
bool Linkedstack::isFull()
{
	return false;
}

//return top of the stack
string Linkedstack::top()
{
	if (stackTop != NULL)
	{
		return stackTop->data;
	}
}

int Linkedstack::priority(string c)
{
	
	if (c == "*" || c == "/")
	{
		return 2;
	}
	if (c == "+" || c == "-")
	{
		return 1;
	}
	else
	{
		return 0;
	}
}


