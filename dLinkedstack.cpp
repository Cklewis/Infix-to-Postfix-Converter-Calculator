#include "dLinkedstack.h"
//Calculate results

//default constructor
dLinkedstack::dLinkedstack()
{
}

//deconstructor
dLinkedstack::~dLinkedstack()
{
	initializeStack();
}

//push into double stack
void dLinkedstack::push(double d)
{
	Node2 *newNode = new Node2;
	newNode->data = d;
	newNode->next = stackTop;
	stackTop = newNode;
}

//pop from the stack
void dLinkedstack::pop()
{
	Node2 *temp;
	if (stackTop != NULL)
	{
		temp = stackTop;
		stackTop = stackTop->next;
		delete temp;
	}
}

void dLinkedstack::initializeStack()
{
	Node2 *temp;
	while (stackTop != NULL)
	{
		temp = stackTop;
		stackTop = stackTop->next;
		delete temp;
	}
}

//evaluate the expression
void dLinkedstack::evalExpress(ofstream &outFile, Linkedstack &ls)
{
	int i = 0;
	while (ls.ss >> line)
	{		
		if (line == "*" || line == "/" || line == "+" || line == "-") 
		{ 
			//cout << "Entering iteration: " << ++i << endl; 
			evalOpr(outFile); 
		}
		else
		{
			double d;
			d = atof(line.c_str());
			push(d);
		}
	}
}

//evaluate the postfix expression 
void dLinkedstack::evalOpr(ofstream &outFile)
{
	double op2;
	double op1;
	if (!isEmpty())
	{
		//cout << top() << endl;
		op2 = top();
		pop();
		if(!isEmpty())
		{
			op1 = top();
			//cout << "\nFirst operand: " << op1 << endl;
			//cout << "\nSecond operand: " << op2 << endl;
			pop();
			if (line == "*") { push(op1 * op2);} //cout << op1*op2; 
			else if (line == "/") { push(op1 / op2); //cout << op1/op2;
			}
			else if (line == "+") { push(op1 + op2); // cout << op1+op2;
			}
			else if (line == "-") { push(op1 - op2); //cout << op1-op2;
			}
		}
		else
		{
			result = op2;
		}
	}
}

//call to print function
void dLinkedstack::printResults(ofstream & outFile)
{
	if (!isEmpty())
	{
		result = top();
		pop();
		outFile << "\n";
		outFile << setprecision(2) << fixed;
		outFile << result;
	}	
	else 
	{ 
		outFile << "\n";
		outFile << setprecision(2) << fixed;
		outFile << result;
	}
}

// empty stack
bool dLinkedstack::isEmpty()
{
	return (stackTop == NULL);
}

// full stack
bool dLinkedstack::isFull()
{
	return false;
}

// top of the stack
double dLinkedstack::top()
{
	if (stackTop!= NULL)
	{
		return stackTop->data;
	}
}
