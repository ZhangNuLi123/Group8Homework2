#include <iostream>
#include <ctime>
using namespace std;

int CheckNumber(char [], int );               //检查输入位置信息是否合法
void Change(char [], int , int );             //下棋改变棋盘
void Print(char []);                          //展示棋盘实现低级交互
int CheckStatus(char []);                     //检验游戏是否结束

int main()
{   
    srand((unsigned int)time(0));              //电脑下棋随机数代码
	
	int player=0;                              //记录下棋者
	int number=0;                              //记录下棋位置
	char chess[10]="123456789";                //初始化棋盘
    int winner=0;     

	cout<<"棋盘如下"<<endl;                           
	print(chess);
	                          //状态参数
	cout<<"请设置谁先手"<<endl;
	cout<<"1--玩家执O		2--电脑执X"<<endl;
	
	cin>>player;                                       //设置先手
	while（player!=1&&player!=2）                      //先手合法性判断
	{
		cout << "请输入合法玩家编号" << endl;
	cin >> player;
	}
    
	int state=0;                                //设置下棋个数，当棋盘棋子达到了9，且未结束时判断为平局
	for(player;winner==0;player++)
	{   
		number=0;
   	    if(player==3)                           //判断player是否溢出
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
			Print(chess);
           
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
			Print(chess);
			
			if(CheckStatus(chess)==1)		
			{
				cout<<"电脑获得胜利"<<endl;   
			    winner=1;
			};
		}
		state++;
		if(state==9) 
		{
			cout<<"平局"<<endl;
			winner=1;
		};

	}

	cout<<"游戏结束"<<endl;
	return 0;
}


int CheckNumber(char chess[], int num)             //函数定义，数组传参
{
	if (num<1||num>9)
		return 0;
	else if (chess[num-1]=='O'||chess[num-1]=='X')
		return 0;
	else 
		return 1;
}

void Change(char chess[], int num, int player)     //函数定义，传输参数
{   
	if (player==1)		
		chess[num-1]='O';               //根据下棋者更改棋盘
	else		        
		chess[num-1]='X';               //根据下棋者更改棋盘
}

void Print(char chess[])                 //展示棋盘
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

int CheckStatus(char chess[10])           //检查是否成功
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