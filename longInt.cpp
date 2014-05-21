#include <iomanip>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "listadt.h"
#include "longInt.h"

using namespace std;

//INITIALIZE
/* TAKES STRING INPUT AND CONVERTS IT TO longInt OBJECT */
void longInt::INITIALIZE( string S )
{
	string temp;
	int tempValue;				//THIS IS THE VALUE WE'LL BE INPUTTING
	int index = S.length();		//LENGTH/POSITION OF STRING INPUT	
	int times = index/4;		//HOW MANY NODES WITH MAX # OF DIGITS WILL WE GET?
	int remainder = index%4;	//THE FIRST NODE MAY NOT COMPLETELY BE 4 DIGITS
	for(int i=0; i<times ; i++,index-=4)
	{
		temp = S.substr(index-4,4);
		tempValue = atoi(temp.c_str());
		this->x.INSERT_LEFT(tempValue);
	}
	if(S[0]=='-')
	{
		this->SETSIGN('-');
		temp = S.substr(1,remainder-1);
		tempValue = atoi(temp.c_str());
		this->x.INSERT_LEFT(tempValue);				
	}
	else
	{
		this->SETSIGN('+');
		if(index==0)
			return;
			temp = S.substr(0,remainder);
		tempValue = atoi(temp.c_str());
		this->x.INSERT_LEFT(tempValue);				
	}
	return;
}

//GETSIGN
/* RETURNS SIGN OF longInt OBJECT */
char longInt::GETSIGN()
{return this->sign;}

//SETSIGN
/* SETS SIGN OF longInt OBJECT */
void longInt::SETSIGN( char S )
{	
	this->sign = S;
	return;		
}

//GETDIGITCOUNT
/* RETURNS # OF DIGITS IN longInt OBJECT */
int longInt::GETDIGITCOUNT()
{	
	int acc;
	node *temp;		
	temp = this->x.GET_FIRST();
	acc = DIGIT(temp->value);		//GET DIGITS OF FIRST NODE / IT'S NOT ALWAYS 4
	while (!this->x.IS_LAST(temp))
	{
		temp = this->x.NEXT_RIGHT(temp);
		acc += 4;
	}
	
	return acc;	
}

//PRINT
/* PRINTS longInt OBJECT */
void longInt::PRINT()
{	
	if(this->sign == '-')
		cout << '-';
	node* temp;
	temp = this->x.GET_FIRST();
	// cout << temp->value << " " ;
	cout << temp->value;
	while (!this->x.IS_LAST(temp))
	{
		temp = this->x.NEXT_RIGHT(temp);
		// cout << setfill('0') << setw(4) << temp->value << " ";		//PRINTS WITH SPACES
		cout << setfill('0') << setw(4) << temp->value;		//SOME NODES HAVE LEADING ZEROS 
	}
	cout << endl;
	return;	
}

//GREATERTHAN
/* COMPARES THE longInt OBJECT THAT CALLS THE FUNCTION AGAINST A longInt PARAMETER */
bool longInt::GREATERTHAN( longInt Q )
{	
	node* temp1;
	node* temp2;

	LIST butts = this->x;
	LIST morebutts = Q.x;
	
	temp1 = butts.GET_FIRST();
	temp2 = morebutts.GET_FIRST();
				
	if(this->sign == '+' and Q.sign == '-')
		return true;
	if(this->sign == '-' and Q.sign == '+')
		return false;
	if(this->GETDIGITCOUNT() > Q.GETDIGITCOUNT())
		return true;
	if(this->GETDIGITCOUNT() < Q.GETDIGITCOUNT())
		return false;
	
	//COMPARING NEGATIVE NUMBERS
	/*---------------ADDENDUM---------------*/
	if(this->sign == Q.sign && this->sign == '-')
	{
		while(!x.IS_LAST(temp1))
		{
			if( (temp1->value > temp2->value) )
				return false;
			if( (temp1->value < temp2->value) )
				return true;
			temp1 = butts.NEXT_RIGHT(temp1);
			temp2 = morebutts.NEXT_RIGHT(temp2);
		}
	}
	/*---------------ADDENDUM---------------*/
	
	while(!x.IS_LAST(temp1))
	{
		if( (temp1->value > temp2->value) )
			return true;
		if( (temp1->value < temp2->value) )
			return false;
		temp1 = butts.NEXT_RIGHT(temp1);
		temp2 = morebutts.NEXT_RIGHT(temp2);
	}
}		

