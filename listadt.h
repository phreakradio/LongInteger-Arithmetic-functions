/* FOR THE LOVE OF EVERYTHING THAT IS HOLY IN THIS WORLD, DO !NOT! CHANGE ANYTHING IN THIS FILE */

#include <string>
#include <iostream>

#ifndef listadt_H
#define listadt_H

using namespace std;

struct node
{
	int value;					//value that will be put in max(9999)/min(0000)
	node *prev;					//Prev node
	node *next;					//Next node
	node(int d, node* p, node* n) : value(d), prev(p), next(n) {}		//Helps with constructing
};

class LIST
{
	private:
		node *head;
		node *tail;
		
	public:
		LIST(){head=tail=NULL;}
		bool empty() const { return ( !head || !tail ); }	//Checking if the head or tail are empty. If so, there's no list

/************************************************FUNCTIONS************************************************/	
		//RETURNS THE RIGHTMOST NODE OF THE DOUBLY LINKED LIST
		node* GET_LAST()
		{	
			node *temp1 = head;
			node *temp2;
			if( empty() )
			{
				//cout << "LIST IS EMPTY, MATE" << endl;
				return NULL;						//LIST IS EMPTY, SO THERE IS NOTHING
			}
			while(temp1 != NULL)
			{				
				temp2 = temp1;
				temp1 = temp1->next;
			}
			return temp2;
		};
		
		//RETURNS THE LEFTMOST NODE OF THE DOUBLY LINKED LIST 
		node* GET_FIRST()
		{
			if ( empty() )
			{	
				//cout << "LIST IS EMPTY, MATE" << endl;
				return NULL;
			}
			return head;
		};
		
		//RETURNS NEXT NODE TO THE RIGHT OF THE NODE N
		node* NEXT_RIGHT(node*& N)
		{
			return N->next;
		};
		
		//RETURNS NEXT NODE TO THE LEFT OF THE NODE N
		node* NEXT_LEFT(node*& N)
		{
			return N->prev;
		};
		
		//VALUE V IS INSERTED AFTER THE RIGHTMOST NODE 
		void INSERT_RIGHT(int V)
		{
			tail = new node(V, tail, NULL);
			if( tail->prev )
			{
				tail->prev->next = tail;
				//cout<< "VALUE " << V << " INSERTED RIGHT. " << endl;
			}
			if( empty() )
			{
				//cout << "NEW LIST CREATED / VALUE: " << V << endl;
				head = tail;
			}
		};
		
		//VALUE V IS INSERTED AFTER THE LEFTMOST NODE
		void INSERT_LEFT(int V)
		{
			head = new node(V, NULL, head);
			if( head->next )
			{
				head->next->prev = head;
				//cout<< "VALUE " << V << " INSERTED LEFT. " << endl;
			}
			if( empty() )
			{
				//cout << "NEW LIST CREATED / VALUE: " << V << endl;
				tail = head;
			}
		};
		
		//DETERMINES IF THE GIVEN NODE IS THE LEFTMOST NODE
		bool IS_FIRST(node*& N)
		{
			if( empty() )
				return false;
			if(N->prev == NULL)
				return true;
			return false;			
		};
		
		//DETERMINES IF THE GIVEN NODE IS THE RIGHTMOST NODE
		bool IS_LAST(node*& N)
		{
			if( empty() )
				return false;
			if(N->next == NULL)
				return true;
				return false;
		};
/************************************************FUNCTIONS************************************************/
		void EMPTY()
		{
			head = tail = NULL;
			return;
		};
		
		void REMOVE_FIRST()
		{
			head = head->next;
		};
}; 		//END CLASS

#endif