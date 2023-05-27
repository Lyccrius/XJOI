	#include<bits/stdc++.h>
	using namespace std;
	int mapp_a[20][20];
	int mapp_b[20][20];
	int needs,num;
	int x,mx;
	int used[100];
	int find(int now)
	{
		if(now==needs)
		{
			mx=max(mx,x);	
			return 0;
		}
		for(int i=1;i<=num;i++)
		{
			for(int j=1;j<=num;j++)
			{
				int a=mapp_a[now][i];
				int b=mapp_b[now][j];
	//			cout<<now<<" "<<i<<" "<<j<<" "<<a<<" "<<b<<endl;
				if(a&&b)
				{
					if(i==j)
					{
						x++;
					}
					else if(!used[j])
					{
						used[j]=1;
						find(now+1);
						used[j]=0;
						if(i==j)
						{
							x--;
						}
					}
				}
			}
		}
		return 0;
	}
	int main()
	{
		freopen("game.in","r",stdin);
		freopen("game.out","w",stdout);
		int  t;
		cin>>t;
		while(t--)
		{
			cin>>needs>>num;
			for(int i=1;i<=needs;i++)
			{
				int k;
				cin>>k;
				for(int j=1;j<=k;j++)
				{
					int n;
					cin>>n;
					mapp_a[i][n]=1;
				}
			}
			for(int i=1;i<=needs;i++)
			{
				int k;
				cin>>k;
				for(int j=1;j<=k;j++)
				{
					int n;
					cin>>n;
					mapp_b[i][n]=1;
				}
			}
			find(1);
			cout<<mx<<endl;
		}
		cout<<endl;
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