//LESSTHAN
/* COMPARES THE longInt OBJECT THAT CALLS THE FUNCTION AGAINST A longInt PARAMETER */
bool longInt::LESSTHAN( longInt Q )
{	
	node* temp1;
	node* temp2;
	
	LIST butts = this->x;
	LIST morebutts = Q.x;
	
	temp1 = butts.GET_FIRST();
	temp2 = morebutts.GET_FIRST();
				
	if(this->sign == '+' and Q.sign == '-')
		return false;
	if(this->sign == '-' and Q.sign == '+')
		return true;
	if(this->GETDIGITCOUNT() < Q.GETDIGITCOUNT())
		return true;
	if(this->GETDIGITCOUNT() > Q.GETDIGITCOUNT())
		return false;
			
	while(!x.IS_LAST(temp1))
	{
		if( (temp1->value > temp2->value) )
			return false;
		if( (temp1->value < temp2->value) )
			return true;
		temp1 = butts.NEXT_RIGHT(temp1);
		temp2 = morebutts.NEXT_RIGHT(temp2);
	}
	if( temp1->value >= temp2->value )
		return false;
	return true;
}

//EQUALTO
/* COMPARES THE longInt OBJECT THAT CALLS THE FUNCTION AGAINST A longInt PARAMETER */
bool longInt::EQUALTO( longInt Q )
{
	node* temp1;
	node* temp2;
		
	LIST butts = this->x;
	LIST morebutts = Q.x;
	
	temp1 = butts.GET_FIRST();
	temp2 = morebutts.GET_FIRST();
	
	if (this->GETSIGN() != Q.GETSIGN())
		return false;
	if (this->GETDIGITCOUNT() != Q.GETDIGITCOUNT())
		return false;
	
	while(!x.IS_LAST(temp1))
	{
		if( (temp1->value != temp2->value) )
			return false;
		temp1 = butts.NEXT_RIGHT(temp1);
		temp2 = morebutts.NEXT_RIGHT(temp2);
	}
	
	if( temp1->value != temp2->value )
		return false;
	return true;
}

//OVER_FLOW
/* MAINTAINS STRUCTURE OF NODES IN longInt OBJECT. 
   SOMETIMES, NODES ARE OUT OF BOUNDS AND MUST BE ADJUSTED */
int longInt::OVER_FLOW( int& T )
{
	int temp = T;
	if(DIGIT(temp)>4)
	{
		temp = temp / 10000;
		T = T - (temp*10000);
		return temp;
	}
	return 0;
}

//DIGIT
/* RETURNS # OF DIGITS IN longInt NODE */
int longInt::DIGIT(int T)
{
	int acc = 1;
	int temp = T;
	while (temp >= 10)
	{
		temp /= 10;
		acc++;
	}
	return acc;			
}

/** ARITHMETIC FUNCTIONS **/

