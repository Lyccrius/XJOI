#include<bits/stdc++.h>
using namespace std;
int k1,k2,n,k,i,t;
long long di[100000]={2,1,2,3,2,2,3,4,5,2,2,6,4,2,2,7,2,2,2,2,5,8,9},s[100000]={2,3,4,8,9,16,25,27,32,36,49,64,81,100,121,128,144,169,196,225,243,256,512};
int main()
{
	freopen("power.in","r",stdin);
	freopen("power.out","w",stdout);
	
	k1=10;
	k2=7;
	
	di[15]=6;
	s[16]=729;
	
	for(int i=16;i<=100000;i++)
	{
		if(i%2==1)
		{
			s[i]=pow(2,k1);
			di[i]=k1;
		}
		else
		{
			s[i]=pow(3,k2);
			di[i]=k2;
		}
		k1++;
		k2++;
	}
	
	cin>>n>>k;
	
	if(k==1)
	{
		cout<<n;
		return 0;
	}
	
	t=1;
	
	for(int i=1;i<=100000;i++)
	{
		if(di[i]<k)
		{
			t++;
			continue;
		}
		
		if(n<s[i])
		{
			
			cout<<i-t+1;
			return 0;
			
		}
	}
	
	cout<<endl;
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
