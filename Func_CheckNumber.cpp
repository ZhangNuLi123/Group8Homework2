#include<iostream>
using namespace std;
int main()
{
	char array[9];
	int i = 0;
	for (; i <= 8; i++)
	{
		array[i] = 'O';
	}
	int j = 0;
	for (; j <= 8; j++)
	{
		cout << ' ' << array[j];
		if ((j + 1) % 3 == 0)
			cout << '\n';
	}
}
int CheckNumber(char a[], int num)
{
	if (num < 1 || num>9)
		return 0;
	else if (a[num] == 'O' || a[num] == 'X')
		return 0;
	else if (a[num] == ' ')
		return 1;
	else
		return 0;
}