longInt longInt::ADD( longInt Q )
{
	//ADD DIFFERENT SIGN 
	
	longInt result;
	
	/* | I'm sure there's a simpler way to do this | */
	/* | ....but screw it, it works.			   | */
	
	/*---------SETTING SIGNS---------*/
	if( (this->sign == '+' and Q.sign == '-' 				//IF THIS VALUE IS POSITIVE, AND THE PARAMETER IS NEGATIVE...
			and 
		( this->GETDIGITCOUNT() > Q.GETDIGITCOUNT() ) 		//...AND THIS VALUE IS LONGER THAN THE PARAMETER...
		) 
			or												//... OR ...
		( this->sign == '-' and Q.sign == '+'				//...IF PARAMETER IS POSITIVE, AND THIS VALUE IS NEGATIVE... 
			and 
		( this->GETDIGITCOUNT() < Q.GETDIGITCOUNT() ) 		//AND THE PARAMETER IS LONGER THEN THIS VALUE
		) 
	){result.sign = '+';}									//OUR RESULT WILL BE POSITIVE
	
	//SAME LOGIC AS ABOVE, BUT REVERSED
	if(	(this->sign == '+' and Q.sign == '-' 
			and 
		( this->GETDIGITCOUNT() < Q.GETDIGITCOUNT() ) 
		)
			or
		( this->sign == '-' and Q.sign == '+' 
			and 
		( this->GETDIGITCOUNT() > Q.GETDIGITCOUNT() ) 
		)
	){result.sign = '-';}
	
	//AND IF THEY'RE EQUAL...well ya know
	if(this->sign == Q.sign)
		result.sign = Q.sign;
	/*---------SETTING SIGNS---------*/
	
	node* r1, *r2; 
	
	LIST a = this->x;
	LIST b = Q.x;
	
	r1 = a.GET_LAST(); 	//THIS
	r2 = b.GET_LAST();	//Q
	
	int sum = r1->value + r2->value;
	int carry = OVER_FLOW(sum);
	
	result.x.INSERT_LEFT(sum);
	
	while(!a.IS_FIRST(r1) && !b.IS_FIRST(r2)) 
	{ 
		r1 = a.NEXT_LEFT(r1); 
		r2 = b.NEXT_LEFT(r2); 
		
		sum = r1->value + r2->value + carry; 
		carry = OVER_FLOW(sum); // Enforce 4 digit rule 
		result.x.INSERT_LEFT(sum);
	}
	
	//IF THIS VALUE IS LONGER THAN PARAMETER
	if( this->GETDIGITCOUNT() > Q.GETDIGITCOUNT() )
	{
		r1 = a.NEXT_LEFT(r1);
		sum = r1->value + carry;
		result.x.INSERT_LEFT(sum);
		while(!a.IS_FIRST(r1))
		{	
			r1 = a.NEXT_LEFT(r1);
			result.x.INSERT_LEFT(r1->value);
		}
		result.sign = '-';
	}
	
	//IF PARAMETER LONGER THAN THIS VALUE
	if( this->GETDIGITCOUNT() < Q.GETDIGITCOUNT() )
	{
		r2 = b.NEXT_LEFT(r2);
		sum = r2->value + carry;
		result.x.INSERT_LEFT(sum);
		while(!b.IS_FIRST(r2))
		{	
			r2 = b.NEXT_LEFT(r2);
			result.x.INSERT_LEFT(r2->value);
		}
	}
	return (result);
}
			
