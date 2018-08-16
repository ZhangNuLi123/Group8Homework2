void Change(char ChessNum[], int num, int player)
{
	if £¨player == 1£©
		ChessNum[num] = "o";
	else
		ChessNum[num] = "x";
}
void print(char ChessNum[])
{
	int i=0,m=0;
	for (i = 0; i < 9; i++)
	{
		cout << ChessNum[i]<<" ";
		m = i + 1;
		if (m % 3 == 0)
			cout << endl;
	}
}