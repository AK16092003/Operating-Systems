#include<iostream>
using namespace std;

#define BUFFER_SIZE 10

int buffer[BUFFER_SIZE];
int counter = 0;
int in = 0 , out = 0;

void producer(int next_produced)
{
	while(counter == BUFFER_SIZE);
	buffer[in] = next_produced;
	in = (in+1)%BUFFER_SIZE;
	counter++;
}


int consumer()
{
	while(counter == 0);
	int next_consumed = buffer[out];
	out = (out+1)%BUFFER_SIZE;
	counter--;
	return next_consumed;
}



int main()
{
	producer(10);
	cout << consumer() << endl;
	return 0;
}
