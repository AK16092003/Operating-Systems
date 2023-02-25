#include<bits/stdc++.h>
#define MAX 10

using namespace std;

int matA[MAX][MAX];
int matB[MAX][MAX];
int matC[MAX][MAX];

int step_i = 0;

void *multiply(void *arg)
{
	int i = step_i++;
	
	for(int j = 0 ;j < MAX; j ++)
	{
		matC[i][j] = 0;
		
		for(int k = 0 ; k < MAX ; k ++)
		{
			matC[i][j] += matA[i][k]*matB[k][j];	
		}
	}
}


int main()
{
	cout << "Input Matrix A : " << endl;
	for(int i = 0; i < MAX; i ++)
	{
		for(int j = 0 ; j < MAX; j ++)
		{
			cin >> matA[i][j];
		}
	}
	
	cout << "Input Matrix B : " << endl;
	for(int i = 0; i < MAX; i ++)
	{
		for(int j = 0 ; j < MAX; j ++)
		{
			cin >> matB[i][j];
		}
	}
	
	pthread_t threads[MAX];
	
	for(int i = 0 ; i < MAX; i ++)
	{
		int *p;
		pthread_create(&threads[i] , NULL , multiply , (void *)(p));
	}
	
	for(int i = 0 ; i < MAX ; i ++)
	{
		pthread_join(threads[i] , NULL);
	}
	cout << "Matrix C" << endl;
	for(int i= 0 ; i  <MAX;i ++)
	{
		for(int j = 0 ; j < MAX ; j ++)
		{
			cout << matC[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}
