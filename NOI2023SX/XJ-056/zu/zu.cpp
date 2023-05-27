#include<bits/stdc++.h>
using namespace std;
int a[15][15];
long long suos;
int n,m;
struct node
{
	int x;
	int y;
	int step;
}black[100000],red[2][100000];
int bdx[3]={-1,0,0},bdy[3]={0,-1,+1};
int rdx[4]={-1,+1,0,0},rdy[4]={0,0,-1,+1};
long long total;
bool judge(int x,int y,int r1h,int r2h)
{
	for(int i=0;i<4;i++)
	{
		int rtx1,rty1;
		int rtx2,rty2;
		rtx1=red[0][r1h].x+rdx[i];
		rty1=red[0][r1h].y+rdy[i];
		rtx2=red[1][r2h].x+rdx[i];
		rty2=red[1][r2h].x+rdy[i];
		if((rtx1==x&&rty1==y)||(rtx2==x&&rty2==y))
			return false;
	}
	return true;
}
bool judge1(int x,int y,int bx,int by)
{
	for(int i=0;i<4;i++)
	{
		int rtx,rty;
		rtx=x+rdx[i];
		rty=y+rdy[i];
		if(rtx==bx&&rty==by)
			return true;
	}
	return false;
}
int main()
{
	freopen("zu.in","r",stdin);
	freopen("zu.out","w",stdout);
	int id,T;
	cin>>id>>T;
	while(T--)
	{
		for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			a[i][j]=0;
		suos=0;
		for(int i=0;i<100000;i++)
		{
			black[i].x=red[0][i].x=red[1][i].x=0;
			black[i].y=red[0][i].y=red[1][i].y=0;
			black[i].step=red[0][i].step=red[1][i].step=0;
		}
		int t=0;
		
		cin>>n>>m;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				char b;
				cin>>b;
				if(b=='#')
					a[i][j]=3;//means 障碍物
				else
				if(b=='X')
				{
					a[i][j]=1;//means 黑棋
					black[1].x=i;
					black[1].y=j;
					black[1].step=0;
				}	
				else
				if(b=='O')
				{
					a[i][j]=2;//means 红棋
					red[t][1].x=i;
					red[t][1].y=j;
					red[t][1].step=0;
					t++;
				}	
			}
		}
		
		int r1head=1,r2head=1,r1tail=1,r2tail=1;
		
		for(int i=0;i<4;i++)
		{
			int rtx1,rty1,rtx2,rty2;
			rtx1=red[0][r1head].x+rdx[i];
			rty1=red[0][r1head].y+rdy[i];
			rtx2=red[1][r2head].x+rdx[i];
			rty2=red[1][r2head].y+rdy[i];
			if((rtx1>=0&&rtx1<n)&&(rty1>=0&&rty1<m)&&a[rtx1][rty1]==0)
			{
				red[0][r1tail].x=rtx1;
				red[0][r1tail].y=rty1;
				red[0][r1tail].step=red[0][r1head].step+1;
				r1tail++;
			}
			if((rtx2>=0&&rtx2<n)&&(rty2>=0&&rty2<m)&&a[rtx2][rty2]==0)
			{
				red[1][r2tail].x=rtx2;
				red[1][r2tail].y=rty2;
				red[1][r2tail].step=red[1][r2head].step+1;
				r2tail++;
			}
		}
		if(r1head==r1tail&&r2head==r2tail)
			cout<<"Black"<<" "<<0<<endl;
		else
			cout<<"Tie"<<endl;
	}
	cout<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
