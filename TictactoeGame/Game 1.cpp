#include <iostream>
#include <ctime>
using namespace std;

int CheckNumber(char [], int );
void Change(char [], int , int );
void print(char []);
int CheckStatus(char []);

int main()
{   
    srand((unsigned int)time(0));
	int player=0;
	int number=0;
	char chess[10]="123456789";
    cout<<"棋盘如下"<<endl;
	print(chess);
	int winner=0;
	cout<<"请设置谁先手"<<endl;
	cout<<"1--玩家执O		2--电脑执X"<<endl;
	cin>>player;
    int state=0;
	for( ;winner==0;player++)
	{   
		number=0;
   	    if(player==3) 
			player=player-2;

        if(player==1)
		{   
			cout<<"请您下棋"<<endl;
		    cin>>number;

			while(CheckNumber(chess,number)==0)
			{
			cout<<"请重新下棋"<<endl;
		    cin>>number;
			};
 
		    Change(chess, number, player);
			print(chess);
           
			if(CheckStatus(chess)==1)		
			{
				cout<<"您获得胜利"<<endl;   
				winner=1;
			}
			;
		}

        if(player==2)
		{
			cout<<"电脑下棋"<<endl;
			number=(rand()%10);

			while(CheckNumber(chess,number)==0)
			{
			number=(rand()%10);
			};
			Change(chess, number, player);
			print(chess);
			if(CheckStatus(chess)==1)		
			{
				cout<<"电脑获得胜利"<<endl;   
			    winner=1;
			};
		}
		state++;
		if(state==9) {cout<<"平局"<<endl;winner=1;};

	}

	cout<<"游戏结束"<<endl;
	return 0;
}




int CheckNumber(char chess[], int num)
{
	if (num<1||num>9)
		return 0;
	else if (chess[num-1]=='O'||chess[num-1]=='X')
		return 0;
	else 
		return 1;
}

void Change(char chess[], int num, int player)
{   
	if (player==1)		
		chess[num-1]='O';
	else		        
		chess[num-1]='X';
}

void print(char chess[])
{
	int i=0,m=0;
	for (i=0; i<9; i++)
	{
		cout<<chess[i]<<" ";
		m=i+1;
		if (m%3==0)
		   cout<<endl;
	}
}

int CheckStatus(char chess[10])
{
	int Status;
	if(chess[0]==chess[3]&&chess[3]==chess[6]||chess[1]==chess[4]&&chess[4]==chess[7]||chess[2]==chess[5]&&chess[5]==chess[8])
    Status=1;
	else if(chess[0]==chess[1]&&chess[1]==chess[2]||chess[3]==chess[4]&&chess[4]==chess[5]||chess[6]==chess[7]&&chess[7]==chess[8])
    Status=1;
    else if(chess[0]==chess[4]&&chess[4]==chess[8]||chess[2]==chess[4]&&chess[4]==chess[6])
    Status=1;
	else Status=0;
    return Status;
}