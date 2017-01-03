#pragma once

#include <string>
#include <iostream>
#include <math.h>
#include <vector>
#include <list>

using std::max;
using std::min;
using std::cout;
using std::endl;
using std::string;
using std::to_string;
using std::vector;
using std::list;

#include "msclStringFuncs.h"
#include "Namespace.h"
#include "StackFrame.h"
#include "Token.h"
#include "AstNode.h"
#include "SourceFile.h"

class Element;

class PineconeProgram
{
public:
	
	PineconeProgram();
	~PineconeProgram() {cleanUp();}
	
	string getCpp() {return outCpp;}
	
	void resolveProgram(string inFilename, bool printExtraOutput);
	
	Namespace getGlobalActionTable();
	
	void execute();
	
private:
	
	void cleanUp();
	
private:
	
	shared_ptr<StackFrame> globalFrame;
	
	SourceFile file;
	string outCpp;
	
	//a list of all the tokens in the program
	vector<Token> tokens;
	
	//root of the abstract syntax tree
	AstNode astRoot=nullptr;
	
	//root of the action tree
	Action actionRoot=createNewVoidAction();
	
	vector<char> whitespaceChars, letterChars, digitChars;
	char singleLineComment;
};

