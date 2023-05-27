#include<bits/stdc++.h>
using namespace std;
struct point {
	int x,y;
}h1,h2,b1;
int T,n,m,used[15][15],dir[4][2]={{0,1},{1,0},{0,-1},{-1,0}},f,fl,id;
char t[15];
int main()
{
	freopen("zu.in","r",stdin);
	freopen("zu.out","w",stdout);
	cin>>id>>T;
	while(T--)
	{
		cin>>n>>m;
		memset(used,-1,sizeof(used));
		f=0;
		for(int j=1;j<=n;j++)
		{
			cin>>t;
			for(int i=0;i<m;i++)
			{
				if(t[i]=='.') used[j][i+1]=0;
				if(t[i]=='X') used[j][i+1]=1,b1.x=j,b1.y=i+1;
				if(t[i]=='O')
				{
					if(f) 
					{
						h2.x=j;
						h2.y=i+1;
					}
					else 
					{
						h1.x=j;
						h1.y=i+1;
						f=1;
					}
				}
 			}
		}
		if(id>=1&&id<=4)
		{
			int i;
			for(i=0;i<=3;i++)
			{
				if(used[h1.x+dir[i][0]][h1.y+dir[i][1]]==0||used[h2.x+dir[i][0]][h2.y+dir[i][1]]==0) break;
				if(used[h1.x+dir[i][0]][h1.y+dir[i][1]]==1||used[h2.x+dir[i][0]][h2.y+dir[i][1]]==1)
				{
					cout<<"Red "<<1<<endl;
					fl=1;
				}
			}
			if(i>3) cout<<"Black "<<0<<endl;
			else if(!fl) cout<<"Tie";
		}
		if(id==5||id==6)
		{
			//cout<<b1.x<<" "<<h1.x<<" "<<h1.y<<" "<<b1.y<<endl;
			//cout<<b1.x-h1.x<<" "<<abs(h1.y-b1.y)+1<<endl;
			if(b1.x-h1.x<abs(h1.y-b1.y)-1) cout<<"Black "<<b1.x*2-2<<endl;
			else if(h1.x!=b1.x-1||abs(h1.y-b1.y)!=1) cout<<"Red "<<(b1.x-h1.x)*2+(b1.y>h1.y? (m-b1.y)*2:b1.y*2-2)-1;
			else cout<<"Red "<<(b1.x-h1.x)*2+(b1.y>h1.y? (m-b1.y)*2:b1.y*2-2)+1;
		}
	}
	return 0;
}
