#include<bits/stdc++.h>
using namespace std;
int n[11000],m[11000],q[11000],t;
struct a{
	int x1;
	int k;
	int c;
}b[999999];
int ans[10950][10050];
int main(){
	freopen("paint.in","r",stdin);
	freopen("paint.out","w",stdout);
	cin>>t;
	for(int h=0;h<t;h++)
	{
		memset(ans,0,sizeof(ans));
		cin>>n[h]>>m[h]>>q[h];
		for(int i=1;i<=q[h];i++)
		{
			cin>>b[i].k>>b[i].x1>>b[i].c;	
		}
		for(int i=1;i<=q[h];i++)
		{	
			if(b[i].k==0)
			{		
				for(int j=1;j<=m[h];j++)
				{
					ans[b[i].x1][j]=b[i].c;
				}
			}
			if(b[i].k==1)
			{
				for(int j=1;j<=n[h];j++)
				{
					ans[j][b[i].x1]=b[i].c;
				}
			}
		}
		cout<<endl;
		for(int i=1;i<=n[h];i++)
		{
			for(int j=1;j<=m[h];j++)
			{
				cout<<ans[i][j]<<" ";
			}
			cout<<endl;
		}
	}
	return 0;
}
