#include <bits/stdc++.h>
using namespace std;
int n,p[1005],ans[1005],k;
double x[1005],y[1005],maxn,minn=INT_MAX;

long double len(){
	long double re=0;
	for (int i=1;i<n;i++){
		re+=sqrt((x[p[i]]-x[p[i+1]])*(x[p[i]]-x[p[i+1]])+(y[p[i]]-y[p[i+1]])*(y[p[i]]-y[p[i+1]]));
	}
	return re;
}

int main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>x[i]>>y[i];
		p[i]=i;
		if (maxn<y[i]){
			maxn=y[i];
			k=i;
		}
	}
	swap(p[1],p[k]);
	sort(p+2,p+n+1);
	long double temp=len();
	if (minn>temp){
		minn=temp;
		for (int i=1;i<=n;i++){
			ans[i]=p[i];
		}
	}
	while (next_permutation(p+2,p+n+1)){
		long double temp=len();
		if (minn>temp){
			minn=temp;
			for (int i=1;i<=n;i++){
				ans[i]=p[i];
			}
		}
	}
	for (int i=1;i<=n;i++){
		cout<<ans[i]<<" ";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
