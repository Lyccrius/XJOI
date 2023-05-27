#include <bits/stdc++.h>
using namespace std;
int k,a[10][50005],ans=INT_MAX;
long long n;
int c(int x){
	int tmax,tmin;
	for (int i=1;i<n;i++){
		tmax=max(a[x][i],a[x][i+1]);
		tmin=min(a[x][i],a[x][i+1]);
	}
	int re=tmax-tmin;
	return re;
}

int C(){
	int re=-1;
	for (int i=1;i<k;i++){
		re=max(re,max(c(i),c(i+1)));
	}
	return re;
}

void change(int y){
	if (y>n){
		return;
	}
	change(y+1);
	int ta[10005];
	int temp=C();
	if (ans>temp){
		ans=temp;
	}
	for (int p=1;p<=k;p++){
		for (int i=1;i<=k;i++){
			ta[i%k+1]=a[i][y];
		}
		for (int i=1;i<=k;i++){
			a[i][y]=ta[i];
		}
		int temp=C();
		if (ans>temp){
			ans=temp;
		}
	}
}

int main(){
	freopen("lock.in","r",stdin);
	freopen("lock.out","w",stdout);
	int T;
	cin>>T>>k;
	while (T--){
		cin>>n;
		for (int i=1;i<=k;i++){
			for (int j=1;j<=n;j++){
				cin>>a[i][j];
			}
		}
		change(1);
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
