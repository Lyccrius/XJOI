#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("power.in","r",stdin);
	freopen("power.out","w",stdout);
	int n,K,num;
	int sum=0;
	cin>>n>>K;
	for(int i=1;i<n;i++)
	{
		for(int j=K;j<100;j++)
		{
			num=pow(i,j);
			if(num==true)
			{
				if(num<n)
			{
				sum=sum+1;
				num=false;
			}
			else
			{
				break;
			}
			}
		}
	}
	cout<<sum;
	return 0;
	fclose(stdin);
	fclose(stdout);
}
