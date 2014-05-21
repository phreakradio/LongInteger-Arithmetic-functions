#include <iomanip>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include "listadt.h"

#ifndef longInt_H
#define longInt_H

using namespace std;

class longInt
{
	private:
		LIST x;	
		char sign;
		
	public:
	
		void testINITIALIZE();			//TESTING listadt FUNCTIONS *IGNORE THIS*
		void INITIALIZE( string S );
		char GETSIGN();
		void SETSIGN( char S );
		int GETDIGITCOUNT();
		void PRINT();
		bool GREATERTHAN( longInt Q );		
		bool LESSTHAN( longInt Q );		
		bool EQUALTO( longInt Q );
		int OVER_FLOW( int& T );
		int DIGIT(int T);
		longInt ADD( longInt Q );
		longInt SUBTRACT( longInt Q );
		longInt MULTIPLY( longInt Q );
		longInt DIVIDE( longInt Q);
		longInt POWER( int p );
};

#endif