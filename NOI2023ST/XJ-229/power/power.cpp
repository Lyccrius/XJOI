#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("power.in","r",stdin);
	freopen("power.out","w",stdout);
	long long int n,cnt=1,k;
	cin>>n>>k;
	if(k==1){
		cout<<n;
		return 0;
	}
	for(int i=2;i<=n;i++){//i是我们要求的数字
		for(int u=2;u*u<=i;u++){//u是底数
			int flag=1;
			for(int j=k;;j++){//j是指数
				int x=pow(u,j);
				if(x==i){
					cnt++;
					flag=0;
					break;
				}
				if(x>i) break;
			}
			if(flag==0) break;
		}
	}
	cout<<cnt;
	fclose(stdin);
	fclose(stdout);
    return 0;
}
