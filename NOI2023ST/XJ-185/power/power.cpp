#include<bits/stdc++.h>
using namespace std;
int k;
int n,m,ans,T,num;
int main()
{
	freopen("power.in","r",stdin);
	freopen("power.out","w",stdout);
	scanf("%d%d",&n,&k);
	if(k==1){
	printf("%d",n);
	return 0;
	}
	for(int i=1;i<=n;i++)
	for(int b=1;b<=log(i);i++)
	{
		for(int j=k;j<=k+10;j++){
		num=0;
		for(int l=1;l<=j;l++)
		num=num*b;
		if(num==i)
		{
			ans++;
			break;
		}
	}
	}
	printf("%d",ans);
    return 0;
}
