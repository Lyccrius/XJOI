#include <bits/stdc++.h>
using namespace std;
int id,T,n,m;
int fx[4]={0,0,1,-1};
int fy[4]={1,-1,0,0};
char a;
int mapp[15][15];
int x1,x2;
int z1,z2;
int now1,now2;
char maw[15][15];
int mina;
bool pdren(int a,int b,int c,int d)
{
	for(int i=0;i<4;i++)
	{
		if(a+fx[i]>0&&b+fy[i]>0&&a+fx[i]<=m&&b+fy[i]<=n&&mapp[a+fx[i]][b+fy[i]]!=-1)
		return 0;
	}
	cout <<"Black 0"<<endl;
	return 1;
}
void solve1()
{

	if(pdren(x1,x2,z1,z2)==1)
	return;
	cout <<"Tie"<<endl;
	return;
}
void minab()
{
	mina=0;
	if((abs(now2-z1)+abs(now1-x1))%2!=1)
	{
	mina=abs(z1-now2)+abs(now1-x1);
	}
	else if((abs(now2-z1)+abs(now1-x1))%2==1)
	{
	mina=1000005;
	}
	return;
}

void check()
{
	if(z1<now2)
	{
		if(now2-z1%2==0)
		cout <<"Red "<<now2-z1;
		else
		{
		cout <<"Black "<<min(mina,now2-z1)-1;
		}
	}
	else
	cout <<"Black "<<min(mina,(now2-1)*2);	
	return;
}
void solve2()
{
	minab();
	if(m==1) 
	{
		check();
		return;
	}
	mina=min(mina,(now2-1)*2);
	if(z1<now2&&abs(now1-x1)<abs(now2-z1)+1)
	{
		cout <<"Tie";		
		return;
	}
	else
	cout <<"Black "<<mina;
	return;
}
void solve3()
{
	int u=0,v=0,t=1;
	if(mapp[z1+1][1]==-1&&mapp[z1-1][1]==-1&&mapp[z2+1][1]==-1&&mapp[z2-1][1]==-1)
	{
		cout <<"Black 0";
		return;
	}
	while(t!=n)
	{
	for(int i=t;i<=n;i++)
	{
		if(maw[i][1]=='O')
		u++;
		if(maw[i][1]=='X')
		v++;
		if(maw[i][1]=='#')
		{
			t=i+1;
			break;
		}
	}
	if(u==0&&v==1)
	{
		cout <<"Black "<<(now2-1)*2;
		return;
	}
	if(u==2&&v==1)
	{
	cout <<"Red "<<min(abs(now2-z1)+1,abs(now2-z2)+1);
	return;
	}
	if(u==1&&v==1)
	{
		if(now2>z1)
		{
		cout <<"Black " <<min(now2-1,abs(now2-z1));
		return;
		}
		else
		{
		cout <<"Red "<<abs(now2-z1);
		return;
		}
	}
	if(u==2&&v==0)
	{
		if((mapp[now2+1][1]!=-1||mapp[now2-1][1]!=-1)&&mapp[z1+1][1]!=-1&&mapp[z1-1][1]!=-1&&mapp[z2+1][1]!=-1&&mapp[z2-1][1]!=-1)
		{
			cout <<"Tie";
			return;
		}
		else if((mapp[z1+1][1]!=-1||mapp[z1-1][1]!=-1||mapp[z2+1][1]!=-1||mapp[z2-1][1]!=-1)&&mapp[now2+1][1]==-1&&mapp[now2-1][1]==-1)
		{
			cout <<"Red 0";
			return;
		}
		else
		{
			 cout <<"Black 0";
			 return;
		}
		}
	}
	return;
}

int main()
{
	freopen("zu.in","r",stdin);
	freopen("zu.out","w",stdout);
	cin >>id >>T>>n>>m;
	while(T!=0)
	{
		T--;
		memset(mapp,-1,sizeof(mapp));
		memset(maw,0,sizeof(maw));
		x1=0,x2=0,z1=0,z2=0,now1=0,now2=0;
		mina=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cin >>a;
			maw[i][j]=a;
			if(a=='.')
			mapp[i][j]=0;
			if(a=='#')
			mapp[i][j]=-1;
			if(a=='X')
			mapp[i][j]=-1,now1=j,now2=i;
			if(a=='O')
			{
			mapp[i][j]=-1;
			if(x1==0)
			x1=j,z1=i;
			else
			x2=j,z2=i;
			}
		}
	}
	if(id>=1&&id<=4)
	{
		solve1();
	}
	if(id>=5&&id<=6)
	{
		solve2();
	}
	if(id>=7)
	{
		solve3();
	}
	}
	return 0;
}
