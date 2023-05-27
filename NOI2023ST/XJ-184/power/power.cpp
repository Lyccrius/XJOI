#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("power.in","r",stdin);
    	freopen("power.out","w",stdout);
	int n,k;
	int a[101];
	int sum=0;
	for(int i=0;i<n;i++)
	{
		for(double j=k;j<=100;j++)
		{
			if(pow(i,j)<=n)
			{
				sum++;
			}
		}
	}
	cout << sum;
	freclose(stdin);
	freclose(stdout);
	return 0;
}