longInt longInt::SUBTRACT( longInt Q ) 
{	
	longInt result;	
	//IN THE EVENT THAT WE ARE SUBTRACTING THE SAME NUMBER FROM ITSELF, WE'RE LEFT WITH ZERO
	if( this->EQUALTO(Q) )
	{
		result.x.INSERT_LEFT(0);
		return result;
	}
		
	node* r1, *r2, *tempA, *tempB; 
	int diff, overflow, temp;									//WE'RE GOING TO KEEP TRACK OF HOW MANY CALCULATIONS RESULT IN 0
	LIST a = this->x;
	LIST b = Q.x;
	//a-b
		
	r1 = a.GET_LAST();							//GET LAST NODES
	r2 = b.GET_LAST();
	tempA = a.NEXT_LEFT(r1);					//KEEP THE SECOND TO LAST NODE HANDY
	tempB = b.NEXT_LEFT(r2);
	
	if( this->GREATERTHAN( Q ) )				//IF THIS VALUE GREATER THAN PARAMETER
	{											//WE WILL CARRY OUT SUBTRACTION HOW WE NORMALLY WOULD
		if(r1->value > r2->value)
			diff = r1->value - r2->value;
		if(r1->value < r2->value)
		{
			if(tempA->value)
				tempA->value -= 1;
			temp = r1->value + 10000;
			diff = temp - r2->value;
		}
	}
	if( this->LESSTHAN( Q ) )					//IF THIS VALUE SMALLER THAN PARAMETER
	{											//WE GOTTA SPICE THINGS UP A BIT
		if(r1->value > r2->value)
		{
			if(tempB->value)
				tempB->value -= 1;
			temp = r2->value + 10000;
			diff = temp - r1->value;
		}
		if(r1->value < r2->value)
			diff = r2->value - r1->value;
	}
	
	result.x.INSERT_LEFT(diff);					//INSERT DIFFERENCE & REPEAT
	
	while( !a.IS_FIRST(r1) && !b.IS_FIRST(r2) )
	{
		r1 = a.NEXT_LEFT(r1);
		r2 = a.NEXT_LEFT(r2);
		tempA = a.NEXT_LEFT(r1);
		tempB = b.NEXT_LEFT(r2);
		
		if( this->GREATERTHAN( Q ) )			//IF THIS VALUE GREATER THAN PARAMETER
		{
			if(r1->value >= r2->value)
			{
				diff = r1->value - r2->value;
				if(diff == 0)	//*Normally, when subtracting negative numbers the first node would spaze out and repeatedly print itself*
					continue;	//*This may seem like a BS way to get the function to work...but it works, so ya know.*
			}
			if(r1->value < r2->value)
			{
				if(tempA->value)
					tempA->value -= 1;
				r1->value += 10000;
				diff = r1->value - r2->value;
				overflow = OVER_FLOW(diff);
			}
		}
		if(this->LESSTHAN( Q ))				//IF THIS VALUE SMALLER THAN PARAMETER
		{
			if(r1->value > r2->value)
			{
				if(tempB->value)
					tempB->value -= 1;
				r2->value += 10000;
				diff = r2->value - r1->value;
				overflow = OVER_FLOW(diff);
			}
			if(r1->value <= r2->value)
			{
				diff = r2->value - r1->value;
				if(diff == 0)	//*Same shit here*
					continue;
			}
		}
		result.x.INSERT_LEFT(diff);
	}
	
	//IF THIS VALUE IS LONGER THAN PARAMETER, WE CAN AUTOMATICALLY ASSUME THE REMAINING NODES WILL FILL THE FRONT
	//ALSO, WHICHEVER HAS THE GREATEST DIGITS WILL DEFINITELY DETERMINE THE SIGN
	if( this->GETDIGITCOUNT() > Q.GETDIGITCOUNT() )
	{
		while(!a.IS_FIRST(r1))
		{	
			r1 = a.NEXT_LEFT(r1);
			result.x.INSERT_LEFT(r1->value);
		}
		result.sign='+';
	}
	
	//IF PARAMETER LONGER THAN THIS VALUE
	if( this->GETDIGITCOUNT() < Q.GETDIGITCOUNT() )
	{
		while(!b.IS_FIRST(r2))
		{	
			r2 = b.NEXT_LEFT(r2);
			result.x.INSERT_LEFT(r2->value);
		}
		result.sign='-';
	}
	
	return result;
}

