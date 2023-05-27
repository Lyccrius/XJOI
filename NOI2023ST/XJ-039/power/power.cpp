#include<bits/stdc++.h>
using namespace std;
long long a;
bool a1[99999999]={0};
int k;
int ans;
int main(){
	freopen("power.in","r",stdin);
	freopen("power.out","w",stdout);
	cin>>a>>k;
	if(k==1){
		cout<<a;
		return 0;
	}
	else{
		for(int i=1;i<=sqrt(a);i++)
		{
			for(int j=k;j<=a;j++)
			{
				int n=1,flag=0;
				for(int m=1;m<=j;m++)
				{
					n=n*i;
					if(n>a&&m<k){
						flag=1;
						break;
					}		
				}	
				if(flag)
				break;
				if(n>a)
				break;
				if(n<=a&&a1[n]==0)
				{
					ans++;
					a1[n]=1;
				}
				
			}	
				
		}
		cout<<ans;
		return 0;
	}
	
}

