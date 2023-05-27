#include<bits/stdc++.h>
using namespace std;
int a[20]={1,4,8,9,16,25,27,32,36,49,64,81,100};
long long n;
int m,sum=0;
int main()
{
	freopen("power.in","r",stdin);
	freopen("power.out","w",stdout);
	cin>>n>>m;
	if(m==1) cout<<n;
	if(m==2){
		for(int i=0;i<=12;i++){
			if(n>=a[i]) sum++;
		}
		cout<<sum;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