longInt longInt::MULTIPLY( longInt Q )
{
	longInt result;						//STORING RESULT HERE
	node* r1, *r2, *t; 					//NODES
	int padding = 0;						//PADDING
	int paddingSPACE = 0000;					//paddingSPACE IS INSERTED padding TIMES FOR ADEQUATE PADDING

	LIST a = this->x;					//THIS longInt
	LIST b = Q.x;						//PARAMETER

	longInt temp;	//temp1				//TEMPORARY PROD
	longInt temple;	//temp2				//CUMULATIVE PROD
	
	int prod, overlord, master;
	
	
	
	r1 = a.GET_LAST(); 	//THIS
	r2 = b.GET_LAST();	//Q
	
	//MULTIPLY
	prod = r1->value * r2->value;
	overlord = OVER_FLOW(prod);
	master = overlord; 
	
	//INSERT
	temp.x.INSERT_LEFT(prod);

	/**--------------ONLY ONE NODE EACH--------------**/
	if( a.IS_FIRST(r1) && b.IS_FIRST(r2) )
	{
		temp.x.INSERT_LEFT(master);
		return temp;
	}
	/**--------------ONLY ONE NODE EACH--------------**/
	
	while( !b.IS_FIRST(r2) )
	{
		r2 = b.NEXT_LEFT(r2);
		if(OVER_FLOW(r2->value))
		{
			if(r2->value>1000)
				prod = r1->value * (r2->value+1);
			else
				prod = r1->value * (r2->value);
			t = b.NEXT_LEFT(r2);
			t->value++;
		}
		else
			prod = r1->value * r2->value;
		overlord = OVER_FLOW(prod);
		prod = master+prod;
		if(prod>9999)
		{
			master += OVER_FLOW(prod)+1;
			temp.x.INSERT_LEFT(prod);
			master = overlord+1;
		}
		else
		{
			temp.x.INSERT_LEFT(prod);
			master = overlord;
		}
	}
	temp.x.INSERT_LEFT(master);
	
	temple = temp;
	temp.x.EMPTY();
	
	while( !a.IS_FIRST(r1) )
	{
		r1 = a.NEXT_LEFT(r1);
		r2 = b.GET_LAST();
		padding++;
		for(int i=0 ; i<padding ; i++)
			temp.x.INSERT_LEFT(paddingSPACE);
		prod = r1->value * r2->value;			//HERE!!
		overlord = OVER_FLOW(prod);
		master = overlord; 
		temp.x.INSERT_LEFT(prod);
		while( !b.IS_FIRST(r2) )
		{
			r2 = b.NEXT_LEFT(r2);
			if(OVER_FLOW(r2->value))
			{
				if(r2->value>1000)
					prod = r1->value * (r2->value+1);
				else
					prod = r1->value * (r2->value);
				t = b.NEXT_LEFT(r2);
				t->value++;
			}
			else
				prod = r1->value * r2->value;
			overlord = OVER_FLOW(prod);
			prod = master+prod; 
			temp.x.INSERT_LEFT(prod);
			master = overlord;
		}
		temp.x.INSERT_LEFT(master);
		temple = temple.ADD(temp);
		temp.x.EMPTY();
	}
	result = temple;
		
	
	if(this->sign == Q.sign)
		result.sign = '+';
	else
		result.sign = '-';
	
	r1 = result.x.GET_FIRST();	
	if ( r1->value == 0 )
		result.x.REMOVE_FIRST();
		
	return result;
}

