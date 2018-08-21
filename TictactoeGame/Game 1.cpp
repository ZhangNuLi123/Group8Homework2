#include <iostream>
#include <ctime>
using namespace std;

int CheckNumber(char [], int );               //�������λ����Ϣ�Ƿ�Ϸ�
void Change(char [], int , int );             //����ı�����
void Print(char []);                          //չʾ����ʵ�ֵͼ�����
int CheckStatus(char []);                     //������Ϸ�Ƿ����

int main()
{   
    srand((unsigned int)time(0));              //�����������������
	
	int player=0;                              //��¼������
	int number=0;                              //��¼����λ��
	char chess[10]="123456789";                //��ʼ������
    int winner=0;     

	cout<<"��������"<<endl;                           
	print(chess);
	                          //״̬����
	cout<<"������˭����"<<endl;
	cout<<"1--���ִO		2--����ִX"<<endl;
	
	cin>>player;                                       //��������
	while��player!=1&&player!=2��                      //���ֺϷ����ж�
	{
		cout << "������Ϸ���ұ��" << endl;
	cin >> player;
	}
    
	int state=0;                                //����������������������Ӵﵽ��9����δ����ʱ�ж�Ϊƽ��
	for(player;winner==0;player++)
	{   
		number=0;
   	    if(player==3)                           //�ж�player�Ƿ����
			player=player-2;

        if(player==1)                            
		{   
			cout<<"��������"<<endl;
		    cin>>number;

			while(CheckNumber(chess,number)==0)
			{
			cout<<"����������"<<endl;
		    cin>>number;
			};
 
		    Change(chess, number, player);    
			Print(chess);
           
			if(CheckStatus(chess)==1)		
			{
				cout<<"�����ʤ��"<<endl;   
				winner=1;
			}
			;
		}

        if(player==2)
		{
			cout<<"��������"<<endl;
			number=(rand()%10);

			while(CheckNumber(chess,number)==0)
			{
			number=(rand()%10);
			};
			
			Change(chess, number, player);
			Print(chess);
			
			if(CheckStatus(chess)==1)		
			{
				cout<<"���Ի��ʤ��"<<endl;   
			    winner=1;
			};
		}
		state++;
		if(state==9) 
		{
			cout<<"ƽ��"<<endl;
			winner=1;
		};

	}

	cout<<"��Ϸ����"<<endl;
	return 0;
}


int CheckNumber(char chess[], int num)             //�������壬���鴫��
{
	if (num<1||num>9)
		return 0;
	else if (chess[num-1]=='O'||chess[num-1]=='X')
		return 0;
	else 
		return 1;
}

void Change(char chess[], int num, int player)     //�������壬�������
{   
	if (player==1)		
		chess[num-1]='O';               //���������߸�������
	else		        
		chess[num-1]='X';               //���������߸�������
}

void Print(char chess[])                 //չʾ����
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

int CheckStatus(char chess[10])           //����Ƿ�ɹ�
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