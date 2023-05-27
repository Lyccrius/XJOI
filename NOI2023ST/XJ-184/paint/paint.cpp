#include<bits/stdc++.h>
using namespace std;
int main()
{
    	freopen("paint.in","r",stdin);
    	freopen("paint.out","w",stdout);
	int a[101][101]={0};
	int n,m,q;
	int sum,c,x;
	int t;
	cin >> t;
	for(int u=0;u<t;u++)
	{
		cin >> n >> m >> q;
		for(int i=0;i<q;i++)
		{
			cin >> sum >> c >> x;
			for(int j=0;j<n;j++)
			{
				for(int k=0;k<m;k++)
				{
					if(sum==0)
					{
						a[j][c]=x
					}
					if(sum===1)
					{
						a[c][k]=x;
					}
				}
			}
		}
		for(int i=0;i<n;i++)
		{	
			for(int j=0;i<m;j++)
			{
				cout << a[i][j] << " " 
			}
		}
	}
	freclose(stdin);
	freclose(stdout);
	return 0;	
}
