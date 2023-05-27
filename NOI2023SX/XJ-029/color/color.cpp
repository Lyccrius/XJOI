#include <bits/stdc++.h>
using namespace std;
int n,m,t,ans1,ans2;
struct number{
	int val=0;
	//1=R 2=G
	int col=0;
}a[55];
int score(){
	int re=0;
	for (int i=1;i<n;i++){
		for (int j=i+1;j<=n;j++){
			if (a[j].col==1 && a[j].val<a[i].val){
				re+=(m-a[j].val+1);
			}else if (a[j].col==2 && a[j].val>a[i].val){
				re+=a[j].val;
			}
		}
	}
	return re;
}
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	int C;
	cin>>C;
	while (C--){
		cin>>n>>m>>t;
		for (int i=1;i<=t;i++){
			cin>>a[i].val;
		}
		if (t==n){
			ans1=1;
		}
		
		ans2=max(ans2,score());
		ans1%=998244353;
		ans2%=998244353;
		cout<<ans1<<" "<<ans2;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
