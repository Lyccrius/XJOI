#include<bits/stdc++.h>
using namespace std;

struct node
{
	int x=-1,y=-1;
	int c=-1;//红1黑2
	int step=0;
}r1,r2,b1;
int mapp[20][20];//红1黑2空0障碍-1
int id,T;
int n,m;
char ch;
int dx[4]={1,-1,0,0};
int dy[4]={0,0,-1,1};//下上左右
int step=0;

void init()
{
	for(int i=0;i<20;i++)
	{
		for(int j=0;j<20;j++)
		{
			mapp[20][20]=-1;
		}
	}

	r1=r2=b1={-1,-1,-1};

	step=0;

	return;
}
void add(char ch,int x,int y)
{
	if(ch=='O')
	{
		if(r1.x!=-1)
		{
			r2.x=x;
			r2.y=y;
			r2.c=1;
		}
		else
		{
			r1.x=x;
			r1.y=y;
			r1.c=1;
		}
		mapp[x][y]=1;
	}

	else if(ch=='X')
	{
		b1.x=x;
		b1.y=y;
		b1.c=mapp[x][y]=2;
	}

	else if(ch=='.')
	{
		mapp[x][y]=0;
	}

	else if(ch=='#')
	{
		mapp[x][y]=-1;
	}

	return;
}
bool dangerous(int x,int y,int c)
{
	for(int k=0;k<4;k++)
	{
		int xx=x+dx[k],yy=y+dy[k];
		if(mapp[xx][yy]==1 && c==2) return true;
		if(mapp[xx][yy]==2 && c==1) return true;
	}
	return false;
}
int check(node t)//1红胜走1步，0黑胜不用走，-1无输赢
{
	int flag=-1;
	if(t.c==1)
	{
		int x=t.x,y=t.y;
		for(int k=0;k<4;k++)
		{
			if(mapp[x+dx[k]][y+dy[k]]==0)
			{
				flag=0;
				break;
			}
			else if(mapp[x+dx[k]][y+dy[k]]==2)
			{
				return 1;
			}
		}
		if(flag==0) return -1;
		else if(flag==-1) return 0;
	}

	else if(t.c==2)
	{
		int x=t.x,y=t.y;
		for(int k=0;k<3;k++)
		{
			if(mapp[x+dx[k]][y+dy[k]]==0)
			{
				flag=0;
				break;
			}
			else if(mapp[x+dx[k]][y+dy[k]]==1)
			{
				return 1;
			}
		}
		if(flag==0) return -1;
		else if(flag==-1) return 1;
	}
	return -1;
}
void bfs()
{
	bool flag1=0,flagg1=0;
	bool flag2=0,flagg2=0;
	bool flag3=0,flagg3=0;
	queue<node> q1,q2,q3;
	q1.push(r1);
	q2.push(r2);
	q3.push(b1);
	while(q1.empty() && q2.empty() && q3.empty() && q1.front().step<=n*m && q2.front().step<=n*m && q3.front().step<=n*m)
	{
		if(q3.front().x==1)
		{
			cout<<"Black "<<q3.front().step+q2.front().step+q1.front().step<<endl;
			return;
		}
		int x1=q1.front().x,stepp1=q1.front().step;
		int x2=q2.front().x,stepp2=q2.front().step;
		int x3=q3.front().x,stepp3=q3.front().step;
		q1.pop();
		q2.pop();
		q3.pop();
		for(int k=0;k<2;k++)
		{
			int xx1=x1+dx[k];
			int xx2=x2+dx[k];
			if(mapp[xx1][1]==0)
			{
				flag1=1;
				if(!dangerous(xx1,1,2))
				{
					flagg1=1;
					q1.push({xx1,1,1,stepp1+1});
				}
			}
			if(mapp[xx2][1]==0)
			{
				flag2=1;
				if(!dangerous(xx2,1,2))
				{
					flagg2=1;
					q2.push({xx2,1,1,stepp2+1});
				}
			}
		}
		if(flag1 && !flagg1)
		{
			if((flag2 && !flagg2) || !flag2)
			{
				cout<<"Black "<<q3.front().step+q2.front().step+q1.front().step+2<<endl;
				return;
			}
		}
		int xx3=x3+dx[2];
		if(mapp[xx3][1]==0)
		{
			flag3=1;
			if(!dangerous(xx3,1,2))
			{
				flagg3=1;
				q3.push({xx3,1,1,stepp3+1});
			}
		}
		if(flag3 && !flagg3)
		{
			cout<<"Red "<<q3.front().step+q2.front().step+q1.front().step+2<<endl;
			return;
		}
	}
	cout<<"Tie"<<endl;
	return;
}
void fun1()
{
	if(check(r1)==0 || check(r2)==0 || check(b1)==0)
	{
		cout<<"Black 0"<<endl;
		return;
	}
	if(check(r1)==1 || check(r2)==1 || check(b1)==1)
	{
		cout<<"Red 1"<<endl;
		return;
	}
	cout<<"Tie"<<endl;
	return;
}

int main()
{
	freopen("zu.in","r",stdin);
	freopen("zu.out","w",stdout);
	
	cin>>id>>T;
	while(T--)
	{
		init();
		cin>>n>>m;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				cin>>ch;
				add(ch,i,j);
			}
		}
		//if(7<=id && id<=9)
		//{
		//	bfs();
		//}
		//else
		//{
			fun1();
		//}
	}

	cout<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
