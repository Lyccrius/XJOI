#include<bits/stdc++.h>
using namespace std;
int main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	int t,k;
	cin>>t>>k;
	while(t--)
	{
		int coust[k];
		int c[k];
		int n;
		cin>>n;
		int a[k][n];
		for(int i=0;i<k;i++)
		for(int j=0;j<n;j++)
		cin>>a[i][j];
		
		int l=0;
		for(int i=0;i<k;i++)
		{
			int tk;
			tk=0;
			for(int j=0;j<n;j++)
			{
				coust[a[i][j]-1]++;
			}
			int minn=999999;
			for(int j=0;j<k;j++)
				if(minn>coust[j]&&coust[i]!=0)
				{
					minn=coust[j];
					tk=i+1;
				}
			c[l++]=minn;
			cout<<minn<<endl;
		}
	}
	cout<<endl;
	//fclose(stdin);
	//fclose(stdout);
	return 0;
}
