#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("power.in","r",stdin);
    freopen("power.out","w",stdout);
    long long n;
    int k,s=0,flag[105]={0};
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
		for(int j=n;j>=1;j--)
		{
			for(int b=k;b<=100;b++)
			{
				if(flag[i]==0&&i==pow(j,b))
				{
					flag[i]=1;
					s++;
				}
			}
		}
    }
    cout<<s;
    return 0;
}
