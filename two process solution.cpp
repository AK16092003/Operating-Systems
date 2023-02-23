#include<iostream>
using namespace std;

// Two process solution
// only mutually exclusive is satisfied
int i = 0 , j = 1;
int turn = 1;

void Pi()
{
	while(turn == j);	// wait
	
	// CRITICAL SECTION
	
	turn = j;
	
	// REMAINDER SECTION
}
void Pj()
{
	while(turn == i);	// wait
	
	// CRITICAL SECTION
	
	turn = i;
	
	// REMAINDER SECTION
}

int main()
{
	Pi();
	Pj();	
	return 0;
}
