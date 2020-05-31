#include <iostream>
#include <cstdio>

using namespace std;

/**
1 ~ 7 ������ ���� ī�尡 ���� �� , �̰��� ������ �� �ִ� ����� ����
����϶�
*/
int arr[7] = {1,2,3,4,5,6,7};

void swap(int index1, int index2)
{
	int temp = arr[index1];
	arr[index1] = arr[index2];
	arr[index2] = temp;
}

void numArr(int arrSize)
{
	if(arrSize == 1)
	{
		for(int i = 0; i < 7; i++)
		{
			printf("%d" ,arr[i]);
		}
		printf("\n");
		return;
	}
	for(int i = 0; i < arrSize; i++)
	{
		swap(i, arrSize-1);
		numArr(arrSize-1);
		swap(i, arrSize-1);
	}
}

int main()
{
	numArr(7);	
	return 0;
}
