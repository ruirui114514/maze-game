#include<bits/stdc++.h>
#include <windows.h>
#include <conio.h>

using namespace std;
char a[25][260];
int x=1,y=100,x2,y2;

void show()
{
	for(int i=1;i<=10;i++)
	{
		for(int j=1;j<=180;j++)
		{
			if(i==x&&j==y)
			{
				cout<<"N";
				continue;
			}
			cout<<a[i][j];
		}
		cout<<endl;
	}
	return;
}

bool game()
{
	int type=1;
	char k;
	x=1;y=100;
	show();
	while(type==1)
	{
		k=getch();
		if(k=='w') x--;
		if(k=='s') x++;
		if(k=='a') y--;
		if(k=='d') y++;
		y=min(255,y);
		y=max(1,y);
		x=min(10,x);
		x=max(1,x);
		system("cls");
		if(a[x][y]=='*') return false;
		if(a[x][y]=='M') return true;
		show();
		Sleep(250);
	}
}

void setmap()
{
	srand(time(0));
	do
	{
		x2=(rand()%(10-1+1))+1;
		y2=(rand()%(180-1+1))+1;
	}while(x2==x||y2==y);
	for(int i=1;i<=20;i++)
	{
		for(int j=1;j<=180;j++)
		{
			if(rand()%101>=95&&(i!=x||j!=y))
			{
				a[i][j]='*';
				continue;
			}
			a[i][j]=' ';
		}
	}
	a[x2][y2]='M';
	return;
}

int main()
{
	char type;
	long long start,end;
	bool win;
	cout<<"Please maximize the window.\n";
	system("pause");
	do
	{
		system("cls");
		start=time(0);
		setmap();
		win=game();
		end=time(0);
		if(win==false)
		{
			cout<<"You are loss! You lasted "<<end-start<<" Seconds. Continue?(y/n)";
		}
		if(win==true)
		{
			cout<<"You are win! You used "<<end-start<<" Seconds. Continue?(y/n)";
		}
		cin>>type;
	}while(type=='y');
	system("pause");
	return 0;
}