longInt longInt::DIVIDE( longInt Q )
{
	//THIS divided by Q
	longInt result, temp, remainder, anotherTM;
	int q, r, d1, d2,blah;
	node* r1, *r2, *rt; 
	bool stat = true;
	LIST a = this->x;
	LIST b = Q.x;
		
	if( this->LESSTHAN( Q ) )				//IF THIS IS LESS THAN WHAT WE ARE DIVIDING BY, WE GET FRACTIONS < 1
	{
		result.x.INSERT_RIGHT(0);			//SO IF YOU LIKE IT, PUT A ZERO ON IT
		return result;
	}
		
	if( this->EQUALTO( Q ) )				//IF IT'S THE SAME longInt, RETURN NEO (THE ONE)
	{
		result.x.INSERT_RIGHT(1);
		return result;
	}

	r1 = a.GET_FIRST(); 	//THIS
	r2 = b.GET_FIRST();		//Q
	
	d1 = r1->value;			//THIS
	d2 = r2->value;			//Q
	
	/* KEEP THIS */
	if(d1 < d2)					//IF THIS FIRST NODE LESS THEN Q's FIRST NODE, BRING IN ANOTHER DIGIT
	{
		rt = a.NEXT_RIGHT( r1 );
		d1 = (d1*10000)+rt->value;
	}

	q = d1 / d2;				//FIND HIGHEST DIGIT
	result.x.INSERT_RIGHT( q );	//USING THIS TO MULTIPLY Q, TO PERFORM REMAINDER SEARCH
	temp.x.INSERT_RIGHT( q );	//USING THIS TO MULTIPLY Q, TO PERFORM REMAINDER SEARCH
	temp = Q.MULTIPLY( temp );
	
	
	//TODO: INSERT PADDING ON THE RIGHT OF temp
	blah = (this->GETDIGITCOUNT()) - (temp.GETDIGITCOUNT());
	blah /= 4;
	for(int i=0; i<blah ; i++)
		temp.x.INSERT_RIGHT(0000);
	
	remainder = this->SUBTRACT(temp);
	temp.x.EMPTY();

	while( stat )
	{
		r1 = remainder.x.GET_FIRST(); 	//THIS
	
		d1 = r1->value;			//THIS
	
		if(d1 < d2)					//IF THIS FIRST NODE LESS THEN Q's FIRST NODE, BRING IN ANOTHER DIGIT
		{
			rt = remainder.x.NEXT_RIGHT( r1 );
			d1 = (d1*10000)+rt->value;
		}
	
		q = d1 / d2;				//FIND HIGHEST DIGIT
		result.x.INSERT_RIGHT( q );	//USING THIS TO MULTIPLY Q, TO PERFORM REMAINDER SEARCH
		temp.x.INSERT_RIGHT( q );	//USING THIS TO MULTIPLY Q, TO PERFORM REMAINDER SEARCH
		temp = Q.MULTIPLY( temp );
		
		blah = (remainder.GETDIGITCOUNT()) - (temp.GETDIGITCOUNT());
		blah /= 4;
		for(int i=0; i<blah ; i++)
			temp.x.INSERT_RIGHT(0000);
		
		if(remainder.GETSIGN() == '-')
			remainder.SETSIGN('+');
		remainder = remainder.SUBTRACT(temp);
		
		temp.x.EMPTY();
		
		if( (result.GETDIGITCOUNT()+Q.GETDIGITCOUNT()) == this->GETDIGITCOUNT())
			stat = false;
	}
	return result;
}

longInt longInt::POWER ( int p )
{
	longInt result;
	int n = 1;	//POWER OF 2
	int counter = 1;
	int tempval;
	bool flag = true;
	
	switch(p)
	{
		case 0:			//IF EXPONENT IS 0, WE GET 0
			result.x.INSERT_LEFT(0);
			break;
		case 1:			//IF EXPONENT IS 1, WE GET BASE
			result = *this;
			break;
		case 2:			//IF EXPONENT IS 2, WE GET BASE**2
			result = this->MULTIPLY( *this );
			break;
		default:		//WHERE THE MAGIC HAPPENS...
			while( flag )		//WE'RE ASSUMING THE EXPONENT IS >2, HERE'S HOW WE FIND IT
			{
				if ( pow(2,n) <= p )		//IF 2^n IS STILL LESS THAN p, KEEP LOOKING FOR n
					n++;
				else
					flag = false;			//EXIT LOOP
			}
			//CHANCES ARE, WE OVERSHOT OUR EXPONENT FOR POWERS OF 2, IF WE DIDN'T, NOTHING TO WORRY ABOUT
			if( pow(2,n) > p)
			{
				n--;
				tempval = pow(2,n);
				tempval = p-tempval;
			}
			
			result = this->MULTIPLY( *this );	//this^2
			while ( counter < n )				
			{
				result = result.MULTIPLY( result );		//this^(2*counter)
				counter*=2;
			}
			//EXAMPLE this^10
			//this^2 -> this^4 -> this^8
			//SINCE OUR POWER OF 2 WAS SMALLER THAN THE EXPONENT, WE NEED FUTHER CALCULATIONS
			while(tempval > 0)
			{
				result = this->MULTIPLY( result );
				tempval--;
			}
	}

	return result;
		
}