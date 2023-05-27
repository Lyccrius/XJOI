#include<bits/stdc++.h>
using namespace std;
int door,worker,change;
int doors[110][110];
int cate[110][110];
int sum()
{
//	cout<<">";
	int maxxx=0;
	for(int i=1;i<=door;i++)
	{
		int maxx=0;
		for(int j=1;j<=doors[i][0];j++)
		{
			maxx=max(maxx,doors[i][j]);
		}
		maxxx+=maxx;
	}
	return maxxx;
}
int used[110];
int maxn;
int give(int now)
{
	if(!doors[now][0])
	{
		maxn=max(sum(),maxn);
	}
	for(int j=1;j<=door;j++)
	{
		if(cate[now][j])
		{
			for(int i=1;i<=doors[now][0];i++)
			{
				if(used[j]==0)
				{
		//			cout<<"!"<<j<<endl;
					used[j]=1;
					give(j);
			/*		doors[j][0]++;
					doors[j][doors[i][0]]=doors[now][i];
					for(int k=i;k<=doors[now][0];k++)
					{
						doors[j][k]=doors[j][k+1];
					}
					doors[now][0]--;
					give(j);
					for(int k=doors[now][0];k>=i;k--)
					{
						doors[j][k+1]=doors[j][k];
					}
					doors[now][0]++;
					doors[now][i]=doors[j][doors[j][0]];
					doors[j][doors[j][0]]=0;
					doors[j][0]--;*/
					used[j]=0;
				}	
			}	
		}
	}
	return 0;
}
int main()
{
	freopen("transfer.in","r",stdin);
	freopen("transfer.out","w",stdout);
	int sid;
	cin>>sid;
	cin>>door>>worker>>change;
	for(int i=2;i<=door;i++)
	{
		int temp;
		cin>>temp;
		cate[temp][i]=1;
	}
	for(int i=1;i<=worker;i++)
	{
		int place;
		cin>>place;
		doors[place][0]++;
		cin>>doors[place][doors[place][0]];
	}
	int maxxx=0;
	for(int i=1;i<=door;i++)
	{
		int maxx=0;
		for(int j=1;j<=doors[i][0];j++)
		{
			maxx=max(maxx,doors[i][j]);
//			cout<<doors[i][j]<<" ";
		}
		maxxx+=maxx;
//		cout<<endl;
	}
	cout<<maxxx<<endl;
//	give(1);
//	cout<<maxn;
	for(int i=1;i<=change;i++)
	{
		int c;
		cin>>c;
		switch(c)
		{
			case 1:
			{
				int x,y;
				cin>>x>>y;
				break;
			}
			case 2:
			{
				int n;
				cin>>n;
				break;
			}
		}
	}
	cout<<endl;
		fclose(stdin);
		fclose(stdout);
		
	return 0;
}
