#include <bits/stdc++.h>
using namespace std;//在这些字符中：'.'表示空位；'#'表示障碍物；
//'X'表示黑棋；'O'表示红棋。保证黑棋恰好有一个，红棋恰好有两个，且黑棋不在第一行。
//红方先走，黑方后走
int mp[15][15];char  dat[15][15];
int rdx1,rdx2,rdy1,rdy2,r;
int blx,bly;
int id,t;
int n,m;
int sm;

bool blk_could=1;
bool red_could1=1;
bool red_could2=1;

bool could_move(int x,int y)
{
	
	if((mp[y][x+1]==1||x==m)&&(mp[y][x-1]==1||x==1)&&(mp[y+1][x]==1||y==n)&&(mp[y-1][x]==1||y==1))
	{	
		return 0;
	}
	return 1;
	}
void f(int bx,int by,int rx1,int ry1,int rx2,int ry2)
{
	if(by==1) cout<<"BLACK"<<sm;
	
	if(!could_move(bx,by)) 
		blk_could=0;
	if(!could_move(rx1,ry1)) 
		red_could1=0;
	if(!could_move(rx2,ry2)) 
		red_could2=0;
	if(!blk_could) {cout<<"Red"<<0;}
	if(!red_could1&&!red_could2) {cout<<"Black"<<0;}
	if(blk_could&&red_could1&&red_could2) cout<<"Tie";
}
int main()
{
	freopen("zu.in","r",stdin);
	freopen("zu.out","w",stdout);
	cin>>id>>t;
	while(t--){
		cin>>n>>m;
		for(int i=0;i<n;++i)
			cin>>dat[i];
		for(int i=0;i<n;++i)
			for(int j=0;j<m;++j)
		{
			char da;
			da=dat[i][j];
			if(da=='.') mp[i+1][j+1]=0;
			else if(da=='#') mp[i+1][j+1]=1;
			else if(da=='O') mp[i+1][j+1]=2;
			//RED
		    else if(da=='X') mp[i+1][j+1]=3;
			//BLACK
		}
		for(int i=1;i<=n;++i){
			for(int j=1;j<=m;++j){
				if(mp[i][j]==2)
				{
					if(!r)
					{
						rdx1=j;rdy1=i;
						r=1;
					}
					else
					{
						rdx2=j;rdy2=i;
						}
				}
				if(mp[i][j]==3)
				{
					blx=j;
					bly=i;	
				}
		}
		}
	}
	f(blx,bly,rdx1,rdy1,rdx2,rdy2);
	return 0;
}
