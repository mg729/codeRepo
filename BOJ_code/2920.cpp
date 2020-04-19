#include<iostream>
#include<cstdio>

using namespace std;

int main()
{
	int arr[8] = {};
	int size = sizeof(arr) / sizeof(arr[0]);
	
	for(int i = 0; i < size; ++i)
	{
		scanf("%d", &arr[i]);		
	}
	bool ascending = true;
	bool descending = true;
	for(int val = 1, i = 0; i < size-1; ++i, ++val)
	{
		if(arr[i] < arr[i+1])
	    	descending = false;
		else if(arr[i] > arr[i+1])
			ascending = false;
	}
	
	if(ascending)
		printf("ascending");
	else if(descending)
		printf("descending");
	else
		printf("mixed");
	
	return 0;
}

//Contest > Croatian Open Competition in Informatics > COCI 2009/2010 > Contest #1
